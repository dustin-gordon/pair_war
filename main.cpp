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

// initialize data structures:
string cards[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen","King"};
int player1[2];     // each player holds 2 cards (saved as int to index string array)
int player2[2];
int player3[2];
queue <int> dealer; // dealer holds deck
int rounds = 0;
int seed;           // for randomized shuffling
bool gameOver = false;

//Initializing mutex and barrier
pthread_mutex_t mutexDrawl;
pthread_barrier_t barrier;

// main fxn to loop game rounds until a player gets a pair and wins
int main()
{
    //************ 1T solution ************
    /*
    dealFirstRound(); //TODO: find pthread alternative
    while (!gameOver) {
        rounds++;
        cout << "\n    Round " << rounds << endl;
        shuffle();
        //pthread_create(&threads[0], NULL, &deal, 1);  // (last option) pointer to void that contains the arguments
        //pthread_create(&threads[1], NULL, &deal, 2);  // to the function defined in the earlier argument
        //pthread_create(&threads[2], NULL, &deal, 3);

        //Here we need synchronization as well as communication...most likely will be added in the deal function.

        deal(player1, 1);
        deal(player2, 2);
        deal(player3, 3);
        // TODO launch deal() calls as separate threads
    }
    cout << "\nGame finished in " << rounds << " rounds." << endl;
    return 0;
    */
    //*************************************


    //************ NT solution ************
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutexDrawl, NULL);
    pthread_barrier_init(&barrier, NULL, 4);
    while(!gameOver)
    {
        //cout << "Debug: creating " <<  NUM_THREADS << " threads..." << endl;
        for(int index = 0; index < NUM_THREADS; index++){
            cout << "In main: creating thread " << index << endl;
            int rc = pthread_create(&threads[index], NULL, parallel_Draws, (void*)((long)index));
            if (rc)
            {
                cout << "ERROR; return code from pthread_create() is " << rc << endl;
                return -1;
            }
            pthread_join(threads[index], NULL);
        }
		
        //pthread_join(threads[0], NULL);
        //pthread_join(threads[1], NULL);
        //pthread_join(threads[2], NULL);
        //pthread_join(threads[3], NULL);

        //pthread_barrier_wait (&barrier);

        cout << "Debug: setting gameOver = true (to be set on win)" << endl;
        gameOver = true; //debug
    }
    cout << "\nGame finished in " << rounds << " rounds." << endl;
    pthread_mutex_destroy(&mutexDrawl);
    pthread_exit(NULL);
    return 0;
    //*************************************
}

// Testing parallel portion
/*
pthread_mutex_init(&mutexDrawl, NULL);

pthread_barrier_init(&barrier, NULL, 3);

while(!gameOver)
{
    for(int index = 0; index < NUM_THREADS; index++){
       cout << "In main: creating thread " << index << endl;
       int rc = pthread_create(&threads[index], NULL, parallel_Draws, (void *)index);
       if (rc){
          cout << "ERROR; return code from pthread_create() is " << rc << endl;
          return -1;
       }
    }
}
pthread_mutex_destroy(&mutexDrawl);
pthread_exit(NULL);

return 0;
}
*/

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

// removes card from queue then adds to player's hand, declares pair or removes random card
// parameters: pointer to player array, player's number

//void* deal(void* threadId)
void deal(int p[], int pNum)
{
    // deal new card:
	
    //long pNum;
    //pNum = (long)threadid;    // This will determine which of the players is accessing this portion.
	
    cout << "PLAYER " << pNum << ": hand " << cards[0] << endl;
    int newCard = dealer.front();   // determine next card
    dealer.pop();                   // remove from deck
    cout << "PLAYER " << pNum << ": draws " << cards[newCard] << endl;
    p[1] = newCard;                 // give player new card
    cout << "PLAYER " << pNum << ": hand " << cards[p[0]] << ", " << cards[p[1]] << endl;

    // check if win:
    if(p[0] == p[1])
    {
        cout << "PLAYER " << pNum << ": wins" << endl;
        cout << "PLAYER " << pNum << ": exits round" << endl;
        gameOver = true;
        // TODO signal others threads to exit
    }
    else // return random card
    {
        int RNG = rand() % 2; // 0 or 1
        switch(RNG)
        {
            case 0:  // return 1st card
                cout << "PLAYER " << pNum << ": discards " << cards[ p[0] ] << endl;
                dealer.push( p[0] );
                p[0] = p[1];
                break;

            case 1: // return 2nd card
                cout << "PLAYER " << pNum << ": discards " << cards[ p[1] ] << endl;
                dealer.push( p[1] );
                break;

            default:
                break;
        }
    }

    printDeck(dealer); // display current deck
}

