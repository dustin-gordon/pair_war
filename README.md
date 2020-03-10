# pair_war

CS 4328 Operating Systems
Programming Assignment 1

Dustin Gordon - dmg210
Jose Mayorga  - 

"Pair War" is a simple card game that implements POSIX threads. In our implementation, the "dealer" and 3 "players" are represented as 4 separate threads. The dealer thread controls a data structure representing the deck of cards. The player threads control data structures representing the player's hand. The threads are created in main and player threads are called in turn order. 

To compile and run, copy "main.cpp" to a Linux environment, and enter the following commands:

g++ -pthread main.cpp -o pw
./pw