/* CS 4328 Operating Systems
 * Programming Assignment 1
 *
 * Dustin Gordon & Jose Mayorga
 */

#include <iostream>
#include <queue>
#include <ctime>
#include <pthread.h>
#include <cstdlib>
#include <fstream>
using namespace std;

#define NUM_THREADS     4

// initialize functions:
void shuffle();
void deal(int [], int);
void dealFirstRound();
void printDeck(queue <int>);
void *parallel_Draws(void *threadid);
void p_deal_first(long);
void p_deal(long);
void p_check_win(long, int []);
void take_Turn(long, int []);

// initialize data structures:
string cards[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen","King"};
int player1[2];     // each player holds 2 cards (saved as int to index string array)
int player2[2];
int player3[2];
queue <int> dealer; // dealer holds deck
int rounds = 1;
int seed;           // for randomized shuffling
bool gameOver = false;
int turn = 1;

//Initializing mutex and barrier
pthread_mutex_t pLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
pthread_cond_t winCond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t dealerLock = PTHREAD_MUTEX_INITIALIZER;



// main fxn to loop game rounds until a player gets a pair and wins
int main()
{
    ofstream logs;
    logs.open("log.txt", ios::out);
    if ( logs.fail() )
    {
        cout << "Log file could not be opened!" << endl;
    }

    cout << "Enter a seed value: ";
    cin >> seed;
    logs << "Enter a seed value: " << seed << endl;

    //************ NT solution ************
    pthread_t threads[NUM_THREADS];


    while(rounds < 4)
    {
        while(!gameOver)
        {
            cout << "\n==== Starting Round " << rounds << " ====" << endl;
            logs << "\n==== Starting Round " << rounds << " ====" << endl;
            // run dealer thread
            pthread_create(&threads[0], NULL, parallel_Draws, (void*)((long)0));

            // run player threads in proper order
            
            if (rounds == 1)
            {
                pthread_create(&threads[1], NULL, parallel_Draws, (void*)((long)1));      
                pthread_create(&threads[2], NULL, parallel_Draws, (void*)((long)2));        
                pthread_create(&threads[3], NULL, parallel_Draws, (void*)((long)3));        
            }
            else if (rounds == 2)
            {         
                pthread_create(&threads[2], NULL, parallel_Draws, (void*)((long)2));        
                pthread_create(&threads[3], NULL, parallel_Draws, (void*)((long)3));
                pthread_create(&threads[1], NULL, parallel_Draws, (void*)((long)1));
            }
            else if (rounds == 3)
            {   
                pthread_create(&threads[3], NULL, parallel_Draws, (void*)((long)3));
                pthread_create(&threads[1], NULL, parallel_Draws, (void*)((long)1));
                pthread_create(&threads[2], NULL, parallel_Draws, (void*)((long)2)); 
             }

            for(int index = turn; index < NUM_THREADS; index++)
                 pthread_join(threads[index], NULL);

            
            turn++;
            if(turn > 3)
                turn = 1;
            
        }
        gameOver = false;
        rounds++;
        if (rounds == 2)
            turn = 2;
        if (rounds == 3)
            turn = 3;
    }
    cout << "\nGame finished in " << rounds - 1 << " rounds." << endl;
    logs.close();
    return 0;
    //*************************************
}

// generates queue of "cards" of random values 0-12, to be used as index to string array
void shuffle()
{
    while(!dealer.empty()) // empty existing deck
    {
        dealer.pop();
    }
    srand(seed);
    for(int i = 0; i < 52; i++)
    {
        int random = rand() % 13;   // random index for cards string array
        dealer.push(random);        // add card to deck
    }
    cout << "DECK: cards shuffled" << endl;
    
}


// iterates current contents of deck and prints output to console
void printDeck(queue <int> deck)
{
    cout << "DECK: (";
    while(!deck.empty())
    {
        cout << cards[ deck.front() ] << " ";
        deck.pop();
    }
    cout << ")" << endl;
    cout << endl;
}

// Executes the program in parallel by calling threads to perform functions.
void *parallel_Draws(void *threadid)
{
    long tid;
    tid = (long)threadid;

    if(tid == 0)
    {
        p_deal_first(tid);
        pthread_mutex_lock(&dealerLock);
        
        while(!gameOver)
        { 
            pthread_cond_wait(&winCond, &dealerLock); // wait for a win
        }
       
    pthread_mutex_unlock(&dealerLock); //unlock when winner determined
    pthread_cond_broadcast(&condition);
    }

    if (tid != 0)
        p_deal(tid);
    
    return NULL;
 }

// Deals the first round to the threads.
void p_deal_first(long tid)
{
   if (tid == 0)
   {
       shuffle();
       if (rounds == 1)
       {
           player1[0] = dealer.front();   // determine next card
           dealer.pop();                   // remove from deck
   
           player2[0] = dealer.front();   // determine next card
           dealer.pop();                   // remove from deck

           player3[0] = dealer.front();   // determine next card
           dealer.pop();                   // remove from deck
        }
       else if (rounds == 2)
       {   
           player2[0] = dealer.front();   // determine next card
           dealer.pop();                   // remove from deck

           player3[0] = dealer.front();   // determine next card
           dealer.pop();                   // remove from deck
           
           player1[0] = dealer.front();   // determine next card
           dealer.pop();                   // remove from deck

        }
        else if (rounds == 3)
       {   
           player3[0] = dealer.front();   // determine next card
           dealer.pop();                   // remove from deck
           
           player1[0] = dealer.front();   // determine next card
           dealer.pop();                   // remove from deck
           
           player2[0] = dealer.front();   // determine next card
           dealer.pop();                   // remove from deck
        }
   }
}

// Deals threads in order 1 - 3 and calls function to check for win.
void p_deal(long tid)
{
   int hand[2];

   if (tid == 1)
       hand[0] = player1[0];

   else if (tid == 2)
       hand[0] = player2[0];

   else if (tid == 3)
       hand[0] = player3[0];

    while(!gameOver)
    { 
        pthread_mutex_lock(&pLock); // lock
        
        while(!gameOver && !(tid == turn || turn == 0)) 
            pthread_cond_wait(&condition, &pLock); 

        if(!gameOver)
            take_Turn(tid, hand);
        
        pthread_mutex_unlock(&pLock); // unlock after turn complete
    }
    //cout << "PLAYER " << tid << ": exits round \n";
}

// Determines turn order
void take_Turn(long tid,int hand[])
{
    cout << "PLAYER " << tid << ": hand = " << cards[hand[0]] << endl;
    int newCard = dealer.front();   // determine next card
    dealer.pop();                   // remove from deck
    cout << "PLAYER " << tid << ": draws " << cards[newCard] << endl;
    hand[1] = newCard;                 // give player new card
    cout << "PLAYER " << tid << ": hand = " << cards[hand[0]] << ", " << cards[hand[1]] << endl;

    // check if match
    if (hand[0] == hand[1]) 
    {
        cout << "PLAYER " << tid << ": wins!!!" << endl;
        gameOver = true;
        pthread_cond_signal(&winCond);

    } 
    else 
    { //no match
        cout << "PLAYER " << tid << ": does not win..." << endl;
        int RNG = rand() % 2; // 0 or 1
        switch(RNG) // return random card
        {
            case 0:  // return 1st card
                cout << "PLAYER " << tid << ": discards " << cards[hand[0]] << endl;
                dealer.push( hand[0] );
                hand[0] = hand[1];
                break;

            case 1: // return 2nd card
                cout << "PLAYER " << tid << ": discards " << cards[hand[1]] << endl;
                dealer.push( hand[1] );
                break;

            default:
                break;
        }
        cout << "PLAYER " << tid << ": exits round" << endl;
    }
    printDeck(dealer);

    // signal next players turn
    turn++;

    if (turn > 3)
      turn = 1; 
    
    pthread_cond_broadcast(&condition);
}