// For 1st round, dealer assigns card to 1st element in player array,
// subsequent rounds dealer assigns to 2nd element via deal()
void dealFirstRound()
{
    rounds++;
    cout << "\n    Round " << rounds << endl;
    shuffle();

    // deal player1's first card:
    int newCard = dealer.front();   // determine next card
    dealer.pop();                   // remove from deck
    cout << "PLAYER 1: draws " << cards[newCard] << endl;
    player1[0] = newCard;           // give player 1st card
    printDeck(dealer);              // display current deck

    // deal player2's first card:
    newCard = dealer.front();   // determine next card
    dealer.pop();               // remove from deck
    cout << "PLAYER 2: draws " << cards[newCard] << endl;
    player2[0] = newCard;       // give player 1st card
    printDeck(dealer);

    // deal player3's first card:
    newCard = dealer.front();   // determine next card
    dealer.pop();               // remove from deck
    cout << "PLAYER 3: draws " << cards[newCard] << endl;
    player3[0] = newCard;       // give player 1st card
    printDeck(dealer);          // display current deck
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
    //pthread_mutex_lock(&mutexDrawl);
    //pthread_barrier_wait (&barrier);
    //cout << "    Hello World! It's me, thread # " << tid << endl;
    p_deal_first(tid);
    //pthread_mutex_unlock(&mutexDrawl);
    //pthread_barrier_wait (&barrier);
    //pthread_mutex_lock(&mutexDrawl);
    p_deal(tid);
    //pthread_mutex_unlock(&mutexDrawl);
    gameOver = true;
    pthread_exit(NULL);
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
       cout << "PLAYER 1: draws " << cards[newCard] << endl;
       player1[0] = newCard;           // give player 1st card
       //printDeck(dealer);              // display current deck
   }
   else if (tid == 2)
   {
       int newCard = dealer.front();   // determine next card
       dealer.pop();                   // remove from deck
       cout << "PLAYER 2: draws " << cards[newCard] << endl;
       player2[0] = newCard;           // give player 2nd card
       //printDeck(dealer);              // display current deck
   }
   else if (tid == 3)
   {
       int newCard = dealer.front();   // determine next card
       dealer.pop();                   // remove from deck
       cout << "PLAYER 3: draws " << cards[newCard] << endl;
       player3[0] = newCard;           // give player 3rd card
       //printDeck(dealer);              // display current deck
   }
	
   //cout << "Thread in deal: " << tid << endl;
}

// Deals threads in order 1 - 3 and calls function to check for win.
void p_deal(long tid)
{
   if (tid == 0)
   {
       shuffle();
   }
   if (tid == 1)
   {
       cout << "PLAYER " << tid << ": hand " << cards[player1[0]] << endl;
       int newCard = dealer.front();   // determine next card
       dealer.pop();                   // remove from deck
       cout << "PLAYER " << tid << ": draws " << cards[newCard] << endl;
       player1[1] = newCard;                 // give player new card
       cout << "PLAYER " << tid << ": hand " << cards[player1[0]] << ", " << cards[player1[1]] << endl;
       p_check_win(tid, player1);
   }
   else if (tid == 2)
   {
       cout << "PLAYER " << tid << ": hand " << cards[player2[0]] << endl;
       int newCard = dealer.front();   // determine next card
       dealer.pop();                   // remove from deck
       cout << "PLAYER " << tid << ": draws " << cards[newCard] << endl;
       player2[1] = newCard;                 // give player new card
       cout << "PLAYER " << tid << ": hand " << cards[player2[0]] << ", " << cards[player2[1]] << endl;
       p_check_win(tid, player2);
   }
   else if (tid == 3)
   {
       cout << "PLAYER " << tid << ": hand " << cards[player3[0]] << endl;
       int newCard = dealer.front();   // determine next card
       dealer.pop();                   // remove from deck
       cout << "PLAYER " << tid << ": draws " << cards[newCard] << endl;
       player3[1] = newCard;                 // give player new card
       cout << "PLAYER " << tid << ": hand " << cards[player3[0]] << ", " << cards[player3[1]] << endl;
       p_check_win(tid, player3);
   }

    //printDeck(dealer); // display current deck

}


// Function called to if there is a match in cards (win)
void p_check_win(long tid, int player[])
{
    if(player[0] == player[1])
    {
        cout << "PLAYER " << tid << ": wins" << endl;
        cout << "PLAYER " << tid << ": exits round" << endl;
        gameOver = true;
        // TODO signal others threads to exit
    }
    else // return random card
    {
        int RNG = rand() % 2; // 0 or 1
        switch(RNG)
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
    }
}
