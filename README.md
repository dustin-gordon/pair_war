# pair_war

	CS 4328 Operating Systems
	Programming Assignment 1

	Dustin Gordon - dmg210
	Jose Mayorga  - jmm498

# Summary:

"Pair War" is a simple card game that implements POSIX threads. In our implementation, the "dealer" and 3 "players" are represented as 4 separate threads. The dealer thread controls a data structure representing the deck of cards. The player threads control data structures representing the player's hand. The threads are created in main and player threads are called in turn order. The player who goes first at the beginning of the round is determined in a round robin fashion, with player 1 going 1st. A random seed is generated at runtime based off of user input for use in randomizing the order of the deck. This performed at the beginning of every round when the dealer calls the shuffle method. During each player's turn, the respective thread will check if drawn card is a match. If so, the round is over and all other threads will exit. If a match is not drawn, a randomly selected card is discarded from the player's hand and their turn ends. The game is designed to continue each round until a player wins. The game lasts for 3 rounds total. During runtime, a log file named "log.txt" is generated to document the program's execution. The log file is overwritten after each run. Please note that there is an edge case where on the small chance that player 1 draws a match on the very first turn than an exception may occur. The issue can only replicate on one of our laptops and does not occur on the Zeus server. If this does happen then recompile and run again.


# To compile and run:

Please copy "main.cpp" to a Linux environment, then enter the following command to compile:

	g++ -pthread main.cpp -o pw

To run, enter the following command:

	./pw

# Result 1:

	Enter a seed value: 1

	==== Starting Round 1 ====
	PLAYER 1:
	HAND Ace
	WIN no
	PLAYER 2:
	HAND Ten
	WIN no
	PLAYER 3:
	HAND Queen Ace
	WIN yes
	DECK: (Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Five Ten Queen King Two )


	==== Starting Round 2 ====
	PLAYER 1:
	HAND Queen Ace
	WIN yes
	PLAYER 2:
	HAND Ace
	WIN no
	PLAYER 3:
	HAND Ten
	WIN no
	DECK: (Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Five Ten Queen King Two )


	==== Starting Round 3 ====
	PLAYER 1:
	HAND Ten
	WIN no
	PLAYER 2:
	HAND Queen
	WIN no
	PLAYER 3:
	HAND Ace Ace
	WIN yes
	DECK: (Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Five Queen Eight King Two )


	Game finished in 3 rounds.

# Result 2: 

	Enter a seed value: 3

	==== Starting Round 1 ====
	PLAYER 1:
	HAND Nine Ace
	WIN yes
	PLAYER 2:
	HAND Ten
	WIN no
	PLAYER 3:
	HAND Four
	WIN no
	DECK: (Seven Queen Six Jack Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six )


	==== Starting Round 2 ====
	PLAYER 1:
	HAND Ten
	WIN no
	PLAYER 2:
	HAND Seven Ace
	WIN yes
	PLAYER 3:
	HAND Nine
	WIN no
	DECK: (Queen Six Jack Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Four Four )


	==== Starting Round 3 ====
	PLAYER 1:
	HAND Nine
	WIN no
	PLAYER 2:
	HAND Ten Ace
	WIN yes
	PLAYER 3:
	HAND Seven
	WIN no
	DECK: (Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen Six Six Ten Ten )


	Game finished in 3 rounds.

# Result 3: 

	Enter a seed value: 5

	==== Starting Round 1 ====
	PLAYER 1:
	HAND Seven Ace
	WIN yes
	PLAYER 2:
	HAND Queen
	WIN no
	PLAYER 3:
	HAND Ten
	WIN no
	DECK: (Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Seven Six Ten Jack Three Eight )


	==== Starting Round 2 ====
	PLAYER 1:
	HAND Ten
	WIN no
	PLAYER 2:
	HAND Seven
	WIN no
	PLAYER 3:
	HAND Queen Ace
	WIN yes
	DECK: (Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ten Six Queen Jack Three Eight )


	==== Starting Round 3 ====
	PLAYER 1:
	HAND Queen Ace
	WIN yes
	PLAYER 2:
	HAND Ten
	WIN no
	PLAYER 3:
	HAND Seven
	WIN no
	DECK: (Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ten Six Queen Jack Three Eight )


	Game finished in 3 rounds.

# Result 4: 

	Enter a seed value: 7

	==== Starting Round 1 ====
	PLAYER 1:
	HAND King
	WIN no
	PLAYER 2:
	HAND Seven
	WIN no
	PLAYER 3:
	HAND King Ace
	WIN yes
	DECK: (Two Six Seven Four Jack Ace Eight Two Eight Four Nine Ten Six Eight Ten Queen Eight Six Ten Two Ace Jack Six Two Ten King Jack Four Jack Three Ten Ace Eight Five Ace Ten Ten Six Eight King King King Ace Six Eight King Five Five )


	==== Starting Round 2 ====
	PLAYER 1:
	HAND Seven
	WIN no
	PLAYER 2:
	HAND King Ace
	WIN yes
	PLAYER 3:
	HAND King
	WIN no
	DECK: (Ten Ten Six Eight Ace Five King King Six Eight Five Queen Five Five Two Six Seven Four Jack Ace Eight Two Eight Four Nine Ten Six Eight Ten Queen Eight Six Ten Two Ace Jack Six Two Ten King Jack Four Jack Three Ten Ace Eight Five )


	==== Starting Round 3 ====
	PLAYER 1:
	HAND King Ace
	WIN yes
	PLAYER 2:
	HAND Seven
	WIN no
	PLAYER 3:
	HAND King
	WIN no
	DECK: (Ten Ten Six Eight Ace Five King King Six Eight Five Queen Five Five Two Six Seven Four Jack Ace Eight Two Eight Four Nine Ten Six Eight Ten Queen Eight Six Ten Two Ace Jack Six Two Ten King Jack Four Jack Three Ten Ace Eight Five )


	Game finished in 3 rounds.

# Result 5: 

	Enter a seed value: 10

	==== Starting Round 1 ====
	PLAYER 1:
	HAND Seven
	WIN no
	PLAYER 2:
	HAND Queen
	WIN no
	PLAYER 3:
	HAND Jack Ace
	WIN yes
	DECK: (Four Eight Eight Nine Jack Seven King King Two Two Jack Jack Three Ten Ten Five Four Six Queen Ten Two Queen Six Two Queen Seven Five Ace Ten Queen Two Queen King Three Eight Seven Eight Ace Queen Jack Six Queen Queen Eight Ten Ace Four Six )


	==== Starting Round 2 ====
	PLAYER 1:
	HAND Queen
	WIN no
	PLAYER 2:
	HAND Queen
	WIN no
	PLAYER 3:
	HAND Seven Ace
	WIN yes
	DECK: (Eight Six Ten Ace Eight Queen Queen King Three Two Four Six Two Four Eight Eight Nine Jack Seven King King Two Two Jack Jack Three Ten Ten Five Four Six Queen Ten Two Queen Six Two Queen Seven Five Ace Ten Queen Two Jack King Three Eight )


	==== Starting Round 3 ====
	PLAYER 1:
	HAND Seven Ace
	WIN yes
	PLAYER 2:
	HAND Queen
	WIN no
	PLAYER 3:
	HAND Queen
	WIN no
	DECK: (Eight Six Ten Ace Eight Queen Queen King Three Two Four Six Two Four Eight Eight Nine Jack Seven King King Two Two Jack Jack Three Ten Ten Five Four Six Queen Ten Two Queen Six Two Queen Seven Five Ace Ten Queen Two Jack King Three Eight )


	Game finished in 3 rounds.

# End of Report