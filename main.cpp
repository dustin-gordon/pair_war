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
int whoseTurn = 1;
bool gameOver = false;
int turn = 0;

//Initializing mutex and barrier
pthread_mutex_t pLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
pthread_cond_t winCond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t dealerLock = PTHREAD_MUTEX_INITIALIZER;

// main fxn to loop game rounds until a player gets a pair and wins
int main()
{

    //************ NT solution ************
    pthread_t threads[NUM_THREADS];
   // pthread_mutex_init(&mutexDrawl, NULL);
    //pthread_barrier_init(&barrier, NULL, 4);


    while(!gameOver)
    {
        cout << "Starting Round " << rounds << endl;
        
        // run dealer thread
        cout << "In main: creating dealer thread 0" << endl;
        pthread_create(&threads[0], NULL, parallel_Draws, (void*)((long)0));

        // run player threads in proper order
        for(int index = whoseTurn; index < NUM_THREADS; index++)
        {
            cout << "In main: creating player thread " << index << endl;
            pthread_create(&threads[index], NULL, parallel_Draws, (void*)((long)index));
            
            if(gameOver)
                break;
        }
        //cout << "back in main" << endl;
        for(int index = whoseTurn; index < NUM_THREADS; index++)
        {
            pthread_join(threads[index], NULL);
        }

        rounds++;
        whoseTurn++;
        if(whoseTurn > 3)
        {
            whoseTurn = 1;
        }
        if (rounds > 3)
            break;
    }
    cout << "\nGame finished in " << rounds - 1 << " rounds." << endl;
    
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

    seed = time(NULL);
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
    //cout << "DEALER FUNCTION " << tid << endl;
    if(rounds == 0 && tid == 0)
    {
        p_deal_first(tid);

        while(!gameOver)
        { 
            //cout << "stuck waiting dealer " << tid << endl;
            pthread_cond_wait(&winCond, &dealerLock); // wait for a win
        }
    }
    
    if (tid == 0)
    {
    pthread_mutex_unlock(&dealerLock); //unlock when winner determined
    pthread_cond_broadcast(&condition);
    
    // exit when round is over
    cout << "DEALER: exits round \n";
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
   }
   if (tid == 1)
   {
       int newCard = dealer.front();   // determine next card
       dealer.pop();                   // remove from deck
       cout << "PLAYER 1: draws 1st card: " << cards[newCard] << endl;
       player1[0] = newCard;           // give player 1st card
       //printDeck(dealer);              // display current deck
   }
   else if (tid == 2)
   {
       int newCard = dealer.front();   // determine next card
       dealer.pop();                   // remove from deck
       cout << "PLAYER 2: draws 1st card: " << cards[newCard] << endl;
       player2[0] = newCard;           // give player 2nd card
       //printDeck(dealer);              // display current deck
   }
   else if (tid == 3)
   {
       int newCard = dealer.front();   // determine next card
       dealer.pop();                   // remove from deck
       cout << "PLAYER 3: draws 1st card: " << cards[newCard] << endl;
       player3[0] = newCard;           // give player 3rd card
       //printDeck(dealer);              // display current deck
   }
	
   //cout << "Thread in deal: " << tid << endl;
}

// Deals threads in order 1 - 3 and calls function to check for win.
void p_deal(long tid)
{
   int hand[2];
   //cout << "Inside deal!\n" << endl;
   if (tid == 1)
   {
       hand[0] = player1[0];
       //hand[1] = dealer.front();   // determine next card
       dealer.pop();                   // remove from deck
       
       //p_check_win(tid, player1);
   }
   else if (tid == 2)
   {
       hand[0] = player2[0];
       //hand[1] = dealer.front();   // determine next card
       dealer.pop();                   // remove from deck
       
   }
   else if (tid == 3)
   {
       hand[0] = player3[0];
       //hand[1] = dealer.front();   // determine next card
       dealer.pop();                   // remove from deck
       
   }
   
    while(!gameOver)
    { 
    
        pthread_mutex_lock(&pLock); // lock
        
        while(!gameOver && !(tid == turn || turn == 0))
        { 
        
            pthread_cond_wait(&condition, &pLock); 
            
        }
        if(!gameOver)
        { 
            take_Turn(tid, hand);
        }
        pthread_mutex_unlock(&pLock); // unlock after turn complete
    }

    
    cout << "PLAYER " << tid << ": exits round \n";
    pthread_exit(NULL);
}

/*
// Function called to if there is a match in cards (win)
void p_check_win(long tid, int player[])
{
    if(player[0] == player[1]) // if cards match
    {
        if(!gameOver) // ensure no other threads won
        {
            cout << "PLAYER " << tid << ": wins!!!" << endl;
            cout << "PLAYER " << tid << ": exits round" << endl;
            gameOver = true;
            // TODO signal others threads to exit
        }
    }
    else // return random card
    {
        cout << "PLAYER " << tid << ": does not win..." << endl;
        int RNG = rand() % 2; // 0 or 1
        switch(RNG) // return random card
        {
            case 0:  // return 1st card
                cout << "PLAYER " << tid << ": discards " << cards[ player[0] ] << endl;
                dealer.push( player[0] );
                player[0] = player[1];
                break;

            case 1: // return 2nd card
                cout << "PLAYER " << tid << ": discards " << cards[ player[1] ] << endl;
                dealer.push( player[1] );
                break;

            default:
                break;
        }
        cout << "PLAYER " << tid << ": exits round" << endl;
    }
}
*/

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
    
    // signal next players turn
    turn++;
    if (turn > NUM_THREADS)
    {
      turn = 1; 
    }
    pthread_cond_broadcast(&condition);
}
