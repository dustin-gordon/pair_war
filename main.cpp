/* CS 4328 Operating Systems
 * Programming Assignment 1
 *
 * Dustin Gordon & Jose Mayorga
 */

#include <iostream>
#include <queue>
#include <ctime>
#include <pthread.h>
using namespace std;

// init functions:
void shuffle();
void deal(int [], int);
void dealFirstRound();
void printDeck(queue <int>);

// init data structures:
string cards[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen","King"};
int player1[2];        // each player holds 2 cards (saved as int to index string array)
int player2[2];
int player3[2];
queue <int> dealer;    // dealer holds deck
int rounds = 0;
int seed;
bool gameOver = false;


int main()
{
    dealFirstRound();
    while(!gameOver)
    {
        rounds++;
        cout << "\n    Round " << rounds << endl;
        shuffle();
        deal(player1, 1);
        deal(player2, 2);
        deal(player3, 3);
    }
    cout << "\nGame finished in " << rounds << " rounds." << endl;

	return 0;
}


void shuffle()
{
    seed = time(NULL);
    srand(seed);
    for(int i = 0; i < 52; i++)
    {
        int random = rand() % 13;   // random index for cards string array
        dealer.push(random);        // add card to deck
        //cout << "debug: adding "<< cards[random] <<" to the deck..." << endl;
    }
    cout << "DECK: cards shuffled" << endl;
}


void deal(int p[], int pNum) // params: ptr to player array, player's number
{
    // deal 2nd card:
    cout << "PLAYER " << pNum << ": hand " << cards[0] << endl;
    int newCard = dealer.front();   // determine next card
    dealer.pop();                   // remove from deck
    cout << "PLAYER " << pNum << ": draws " << cards[newCard] << endl;
    p[1] = newCard;
    cout << "PLAYER " << pNum << ": hand " << cards[p[0]] << " " << cards[p[1]] << endl;

    if(p[0] == p[1])    // check if win
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
                dealer.push( p[0] ); // return card to deck
                p[0] = p[1];
                break;

            case 1: // return 2nd card
                cout << "PLAYER " << pNum << ": discards " << cards[ p[1] ] << endl;
                dealer.push( p[1] ); // return card to deck
                break;

            default:
                break;
        }
    }
    printDeck(dealer);
}


void dealFirstRound()
{
    rounds++;
    cout << "\n    Round " << rounds << endl;
    shuffle();

    // deal p1 first card:
    int newCard = dealer.front();   // determine next card
    dealer.pop();                   // remove from deck
    cout << "PLAYER 1: draws " << cards[newCard] << endl;
    player1[0] = newCard;
    printDeck(dealer);

    // deal p2 first card:
    newCard = dealer.front();
    dealer.pop();
    cout << "PLAYER 2: draws " << cards[newCard] << endl;
    player2[0] = newCard;
    printDeck(dealer);

    // deal p3 first card:
    newCard = dealer.front();
    dealer.pop();
    cout << "PLAYER 3: draws " << cards[newCard] << endl;
    player3[0] = newCard;
    printDeck(dealer);
}


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