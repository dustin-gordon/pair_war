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
//int whoseTurn = 1;
bool gameOver = false;
bool roundOver = false;
int turn = 1;
pthread_t threads[NUM_THREADS];

//Initializing mutex and barrier
pthread_mutex_t pLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t dealerLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t turnCond = PTHREAD_COND_INITIALIZER;
pthread_cond_t winCond = PTHREAD_COND_INITIALIZER;


// main fxn to loop game rounds until a player gets a pair and wins
int main()
{

    //************ NT solution ************

    while(rounds < 4)
    {
        while(!gameOver)
        {
            cout << "Starting Round " << rounds << endl;
            roundOver = false;
            // run dealer thread
            cout << "* creating dealer thread 0" << endl;
            pthread_create(&threads[0], NULL, parallel_Draws, (void*)((long)0));

            // run player threads in proper order
            for(int index = 1; index < NUM_THREADS; index++)
            {
              //  cout << "In main: creating player thread " << index << endl;
                cout << "* creating thread " << index << endl;
                pthread_create(&threads[index], NULL, parallel_Draws, (void*)((long)index));

                turn++;
                if(gameOver)
                    break;

            }
            //cout << "back in main" << endl;
            for(int index = 1; index < NUM_THREADS; index++)
            {
                 cout << "* joining thread " << index << endl;
                 pthread_join(threads[index], NULL);
                 
            }

            roundOver = true;

            rounds++;
            turn++;
            if(turn > 3)
            {
                turn = 1;
            }
            //cout << gameOver << " test\n";
        }
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
    printDeck(dealer);
    
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
    cout << "* Running parallel_Draws() for thread " << tid << endl;
    //cout << "DEALER FUNCTION " << tid << endl;
    if(tid == 0) // if dealer thread 0
    {
        cout << "* enabling dealerLock in thread " << tid << endl;
        pthread_mutex_lock(&dealerLock);
        /*
        while(!gameOver)
        {
            cout << "stuck waiting dealer " << tid << endl;
            pthread_cond_wait(&winCond, &dealerLock); // wait for a win
        }
         */
        if(rounds == 1)
        {
            cout << "* dealing to player " << tid << endl;
            p_deal_first(tid);
        }
        cout << "* dealing to player " << tid << endl;
        p_deal(tid);

        cout << "* broadcasting condition in thread " << tid << endl;
        pthread_cond_broadcast(&turnCond);
        cout << "* disabling dealerLock in thread " << tid << endl;
        pthread_mutex_unlock(&dealerLock); //unlock when winner determined
    }
    else
    {
        cout << "Waiting for dealer thread to finish.." << endl;
        //pthread_cond_wait(&turnCond, &dealerLock);
        pthread_join(threads[0], NULL);
        cout << "* dealing to player " << tid << endl;
        p_deal(tid);
    }

    return NULL;

 }

// Deals the first round to the threads.
void p_deal_first(long tid)
{
   if (tid == 0)
   {
   
       shuffle();
   
       int newCard = dealer.front();   // determine next card
       dealer.pop();                   // remove from deck
       cout << "PLAYER 1: draws 1st card: " << cards[newCard] << endl;
       player1[0] = newCard;           // give player 1st card
   
       newCard = dealer.front();       // determine next card
       dealer.pop();                   // remove from deck
       cout << "PLAYER 2: draws 1st card: " << cards[newCard] << endl;
       player2[0] = newCard;           // give player 2nd card

       newCard = dealer.front();       // determine next card
       dealer.pop();                   // remove from deck
       cout << "PLAYER 3: draws 1st card: " << cards[newCard] << endl;
       player3[0] = newCard;           // give player 3rd card
   }

}

// Deals threads in order 1 - 3 and calls function to check for win.
void p_deal(long tid)
{
   if(gameOver)
   {
       cout << "PLAYER " << tid << ": exits round \n";
       pthread_exit(NULL);
   }

   int newCard;
   switch(tid) // shuffle or draw card
   {
       case 0:
           shuffle();
           break;
       case 1:
           cout << "Player " << tid << "'s turn" << endl;
           cout << "PLAYER " << tid << ": hand = " << cards[player1[0]] << endl;
           newCard = dealer.front();   // determine next card
           dealer.pop();               // remove from deck
           cout << "PLAYER " << tid << ": draws " << cards[newCard] << endl;
           player1[1] = newCard;       // give player new card
           cout << "PLAYER " << tid << ": hand = " << cards[player1[0]] << ", " << cards[player1[1]] << endl;
           break;
       case 2:
           cout << "Player " << tid << "'s turn" << endl;
           cout << "PLAYER " << tid << ": hand = " << cards[player2[0]] << endl;
           newCard = dealer.front();   // determine next card
           dealer.pop();               // remove from deck
           cout << "PLAYER " << tid << ": draws " << cards[newCard] << endl;
           player2[1] = newCard;       // give player new card
           cout << "PLAYER " << tid << ": hand = " << cards[player2[0]] << ", " << cards[player2[1]] << endl;
           break;
       case 3:
           cout << "Player " << tid << "'s turn" << endl;
           cout << "PLAYER " << tid << ": hand = " << cards[player3[0]] << endl;
           newCard = dealer.front();   // determine next card
           dealer.pop();               // remove from deck
           cout << "PLAYER " << tid << ": draws " << cards[newCard] << endl;
           player3[1] = newCard;       // give player new card
           cout << "PLAYER " << tid << ": hand = " << cards[player3[0]] << ", " << cards[player3[1]] << endl;
           break;
       default: break;
   }

   if(tid != 0)
   {
       cout << "* enabling pLock in thread " << tid << endl;
       pthread_mutex_lock(&pLock); // lock

       switch (tid) {
           case 1:
               take_Turn(tid, player1);
               break;
           case 2:
               take_Turn(tid, player2);
               break;
           case 3:
               take_Turn(tid, player3);
               break;
           default:
               break;
       }

       /*
       while (!gameOver && !(tid == turn || turn == 0)) {
           cout << "* thread " << tid << " waiting on condition and pLock" << endl;
           pthread_cond_wait(&turnCond, &pLock);

       }
        */
       cout << "* thread " << tid << " waiting on condition and pLock" << endl;
       pthread_cond_wait(&turnCond, &pLock);

       cout << "* broadcasting turnCond in thread " << tid << endl;
       pthread_cond_broadcast(&turnCond);
       cout << "* disabling pLock in thread " << tid << endl;
       pthread_mutex_unlock(&pLock); // unlock after turn complete


       cout << "PLAYER " << tid << ": exits round \n";
   }
    
}

// Determines turn order, sets winCond
void take_Turn(long tid,int hand[])
{

    /*
    cout << "PLAYER " << tid << ": hand = " << cards[hand[0]] << endl;
    int newCard = dealer.front();   // determine next card
    dealer.pop();                   // remove from deck
    cout << "PLAYER " << tid << ": draws " << cards[newCard] << endl;
    hand[1] = newCard;                 // give player new card
    cout << "PLAYER " << tid << ": hand = " << cards[hand[0]] << ", " << cards[hand[1]] << endl;
    */

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

            default: break;
        }

    }
    turn++;
    if (turn > NUM_THREADS)
    {
      turn = 1; 
    }
    pthread_mutex_unlock(&pLock);
    pthread_cond_broadcast(&turnCond);
    
}
