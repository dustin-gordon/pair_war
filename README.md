# pair_war

	CS 4328 Operating Systems
	Programming Assignment 1

	Dustin Gordon - dmg210
	Jose Mayorga  - jmm498

# Summary:

"Pair War" is a simple card game that implements POSIX threads. In our implementation, the "dealer" and 3 "players" are represented as 4 separate threads. The dealer thread controls a data structure representing the deck of cards. The player threads control data structures representing the player's hand. The threads are created in main and player threads are called in turn order. The player who goes first at the beginning of the round is determined in a round robin fashion, with player 1 going 1st. A random seed is generated at runtime based off of user input for use in randomizing the order of the deck. This performed at the beginning of every round when the dealer calls the shuffle method. During each player's turn, the respective thread will check if drawn card is a match. If so, the round is over and all other threads will exit. If a match is not drawn, a randomly selected card is discarded from the player's hand and their turn ends. The game is designed to continue each round until a player wins. The game lasts for 3 rounds total. During runtime, a log file named "log.txt" is generated to document the program's execution. The log file is overwritten after each run. Please note that there is an edge case where on the small chance that player 1 draws a match on the very first turn than an exception may occur. If this happens then run again using a different seed value.


# To compile and run:

Please copy "main.cpp" to a Linux environment, then enter the following command to compile:

	g++ -pthread main.cpp -o pw

To run, enter the following command:

	./pw

# Result 1:

	Enter a seed value: 1

	==== Starting Round 1 ====
	DECK: cards shuffled
	PLAYER 1: hand = Ace
	PLAYER 1: draws Five
	PLAYER 1: hand = Ace, Five
	PLAYER 1: does not win...
	PLAYER 1: discards Five
	PLAYER 1: exits round
	DECK: (Two Two King Four Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Five )

	PLAYER 2: hand = Ten
	PLAYER 2: draws Two
	PLAYER 2: hand = Ten, Two
	PLAYER 2: does not win...
	PLAYER 2: discards Ten
	PLAYER 2: exits round
	DECK: (Two King Four Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Five Ten )

	PLAYER 3: hand = Queen
	PLAYER 3: draws Two
	PLAYER 3: hand = Queen, Two
	PLAYER 3: does not win...
	PLAYER 3: discards Queen
	PLAYER 3: exits round
	DECK: (King Four Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Five Ten Queen )

	PLAYER 1: hand = Ace
	PLAYER 1: draws King
	PLAYER 1: hand = Ace, King
	PLAYER 1: does not win...
	PLAYER 1: discards King
	PLAYER 1: exits round
	DECK: (Four Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Five Ten Queen King )

	PLAYER 2: hand = Two
	PLAYER 2: draws Four
	PLAYER 2: hand = Two, Four
	PLAYER 2: does not win...
	PLAYER 2: discards Two
	PLAYER 2: exits round
	DECK: (Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Five Ten Queen King Two )

	PLAYER 3: hand = Two
	PLAYER 3: draws Two
	PLAYER 3: hand = Two, Two
	PLAYER 3: wins!!!
	DECK: (Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Five Ten Queen King Two )


	==== Starting Round 2 ====
	DECK: cards shuffled
	PLAYER 2: hand = Ten
	PLAYER 2: draws Five
	PLAYER 2: hand = Ten, Five
	PLAYER 2: does not win...
	PLAYER 2: discards Five
	PLAYER 2: exits round
	DECK: (Two Two King Four Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Five )

	PLAYER 3: hand = Ten
	PLAYER 3: draws Two
	PLAYER 3: hand = Ten, Two
	PLAYER 3: does not win...
	PLAYER 3: discards Ten
	PLAYER 3: exits round
	DECK: (Two King Four Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Five Ten )

	PLAYER 1: hand = Queen
	PLAYER 1: draws Two
	PLAYER 1: hand = Queen, Two
	PLAYER 1: does not win...
	PLAYER 1: discards Queen
	PLAYER 1: exits round
	DECK: (King Four Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Five Ten Queen )

	PLAYER 2: hand = Ten
	PLAYER 2: draws King
	PLAYER 2: hand = Ten, King
	PLAYER 2: does not win...
	PLAYER 2: discards King
	PLAYER 2: exits round
	DECK: (Four Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Five Ten Queen King )

	PLAYER 3: hand = Two
	PLAYER 3: draws Four
	PLAYER 3: hand = Two, Four
	PLAYER 3: does not win...
	PLAYER 3: discards Two
	PLAYER 3: exits round
	DECK: (Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Five Ten Queen King Two )

	PLAYER 1: hand = Two
	PLAYER 1: draws Two
	PLAYER 1: hand = Two, Two
	PLAYER 1: wins!!!
	DECK: (Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Five Ten Queen King Two )


	==== Starting Round 3 ====
	PLAYER 3: hand = Ten
	PLAYER 3: draws Eight
	PLAYER 3: hand = Ten, Eight
	PLAYER 3: does not win...
	PLAYER 3: discards Ten
	PLAYER 3: exits round
	DECK: (Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Five Ten Queen King Two Ten )

	PLAYER 1: hand = Queen
	PLAYER 1: draws Ace
	PLAYER 1: hand = Queen, Ace
	PLAYER 1: does not win...
	PLAYER 1: discards Ace
	PLAYER 1: exits round
	DECK: (Ten Queen Five Two Two King Four Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Ace )

	PLAYER 2: hand = Ace
	PLAYER 2: draws Ten
	PLAYER 2: hand = Ace, Ten
	PLAYER 2: does not win...
	PLAYER 2: discards Ace
	PLAYER 2: exits round
	DECK: (Queen Five Two Two King Four Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Ace Ace )

	PLAYER 3: hand = Eight
	PLAYER 3: draws Queen
	PLAYER 3: hand = Eight, Queen
	PLAYER 3: does not win...
	PLAYER 3: discards Eight
	PLAYER 3: exits round
	DECK: (Five Two Two King Four Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Ace Ace Eight )

	PLAYER 1: hand = Queen
	PLAYER 1: draws Five
	PLAYER 1: hand = Queen, Five
	PLAYER 1: does not win...
	PLAYER 1: discards Five
	PLAYER 1: exits round
	DECK: (Two Two King Four Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Ace Ace Eight Five )

	PLAYER 2: hand = Ten
	PLAYER 2: draws Two
	PLAYER 2: hand = Ten, Two
	PLAYER 2: does not win...
	PLAYER 2: discards Ten
	PLAYER 2: exits round
	DECK: (Two King Four Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Ace Ace Eight Five Ten )

	PLAYER 3: hand = Queen
	PLAYER 3: draws Two
	PLAYER 3: hand = Queen, Two
	PLAYER 3: does not win...
	PLAYER 3: discards Queen
	PLAYER 3: exits round
	DECK: (King Four Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Ace Ace Eight Five Ten Queen )

	PLAYER 1: hand = Queen
	PLAYER 1: draws King
	PLAYER 1: hand = Queen, King
	PLAYER 1: does not win...
	PLAYER 1: discards Queen
	PLAYER 1: exits round
	DECK: (Four Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Ace Ace Eight Five Ten Queen Queen )

	PLAYER 2: hand = Two
	PLAYER 2: draws Four
	PLAYER 2: hand = Two, Four
	PLAYER 2: does not win...
	PLAYER 2: discards Four
	PLAYER 2: exits round
	DECK: (Two Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Ace Ace Eight Five Ten Queen Queen Four )

	PLAYER 3: hand = Two
	PLAYER 3: draws Two
	PLAYER 3: hand = Two, Two
	PLAYER 3: wins!!!
	DECK: (Eight Three Four Ace Five King Two Ten Jack Jack Queen Eight Nine Four Four Four Six Three Four Jack Five Ten King Two Ten Six Five Jack Six Ten Queen Two Queen Four Two Five Six Six Ace Five Three Two Queen Ace Ace Eight Five Ten Queen Queen Four )


	Game finished in 3 rounds.

# Result 2: 

	Enter a seed value: 2

	==== Starting Round 1 ====
	DECK: cards shuffled
	PLAYER 1: hand = Five
	PLAYER 1: draws Ace
	PLAYER 1: hand = Five, Ace
	PLAYER 1: does not win...
	PLAYER 1: discards Ace
	PLAYER 1: exits round
	DECK: (Eight Ace King Four Eight Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace )

	PLAYER 2: hand = Two
	PLAYER 2: draws Eight
	PLAYER 2: hand = Two, Eight
	PLAYER 2: does not win...
	PLAYER 2: discards Two
	PLAYER 2: exits round
	DECK: (Ace King Four Eight Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Two )

	PLAYER 3: hand = Seven
	PLAYER 3: draws Ace
	PLAYER 3: hand = Seven, Ace
	PLAYER 3: does not win...
	PLAYER 3: discards Seven
	PLAYER 3: exits round
	DECK: (King Four Eight Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Two Seven )

	PLAYER 1: hand = Five
	PLAYER 1: draws King
	PLAYER 1: hand = Five, King
	PLAYER 1: does not win...
	PLAYER 1: discards Five
	PLAYER 1: exits round
	DECK: (Four Eight Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Two Seven Five )

	PLAYER 2: hand = Eight
	PLAYER 2: draws Four
	PLAYER 2: hand = Eight, Four
	PLAYER 2: does not win...
	PLAYER 2: discards Four
	PLAYER 2: exits round
	DECK: (Eight Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Two Seven Five Four )

	PLAYER 3: hand = Ace
	PLAYER 3: draws Eight
	PLAYER 3: hand = Ace, Eight
	PLAYER 3: does not win...
	PLAYER 3: discards Eight
	PLAYER 3: exits round
	DECK: (Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Two Seven Five Four Eight )

	PLAYER 1: hand = King
	PLAYER 1: draws Ace
	PLAYER 1: hand = King, Ace
	PLAYER 1: does not win...
	PLAYER 1: discards King
	PLAYER 1: exits round
	DECK: (Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Two Seven Five Four Eight King )

	PLAYER 2: hand = Eight
	PLAYER 2: draws Eight
	PLAYER 2: hand = Eight, Eight
	PLAYER 2: wins!!!
	DECK: (Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Two Seven Five Four Eight King )


	==== Starting Round 2 ====
	DECK: cards shuffled
	PLAYER 2: hand = Five
	PLAYER 2: draws Ace
	PLAYER 2: hand = Five, Ace
	PLAYER 2: does not win...
	PLAYER 2: discards Ace
	PLAYER 2: exits round
	DECK: (Eight Ace King Four Eight Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace )

	PLAYER 3: hand = Two
	PLAYER 3: draws Eight
	PLAYER 3: hand = Two, Eight
	PLAYER 3: does not win...
	PLAYER 3: discards Two
	PLAYER 3: exits round
	DECK: (Ace King Four Eight Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Two )

	PLAYER 1: hand = Seven
	PLAYER 1: draws Ace
	PLAYER 1: hand = Seven, Ace
	PLAYER 1: does not win...
	PLAYER 1: discards Seven
	PLAYER 1: exits round
	DECK: (King Four Eight Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Two Seven )

	PLAYER 2: hand = Five
	PLAYER 2: draws King
	PLAYER 2: hand = Five, King
	PLAYER 2: does not win...
	PLAYER 2: discards Five
	PLAYER 2: exits round
	DECK: (Four Eight Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Two Seven Five )

	PLAYER 3: hand = Eight
	PLAYER 3: draws Four
	PLAYER 3: hand = Eight, Four
	PLAYER 3: does not win...
	PLAYER 3: discards Four
	PLAYER 3: exits round
	DECK: (Eight Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Two Seven Five Four )

	PLAYER 1: hand = Ace
	PLAYER 1: draws Eight
	PLAYER 1: hand = Ace, Eight
	PLAYER 1: does not win...
	PLAYER 1: discards Eight
	PLAYER 1: exits round
	DECK: (Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Two Seven Five Four Eight )

	PLAYER 2: hand = King
	PLAYER 2: draws Ace
	PLAYER 2: hand = King, Ace
	PLAYER 2: does not win...
	PLAYER 2: discards King
	PLAYER 2: exits round
	DECK: (Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Two Seven Five Four Eight King )

	PLAYER 3: hand = Eight
	PLAYER 3: draws Eight
	PLAYER 3: hand = Eight, Eight
	PLAYER 3: wins!!!
	DECK: (Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Two Seven Five Four Eight King )


	==== Starting Round 3 ====
	DECK: cards shuffled
	PLAYER 3: hand = Five
	PLAYER 3: draws Ace
	PLAYER 3: hand = Five, Ace
	PLAYER 3: does not win...
	PLAYER 3: discards Ace
	PLAYER 3: exits round
	DECK: (Eight Ace King Four Eight Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace )

	PLAYER 1: hand = Ace
	PLAYER 1: draws Eight
	PLAYER 1: hand = Ace, Eight
	PLAYER 1: does not win...
	PLAYER 1: discards Ace
	PLAYER 1: exits round
	DECK: (Ace King Four Eight Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Ace )

	PLAYER 2: hand = Seven
	PLAYER 2: draws Ace
	PLAYER 2: hand = Seven, Ace
	PLAYER 2: does not win...
	PLAYER 2: discards Seven
	PLAYER 2: exits round
	DECK: (King Four Eight Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Ace Seven )

	PLAYER 3: hand = Five
	PLAYER 3: draws King
	PLAYER 3: hand = Five, King
	PLAYER 3: does not win...
	PLAYER 3: discards Five
	PLAYER 3: exits round
	DECK: (Four Eight Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Ace Seven Five )

	PLAYER 1: hand = Two
	PLAYER 1: draws Four
	PLAYER 1: hand = Two, Four
	PLAYER 1: does not win...
	PLAYER 1: discards Four
	PLAYER 1: exits round
	DECK: (Eight Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Ace Seven Five Four )

	PLAYER 2: hand = Ace
	PLAYER 2: draws Eight
	PLAYER 2: hand = Ace, Eight
	PLAYER 2: does not win...
	PLAYER 2: discards Eight
	PLAYER 2: exits round
	DECK: (Ace Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Ace Seven Five Four Eight )

	PLAYER 3: hand = King
	PLAYER 3: draws Ace
	PLAYER 3: hand = King, Ace
	PLAYER 3: does not win...
	PLAYER 3: discards King
	PLAYER 3: exits round
	DECK: (Eight Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Ace Seven Five Four Eight King )

	PLAYER 1: hand = Eight
	PLAYER 1: draws Eight
	PLAYER 1: hand = Eight, Eight
	PLAYER 1: wins!!!
	DECK: (Jack Two Nine King Queen Eight Six Three Jack Jack Six Ace Two Nine Four Six Six Six Ten Four Ten Jack Jack Ten Eight King Jack Jack Seven Ace Seven Six Two Two Five Ace Nine Queen Five Six Queen Ace Ace Seven Five Four Eight King )


	Game finished in 3 rounds.

# Result 3: 

	Enter a seed value: 3

	==== Starting Round 1 ====
	DECK: cards shuffled
	PLAYER 1: hand = Seven
	PLAYER 1: draws Four
	PLAYER 1: hand = Seven, Four
	PLAYER 1: does not win...
	PLAYER 1: discards Seven
	PLAYER 1: exits round
	DECK: (Seven Queen Six Jack Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven )

	PLAYER 2: hand = Nine
	PLAYER 2: draws Seven
	PLAYER 2: hand = Nine, Seven
	PLAYER 2: does not win...
	PLAYER 2: discards Seven
	PLAYER 2: exits round
	DECK: (Queen Six Jack Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven )

	PLAYER 3: hand = Ten
	PLAYER 3: draws Queen
	PLAYER 3: hand = Ten, Queen
	PLAYER 3: does not win...
	PLAYER 3: discards Ten
	PLAYER 3: exits round
	DECK: (Six Jack Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten )

	PLAYER 1: hand = Four
	PLAYER 1: draws Six
	PLAYER 1: hand = Four, Six
	PLAYER 1: does not win...
	PLAYER 1: discards Six
	PLAYER 1: exits round
	DECK: (Jack Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six )

	PLAYER 2: hand = Nine
	PLAYER 2: draws Jack
	PLAYER 2: hand = Nine, Jack
	PLAYER 2: does not win...
	PLAYER 2: discards Nine
	PLAYER 2: exits round
	DECK: (Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine )

	PLAYER 3: hand = Queen
	PLAYER 3: draws Five
	PLAYER 3: hand = Queen, Five
	PLAYER 3: does not win...
	PLAYER 3: discards Five
	PLAYER 3: exits round
	DECK: (Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five )

	PLAYER 1: hand = Four
	PLAYER 1: draws Seven
	PLAYER 1: hand = Four, Seven
	PLAYER 1: does not win...
	PLAYER 1: discards Four
	PLAYER 1: exits round
	DECK: (Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four )

	PLAYER 2: hand = Jack
	PLAYER 2: draws Six
	PLAYER 2: hand = Jack, Six
	PLAYER 2: does not win...
	PLAYER 2: discards Jack
	PLAYER 2: exits round
	DECK: (Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack )

	PLAYER 3: hand = Queen
	PLAYER 3: draws Five
	PLAYER 3: hand = Queen, Five
	PLAYER 3: does not win...
	PLAYER 3: discards Five
	PLAYER 3: exits round
	DECK: (Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five )

	PLAYER 1: hand = Seven
	PLAYER 1: draws Four
	PLAYER 1: hand = Seven, Four
	PLAYER 1: does not win...
	PLAYER 1: discards Four
	PLAYER 1: exits round
	DECK: (Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four )

	PLAYER 2: hand = Six
	PLAYER 2: draws Queen
	PLAYER 2: hand = Six, Queen
	PLAYER 2: does not win...
	PLAYER 2: discards Queen
	PLAYER 2: exits round
	DECK: (Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen )

	PLAYER 3: hand = Queen
	PLAYER 3: draws Ten
	PLAYER 3: hand = Queen, Ten
	PLAYER 3: does not win...
	PLAYER 3: discards Ten
	PLAYER 3: exits round
	DECK: (Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten )

	PLAYER 1: hand = Seven
	PLAYER 1: draws Three
	PLAYER 1: hand = Seven, Three
	PLAYER 1: does not win...
	PLAYER 1: discards Three
	PLAYER 1: exits round
	DECK: (King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three )

	PLAYER 2: hand = Six
	PLAYER 2: draws King
	PLAYER 2: hand = Six, King
	PLAYER 2: does not win...
	PLAYER 2: discards King
	PLAYER 2: exits round
	DECK: (Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King )

	PLAYER 3: hand = Queen
	PLAYER 3: draws Nine
	PLAYER 3: hand = Queen, Nine
	PLAYER 3: does not win...
	PLAYER 3: discards Nine
	PLAYER 3: exits round
	DECK: (Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine )

	PLAYER 1: hand = Seven
	PLAYER 1: draws Six
	PLAYER 1: hand = Seven, Six
	PLAYER 1: does not win...
	PLAYER 1: discards Seven
	PLAYER 1: exits round
	DECK: (Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven )

	PLAYER 2: hand = Six
	PLAYER 2: draws Jack
	PLAYER 2: hand = Six, Jack
	PLAYER 2: does not win...
	PLAYER 2: discards Six
	PLAYER 2: exits round
	DECK: (Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six )

	PLAYER 3: hand = Queen
	PLAYER 3: draws Five
	PLAYER 3: hand = Queen, Five
	PLAYER 3: does not win...
	PLAYER 3: discards Five
	PLAYER 3: exits round
	DECK: (Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five )

	PLAYER 1: hand = Six
	PLAYER 1: draws Ace
	PLAYER 1: hand = Six, Ace
	PLAYER 1: does not win...
	PLAYER 1: discards Six
	PLAYER 1: exits round
	DECK: (Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six )

	PLAYER 2: hand = Jack
	PLAYER 2: draws Five
	PLAYER 2: hand = Jack, Five
	PLAYER 2: does not win...
	PLAYER 2: discards Jack
	PLAYER 2: exits round
	DECK: (Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack )

	PLAYER 3: hand = Queen
	PLAYER 3: draws Ace
	PLAYER 3: hand = Queen, Ace
	PLAYER 3: does not win...
	PLAYER 3: discards Ace
	PLAYER 3: exits round
	DECK: (Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace )

	PLAYER 1: hand = Ace
	PLAYER 1: draws Seven
	PLAYER 1: hand = Ace, Seven
	PLAYER 1: does not win...
	PLAYER 1: discards Seven
	PLAYER 1: exits round
	DECK: (Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven )

	PLAYER 2: hand = Five
	PLAYER 2: draws Ten
	PLAYER 2: hand = Five, Ten
	PLAYER 2: does not win...
	PLAYER 2: discards Five
	PLAYER 2: exits round
	DECK: (Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five )

	PLAYER 3: hand = Queen
	PLAYER 3: draws Five
	PLAYER 3: hand = Queen, Five
	PLAYER 3: does not win...
	PLAYER 3: discards Five
	PLAYER 3: exits round
	DECK: (Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five )

	PLAYER 1: hand = Ace
	PLAYER 1: draws Ten
	PLAYER 1: hand = Ace, Ten
	PLAYER 1: does not win...
	PLAYER 1: discards Ace
	PLAYER 1: exits round
	DECK: (Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace )

	PLAYER 2: hand = Ten
	PLAYER 2: draws Eight
	PLAYER 2: hand = Ten, Eight
	PLAYER 2: does not win...
	PLAYER 2: discards Eight
	PLAYER 2: exits round
	DECK: (Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight )

	PLAYER 3: hand = Queen
	PLAYER 3: draws Eight
	PLAYER 3: hand = Queen, Eight
	PLAYER 3: does not win...
	PLAYER 3: discards Eight
	PLAYER 3: exits round
	DECK: (Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight )

	PLAYER 1: hand = Ten
	PLAYER 1: draws Queen
	PLAYER 1: hand = Ten, Queen
	PLAYER 1: does not win...
	PLAYER 1: discards Ten
	PLAYER 1: exits round
	DECK: (Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten )

	PLAYER 2: hand = Ten
	PLAYER 2: draws Ace
	PLAYER 2: hand = Ten, Ace
	PLAYER 2: does not win...
	PLAYER 2: discards Ace
	PLAYER 2: exits round
	DECK: (Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace )

	PLAYER 3: hand = Queen
	PLAYER 3: draws Six
	PLAYER 3: hand = Queen, Six
	PLAYER 3: does not win...
	PLAYER 3: discards Queen
	PLAYER 3: exits round
	DECK: (Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen )

	PLAYER 1: hand = Queen
	PLAYER 1: draws Ten
	PLAYER 1: hand = Queen, Ten
	PLAYER 1: does not win...
	PLAYER 1: discards Queen
	PLAYER 1: exits round
	DECK: (Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen )

	PLAYER 2: hand = Ten
	PLAYER 2: draws Six
	PLAYER 2: hand = Ten, Six
	PLAYER 2: does not win...
	PLAYER 2: discards Six
	PLAYER 2: exits round
	DECK: (Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen Six )

	PLAYER 3: hand = Six
	PLAYER 3: draws Queen
	PLAYER 3: hand = Six, Queen
	PLAYER 3: does not win...
	PLAYER 3: discards Six
	PLAYER 3: exits round
	DECK: (Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen Six Six )

	PLAYER 1: hand = Ten
	PLAYER 1: draws Nine
	PLAYER 1: hand = Ten, Nine
	PLAYER 1: does not win...
	PLAYER 1: discards Ten
	PLAYER 1: exits round
	DECK: (Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen Six Six Ten )

	PLAYER 2: hand = Ten
	PLAYER 2: draws Jack
	PLAYER 2: hand = Ten, Jack
	PLAYER 2: does not win...
	PLAYER 2: discards Ten
	PLAYER 2: exits round
	DECK: (Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen Six Six Ten Ten )

	PLAYER 3: hand = Queen
	PLAYER 3: draws Queen
	PLAYER 3: hand = Queen, Queen
	PLAYER 3: wins!!!
	DECK: (Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen Six Six Ten Ten )


	==== Starting Round 2 ====
	DECK: cards shuffled
	PLAYER 2: hand = Seven
	PLAYER 2: draws Four
	PLAYER 2: hand = Seven, Four
	PLAYER 2: does not win...
	PLAYER 2: discards Seven
	PLAYER 2: exits round
	DECK: (Seven Queen Six Jack Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven )

	PLAYER 3: hand = Nine
	PLAYER 3: draws Seven
	PLAYER 3: hand = Nine, Seven
	PLAYER 3: does not win...
	PLAYER 3: discards Seven
	PLAYER 3: exits round
	DECK: (Queen Six Jack Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven )

	PLAYER 1: hand = Ten
	PLAYER 1: draws Queen
	PLAYER 1: hand = Ten, Queen
	PLAYER 1: does not win...
	PLAYER 1: discards Ten
	PLAYER 1: exits round
	DECK: (Six Jack Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten )

	PLAYER 2: hand = Four
	PLAYER 2: draws Six
	PLAYER 2: hand = Four, Six
	PLAYER 2: does not win...
	PLAYER 2: discards Six
	PLAYER 2: exits round
	DECK: (Jack Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six )

	PLAYER 3: hand = Nine
	PLAYER 3: draws Jack
	PLAYER 3: hand = Nine, Jack
	PLAYER 3: does not win...
	PLAYER 3: discards Nine
	PLAYER 3: exits round
	DECK: (Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine )

	PLAYER 1: hand = Queen
	PLAYER 1: draws Five
	PLAYER 1: hand = Queen, Five
	PLAYER 1: does not win...
	PLAYER 1: discards Five
	PLAYER 1: exits round
	DECK: (Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five )

	PLAYER 2: hand = Four
	PLAYER 2: draws Seven
	PLAYER 2: hand = Four, Seven
	PLAYER 2: does not win...
	PLAYER 2: discards Four
	PLAYER 2: exits round
	DECK: (Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four )

	PLAYER 3: hand = Jack
	PLAYER 3: draws Six
	PLAYER 3: hand = Jack, Six
	PLAYER 3: does not win...
	PLAYER 3: discards Jack
	PLAYER 3: exits round
	DECK: (Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack )

	PLAYER 1: hand = Queen
	PLAYER 1: draws Five
	PLAYER 1: hand = Queen, Five
	PLAYER 1: does not win...
	PLAYER 1: discards Five
	PLAYER 1: exits round
	DECK: (Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five )

	PLAYER 2: hand = Seven
	PLAYER 2: draws Four
	PLAYER 2: hand = Seven, Four
	PLAYER 2: does not win...
	PLAYER 2: discards Four
	PLAYER 2: exits round
	DECK: (Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four )

	PLAYER 3: hand = Six
	PLAYER 3: draws Queen
	PLAYER 3: hand = Six, Queen
	PLAYER 3: does not win...
	PLAYER 3: discards Queen
	PLAYER 3: exits round
	DECK: (Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen )

	PLAYER 1: hand = Queen
	PLAYER 1: draws Ten
	PLAYER 1: hand = Queen, Ten
	PLAYER 1: does not win...
	PLAYER 1: discards Ten
	PLAYER 1: exits round
	DECK: (Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten )

	PLAYER 2: hand = Seven
	PLAYER 2: draws Three
	PLAYER 2: hand = Seven, Three
	PLAYER 2: does not win...
	PLAYER 2: discards Three
	PLAYER 2: exits round
	DECK: (King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three )

	PLAYER 3: hand = Six
	PLAYER 3: draws King
	PLAYER 3: hand = Six, King
	PLAYER 3: does not win...
	PLAYER 3: discards King
	PLAYER 3: exits round
	DECK: (Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King )

	PLAYER 1: hand = Queen
	PLAYER 1: draws Nine
	PLAYER 1: hand = Queen, Nine
	PLAYER 1: does not win...
	PLAYER 1: discards Nine
	PLAYER 1: exits round
	DECK: (Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine )

	PLAYER 2: hand = Seven
	PLAYER 2: draws Six
	PLAYER 2: hand = Seven, Six
	PLAYER 2: does not win...
	PLAYER 2: discards Seven
	PLAYER 2: exits round
	DECK: (Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven )

	PLAYER 3: hand = Six
	PLAYER 3: draws Jack
	PLAYER 3: hand = Six, Jack
	PLAYER 3: does not win...
	PLAYER 3: discards Six
	PLAYER 3: exits round
	DECK: (Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six )

	PLAYER 1: hand = Queen
	PLAYER 1: draws Five
	PLAYER 1: hand = Queen, Five
	PLAYER 1: does not win...
	PLAYER 1: discards Five
	PLAYER 1: exits round
	DECK: (Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five )

	PLAYER 2: hand = Six
	PLAYER 2: draws Ace
	PLAYER 2: hand = Six, Ace
	PLAYER 2: does not win...
	PLAYER 2: discards Six
	PLAYER 2: exits round
	DECK: (Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six )

	PLAYER 3: hand = Jack
	PLAYER 3: draws Five
	PLAYER 3: hand = Jack, Five
	PLAYER 3: does not win...
	PLAYER 3: discards Jack
	PLAYER 3: exits round
	DECK: (Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack )

	PLAYER 1: hand = Queen
	PLAYER 1: draws Ace
	PLAYER 1: hand = Queen, Ace
	PLAYER 1: does not win...
	PLAYER 1: discards Ace
	PLAYER 1: exits round
	DECK: (Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace )

	PLAYER 2: hand = Ace
	PLAYER 2: draws Seven
	PLAYER 2: hand = Ace, Seven
	PLAYER 2: does not win...
	PLAYER 2: discards Seven
	PLAYER 2: exits round
	DECK: (Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven )

	PLAYER 3: hand = Five
	PLAYER 3: draws Ten
	PLAYER 3: hand = Five, Ten
	PLAYER 3: does not win...
	PLAYER 3: discards Five
	PLAYER 3: exits round
	DECK: (Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five )

	PLAYER 1: hand = Queen
	PLAYER 1: draws Five
	PLAYER 1: hand = Queen, Five
	PLAYER 1: does not win...
	PLAYER 1: discards Five
	PLAYER 1: exits round
	DECK: (Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five )

	PLAYER 2: hand = Ace
	PLAYER 2: draws Ten
	PLAYER 2: hand = Ace, Ten
	PLAYER 2: does not win...
	PLAYER 2: discards Ace
	PLAYER 2: exits round
	DECK: (Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace )

	PLAYER 3: hand = Ten
	PLAYER 3: draws Eight
	PLAYER 3: hand = Ten, Eight
	PLAYER 3: does not win...
	PLAYER 3: discards Eight
	PLAYER 3: exits round
	DECK: (Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight )

	PLAYER 1: hand = Queen
	PLAYER 1: draws Eight
	PLAYER 1: hand = Queen, Eight
	PLAYER 1: does not win...
	PLAYER 1: discards Eight
	PLAYER 1: exits round
	DECK: (Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight )

	PLAYER 2: hand = Ten
	PLAYER 2: draws Queen
	PLAYER 2: hand = Ten, Queen
	PLAYER 2: does not win...
	PLAYER 2: discards Ten
	PLAYER 2: exits round
	DECK: (Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten )

	PLAYER 3: hand = Ten
	PLAYER 3: draws Ace
	PLAYER 3: hand = Ten, Ace
	PLAYER 3: does not win...
	PLAYER 3: discards Ace
	PLAYER 3: exits round
	DECK: (Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace )

	PLAYER 1: hand = Queen
	PLAYER 1: draws Six
	PLAYER 1: hand = Queen, Six
	PLAYER 1: does not win...
	PLAYER 1: discards Queen
	PLAYER 1: exits round
	DECK: (Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen )

	PLAYER 2: hand = Queen
	PLAYER 2: draws Ten
	PLAYER 2: hand = Queen, Ten
	PLAYER 2: does not win...
	PLAYER 2: discards Queen
	PLAYER 2: exits round
	DECK: (Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen )

	PLAYER 3: hand = Ten
	PLAYER 3: draws Six
	PLAYER 3: hand = Ten, Six
	PLAYER 3: does not win...
	PLAYER 3: discards Six
	PLAYER 3: exits round
	DECK: (Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen Six )

	PLAYER 1: hand = Six
	PLAYER 1: draws Queen
	PLAYER 1: hand = Six, Queen
	PLAYER 1: does not win...
	PLAYER 1: discards Six
	PLAYER 1: exits round
	DECK: (Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen Six Six )

	PLAYER 2: hand = Ten
	PLAYER 2: draws Nine
	PLAYER 2: hand = Ten, Nine
	PLAYER 2: does not win...
	PLAYER 2: discards Ten
	PLAYER 2: exits round
	DECK: (Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen Six Six Ten )

	PLAYER 3: hand = Ten
	PLAYER 3: draws Jack
	PLAYER 3: hand = Ten, Jack
	PLAYER 3: does not win...
	PLAYER 3: discards Ten
	PLAYER 3: exits round
	DECK: (Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen Six Six Ten Ten )

	PLAYER 1: hand = Queen
	PLAYER 1: draws Queen
	PLAYER 1: hand = Queen, Queen
	PLAYER 1: wins!!!
	DECK: (Two Six Four Six Nine Three Five Ace Two King Six Ace Six Seven Seven Ten Six Nine Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen Six Six Ten Ten )


	==== Starting Round 3 ====
	DECK: cards shuffled
	PLAYER 3: hand = Nine
	PLAYER 3: draws Four
	PLAYER 3: hand = Nine, Four
	PLAYER 3: does not win...
	PLAYER 3: discards Nine
	PLAYER 3: exits round
	DECK: (Seven Queen Six Jack Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine )

	PLAYER 1: hand = Ten
	PLAYER 1: draws Seven
	PLAYER 1: hand = Ten, Seven
	PLAYER 1: does not win...
	PLAYER 1: discards Seven
	PLAYER 1: exits round
	DECK: (Queen Six Jack Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven )

	PLAYER 2: hand = Seven
	PLAYER 2: draws Queen
	PLAYER 2: hand = Seven, Queen
	PLAYER 2: does not win...
	PLAYER 2: discards Seven
	PLAYER 2: exits round
	DECK: (Six Jack Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven )

	PLAYER 3: hand = Four
	PLAYER 3: draws Six
	PLAYER 3: hand = Four, Six
	PLAYER 3: does not win...
	PLAYER 3: discards Six
	PLAYER 3: exits round
	DECK: (Jack Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six )

	PLAYER 1: hand = Ten
	PLAYER 1: draws Jack
	PLAYER 1: hand = Ten, Jack
	PLAYER 1: does not win...
	PLAYER 1: discards Ten
	PLAYER 1: exits round
	DECK: (Five Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten )

	PLAYER 2: hand = Queen
	PLAYER 2: draws Five
	PLAYER 2: hand = Queen, Five
	PLAYER 2: does not win...
	PLAYER 2: discards Five
	PLAYER 2: exits round
	DECK: (Seven Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five )

	PLAYER 3: hand = Four
	PLAYER 3: draws Seven
	PLAYER 3: hand = Four, Seven
	PLAYER 3: does not win...
	PLAYER 3: discards Four
	PLAYER 3: exits round
	DECK: (Six Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four )

	PLAYER 1: hand = Jack
	PLAYER 1: draws Six
	PLAYER 1: hand = Jack, Six
	PLAYER 1: does not win...
	PLAYER 1: discards Jack
	PLAYER 1: exits round
	DECK: (Five Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack )

	PLAYER 2: hand = Queen
	PLAYER 2: draws Five
	PLAYER 2: hand = Queen, Five
	PLAYER 2: does not win...
	PLAYER 2: discards Five
	PLAYER 2: exits round
	DECK: (Four Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five )

	PLAYER 3: hand = Seven
	PLAYER 3: draws Four
	PLAYER 3: hand = Seven, Four
	PLAYER 3: does not win...
	PLAYER 3: discards Four
	PLAYER 3: exits round
	DECK: (Queen Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four )

	PLAYER 1: hand = Six
	PLAYER 1: draws Queen
	PLAYER 1: hand = Six, Queen
	PLAYER 1: does not win...
	PLAYER 1: discards Queen
	PLAYER 1: exits round
	DECK: (Ten Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen )

	PLAYER 2: hand = Queen
	PLAYER 2: draws Ten
	PLAYER 2: hand = Queen, Ten
	PLAYER 2: does not win...
	PLAYER 2: discards Ten
	PLAYER 2: exits round
	DECK: (Three King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten )

	PLAYER 3: hand = Seven
	PLAYER 3: draws Three
	PLAYER 3: hand = Seven, Three
	PLAYER 3: does not win...
	PLAYER 3: discards Three
	PLAYER 3: exits round
	DECK: (King Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three )

	PLAYER 1: hand = Six
	PLAYER 1: draws King
	PLAYER 1: hand = Six, King
	PLAYER 1: does not win...
	PLAYER 1: discards King
	PLAYER 1: exits round
	DECK: (Nine Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King )

	PLAYER 2: hand = Queen
	PLAYER 2: draws Nine
	PLAYER 2: hand = Queen, Nine
	PLAYER 2: does not win...
	PLAYER 2: discards Nine
	PLAYER 2: exits round
	DECK: (Six Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine )

	PLAYER 3: hand = Seven
	PLAYER 3: draws Six
	PLAYER 3: hand = Seven, Six
	PLAYER 3: does not win...
	PLAYER 3: discards Seven
	PLAYER 3: exits round
	DECK: (Jack Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven )

	PLAYER 1: hand = Six
	PLAYER 1: draws Jack
	PLAYER 1: hand = Six, Jack
	PLAYER 1: does not win...
	PLAYER 1: discards Six
	PLAYER 1: exits round
	DECK: (Five Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six )

	PLAYER 2: hand = Queen
	PLAYER 2: draws Five
	PLAYER 2: hand = Queen, Five
	PLAYER 2: does not win...
	PLAYER 2: discards Five
	PLAYER 2: exits round
	DECK: (Ace Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five )

	PLAYER 3: hand = Six
	PLAYER 3: draws Ace
	PLAYER 3: hand = Six, Ace
	PLAYER 3: does not win...
	PLAYER 3: discards Six
	PLAYER 3: exits round
	DECK: (Five Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six )

	PLAYER 1: hand = Jack
	PLAYER 1: draws Five
	PLAYER 1: hand = Jack, Five
	PLAYER 1: does not win...
	PLAYER 1: discards Jack
	PLAYER 1: exits round
	DECK: (Ace Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack )

	PLAYER 2: hand = Queen
	PLAYER 2: draws Ace
	PLAYER 2: hand = Queen, Ace
	PLAYER 2: does not win...
	PLAYER 2: discards Ace
	PLAYER 2: exits round
	DECK: (Seven Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace )

	PLAYER 3: hand = Ace
	PLAYER 3: draws Seven
	PLAYER 3: hand = Ace, Seven
	PLAYER 3: does not win...
	PLAYER 3: discards Seven
	PLAYER 3: exits round
	DECK: (Ten Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven )

	PLAYER 1: hand = Five
	PLAYER 1: draws Ten
	PLAYER 1: hand = Five, Ten
	PLAYER 1: does not win...
	PLAYER 1: discards Five
	PLAYER 1: exits round
	DECK: (Five Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five )

	PLAYER 2: hand = Queen
	PLAYER 2: draws Five
	PLAYER 2: hand = Queen, Five
	PLAYER 2: does not win...
	PLAYER 2: discards Five
	PLAYER 2: exits round
	DECK: (Ten Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five )

	PLAYER 3: hand = Ace
	PLAYER 3: draws Ten
	PLAYER 3: hand = Ace, Ten
	PLAYER 3: does not win...
	PLAYER 3: discards Ace
	PLAYER 3: exits round
	DECK: (Eight Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace )

	PLAYER 1: hand = Ten
	PLAYER 1: draws Eight
	PLAYER 1: hand = Ten, Eight
	PLAYER 1: does not win...
	PLAYER 1: discards Eight
	PLAYER 1: exits round
	DECK: (Eight Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight )

	PLAYER 2: hand = Queen
	PLAYER 2: draws Eight
	PLAYER 2: hand = Queen, Eight
	PLAYER 2: does not win...
	PLAYER 2: discards Eight
	PLAYER 2: exits round
	DECK: (Queen Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight )

	PLAYER 3: hand = Ten
	PLAYER 3: draws Queen
	PLAYER 3: hand = Ten, Queen
	PLAYER 3: does not win...
	PLAYER 3: discards Ten
	PLAYER 3: exits round
	DECK: (Ace Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten )

	PLAYER 1: hand = Ten
	PLAYER 1: draws Ace
	PLAYER 1: hand = Ten, Ace
	PLAYER 1: does not win...
	PLAYER 1: discards Ace
	PLAYER 1: exits round
	DECK: (Six Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace )

	PLAYER 2: hand = Queen
	PLAYER 2: draws Six
	PLAYER 2: hand = Queen, Six
	PLAYER 2: does not win...
	PLAYER 2: discards Queen
	PLAYER 2: exits round
	DECK: (Ten Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen )

	PLAYER 3: hand = Queen
	PLAYER 3: draws Ten
	PLAYER 3: hand = Queen, Ten
	PLAYER 3: does not win...
	PLAYER 3: discards Queen
	PLAYER 3: exits round
	DECK: (Six Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen )

	PLAYER 1: hand = Ten
	PLAYER 1: draws Six
	PLAYER 1: hand = Ten, Six
	PLAYER 1: does not win...
	PLAYER 1: discards Six
	PLAYER 1: exits round
	DECK: (Queen Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen Six )

	PLAYER 2: hand = Six
	PLAYER 2: draws Queen
	PLAYER 2: hand = Six, Queen
	PLAYER 2: does not win...
	PLAYER 2: discards Six
	PLAYER 2: exits round
	DECK: (Nine Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen Six Six )

	PLAYER 3: hand = Ten
	PLAYER 3: draws Nine
	PLAYER 3: hand = Ten, Nine
	PLAYER 3: does not win...
	PLAYER 3: discards Ten
	PLAYER 3: exits round
	DECK: (Jack Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen Six Six Ten )

	PLAYER 1: hand = Ten
	PLAYER 1: draws Jack
	PLAYER 1: hand = Ten, Jack
	PLAYER 1: does not win...
	PLAYER 1: discards Ten
	PLAYER 1: exits round
	DECK: (Queen Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen Six Six Ten Ten )

	PLAYER 2: hand = Queen
	PLAYER 2: draws Queen
	PLAYER 2: hand = Queen, Queen
	PLAYER 2: wins!!!
	DECK: (Two Six Four Six Nine Three Five Ace Two King Six Ace Six Nine Seven Seven Six Ten Five Four Jack Five Four Queen Ten Three King Nine Seven Six Five Six Jack Ace Seven Five Five Ace Eight Eight Ten Ace Queen Queen Six Six Ten Ten )


	Game finished in 3 rounds.

# Result 4:

	Enter a seed value: 4

	==== Starting Round 1 ====
	DECK: cards shuffled
	PLAYER 1: hand = Eight
	PLAYER 1: draws Two
	PLAYER 1: hand = Eight, Two
	PLAYER 1: does not win...
	PLAYER 1: discards Two
	PLAYER 1: exits round
	DECK: (Nine King Four Two Ten Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two )

	PLAYER 2: hand = Jack
	PLAYER 2: draws Nine
	PLAYER 2: hand = Jack, Nine
	PLAYER 2: does not win...
	PLAYER 2: discards Nine
	PLAYER 2: exits round
	DECK: (King Four Two Ten Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine )

	PLAYER 3: hand = Jack
	PLAYER 3: draws King
	PLAYER 3: hand = Jack, King
	PLAYER 3: does not win...
	PLAYER 3: discards King
	PLAYER 3: exits round
	DECK: (Four Two Ten Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King )

	PLAYER 1: hand = Eight
	PLAYER 1: draws Four
	PLAYER 1: hand = Eight, Four
	PLAYER 1: does not win...
	PLAYER 1: discards Eight
	PLAYER 1: exits round
	DECK: (Two Ten Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King Eight )

	PLAYER 2: hand = Jack
	PLAYER 2: draws Two
	PLAYER 2: hand = Jack, Two
	PLAYER 2: does not win...
	PLAYER 2: discards Jack
	PLAYER 2: exits round
	DECK: (Ten Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King Eight Jack )

	PLAYER 3: hand = Jack
	PLAYER 3: draws Ten
	PLAYER 3: hand = Jack, Ten
	PLAYER 3: does not win...
	PLAYER 3: discards Ten
	PLAYER 3: exits round
	DECK: (Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King Eight Jack Ten )

	PLAYER 1: hand = Four
	PLAYER 1: draws Ten
	PLAYER 1: hand = Four, Ten
	PLAYER 1: does not win...
	PLAYER 1: discards Four
	PLAYER 1: exits round
	DECK: (Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King Eight Jack Ten Four )

	PLAYER 2: hand = Two
	PLAYER 2: draws Two
	PLAYER 2: hand = Two, Two
	PLAYER 2: wins!!!
	DECK: (Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King Eight Jack Ten Four )


	==== Starting Round 2 ====
	PLAYER 2: hand = Jack
	PLAYER 2: draws Nine
	PLAYER 2: hand = Jack, Nine
	PLAYER 2: does not win...
	PLAYER 2: discards Jack
	PLAYER 2: exits round
	DECK: (Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King Eight Jack Ten Four Jack )

	DECK: cards shuffled
	PLAYER 3: hand = Jack
	PLAYER 3: draws Two
	PLAYER 3: hand = Jack, Two
	PLAYER 3: does not win...
	PLAYER 3: discards Two
	PLAYER 3: exits round
	DECK: (Nine King Four Two Ten Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two )

	PLAYER 1: hand = Jack
	PLAYER 1: draws Nine
	PLAYER 1: hand = Jack, Nine
	PLAYER 1: does not win...
	PLAYER 1: discards Nine
	PLAYER 1: exits round
	DECK: (King Four Two Ten Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine )

	PLAYER 2: hand = Nine
	PLAYER 2: draws King
	PLAYER 2: hand = Nine, King
	PLAYER 2: does not win...
	PLAYER 2: discards King
	PLAYER 2: exits round
	DECK: (Four Two Ten Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King )

	PLAYER 3: hand = Jack
	PLAYER 3: draws Four
	PLAYER 3: hand = Jack, Four
	PLAYER 3: does not win...
	PLAYER 3: discards Jack
	PLAYER 3: exits round
	DECK: (Two Ten Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King Jack )

	PLAYER 1: hand = Jack
	PLAYER 1: draws Two
	PLAYER 1: hand = Jack, Two
	PLAYER 1: does not win...
	PLAYER 1: discards Jack
	PLAYER 1: exits round
	DECK: (Ten Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King Jack Jack )

	PLAYER 2: hand = Nine
	PLAYER 2: draws Ten
	PLAYER 2: hand = Nine, Ten
	PLAYER 2: does not win...
	PLAYER 2: discards Ten
	PLAYER 2: exits round
	DECK: (Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King Jack Jack Ten )

	PLAYER 3: hand = Four
	PLAYER 3: draws Ten
	PLAYER 3: hand = Four, Ten
	PLAYER 3: does not win...
	PLAYER 3: discards Four
	PLAYER 3: exits round
	DECK: (Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King Jack Jack Ten Four )

	PLAYER 1: hand = Two
	PLAYER 1: draws Two
	PLAYER 1: hand = Two, Two
	PLAYER 1: wins!!!
	DECK: (Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King Jack Jack Ten Four )


	==== Starting Round 3 ====
	DECK: cards shuffled
	PLAYER 3: hand = Eight
	PLAYER 3: draws Two
	PLAYER 3: hand = Eight, Two
	PLAYER 3: does not win...
	PLAYER 3: discards Two
	PLAYER 3: exits round
	DECK: (Nine King Four Two Ten Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two )

	PLAYER 1: hand = Jack
	PLAYER 1: draws Nine
	PLAYER 1: hand = Jack, Nine
	PLAYER 1: does not win...
	PLAYER 1: discards Nine
	PLAYER 1: exits round
	DECK: (King Four Two Ten Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine )

	PLAYER 2: hand = Jack
	PLAYER 2: draws King
	PLAYER 2: hand = Jack, King
	PLAYER 2: does not win...
	PLAYER 2: discards King
	PLAYER 2: exits round
	DECK: (Four Two Ten Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King )

	PLAYER 3: hand = Eight
	PLAYER 3: draws Four
	PLAYER 3: hand = Eight, Four
	PLAYER 3: does not win...
	PLAYER 3: discards Eight
	PLAYER 3: exits round
	DECK: (Two Ten Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King Eight )

	PLAYER 1: hand = Jack
	PLAYER 1: draws Two
	PLAYER 1: hand = Jack, Two
	PLAYER 1: does not win...
	PLAYER 1: discards Jack
	PLAYER 1: exits round
	DECK: (Ten Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King Eight Jack )

	PLAYER 2: hand = Jack
	PLAYER 2: draws Ten
	PLAYER 2: hand = Jack, Ten
	PLAYER 2: does not win...
	PLAYER 2: discards Ten
	PLAYER 2: exits round
	DECK: (Ten Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King Eight Jack Ten )

	PLAYER 3: hand = Four
	PLAYER 3: draws Ten
	PLAYER 3: hand = Four, Ten
	PLAYER 3: does not win...
	PLAYER 3: discards Four
	PLAYER 3: exits round
	DECK: (Two Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King Eight Jack Ten Four )

	PLAYER 1: hand = Two
	PLAYER 1: draws Two
	PLAYER 1: hand = Two, Two
	PLAYER 1: wins!!!
	DECK: (Nine Four Ten Jack Eight Four Six Four Two Five Three Eight Queen Five Eight Eight Three Nine Five Six Five Three Five Six King Five Nine Two Ace Seven Five Nine Ten Two Eight Seven Seven King Ten Eight Four Two Nine King Eight Jack Ten Four )


	Game finished in 3 rounds.

# Result 5:

	Enter a seed value: 5

	==== Starting Round 1 ====
	PLAYER 1: hand = Ace
	DECK: cards shuffled
	PLAYER 1: draws Seven
	PLAYER 1: hand = Ace, Seven
	PLAYER 1: does not win...
	PLAYER 1: discards Ace
	PLAYER 1: exits round
	DECK: (Six Two Jack Three Eight Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ace )

	PLAYER 2: hand = Ten
	PLAYER 2: draws Six
	PLAYER 2: hand = Ten, Six
	PLAYER 2: does not win...
	PLAYER 2: discards Six
	PLAYER 2: exits round
	DECK: (Two Jack Three Eight Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ace Six )

	PLAYER 3: hand = Four
	PLAYER 3: draws Two
	PLAYER 3: hand = Four, Two
	PLAYER 3: does not win...
	PLAYER 3: discards Four
	PLAYER 3: exits round
	DECK: (Jack Three Eight Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ace Six Four )

	PLAYER 1: hand = Seven
	PLAYER 1: draws Jack
	PLAYER 1: hand = Seven, Jack
	PLAYER 1: does not win...
	PLAYER 1: discards Jack
	PLAYER 1: exits round
	DECK: (Three Eight Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ace Six Four Jack )

	PLAYER 2: hand = Ten
	PLAYER 2: draws Three
	PLAYER 2: hand = Ten, Three
	PLAYER 2: does not win...
	PLAYER 2: discards Three
	PLAYER 2: exits round
	DECK: (Eight Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ace Six Four Jack Three )

	PLAYER 3: hand = Two
	PLAYER 3: draws Eight
	PLAYER 3: hand = Two, Eight
	PLAYER 3: does not win...
	PLAYER 3: discards Eight
	PLAYER 3: exits round
	DECK: (Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ace Six Four Jack Three Eight )

	PLAYER 1: hand = Seven
	PLAYER 1: draws Four
	PLAYER 1: hand = Seven, Four
	PLAYER 1: does not win...
	PLAYER 1: discards Four
	PLAYER 1: exits round
	DECK: (Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ace Six Four Jack Three Eight Four )

	PLAYER 2: hand = Ten
	PLAYER 2: draws Ten
	PLAYER 2: hand = Ten, Ten
	PLAYER 2: wins!!!
	DECK: (Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ace Six Four Jack Three Eight Four )


	==== Starting Round 2 ====
	DECK: cards shuffled
	PLAYER 2: hand = Ten
	PLAYER 2: draws Four
	PLAYER 2: hand = Ten, Four
	PLAYER 2: does not win...
	PLAYER 2: discards Ten
	PLAYER 2: exits round
	DECK: (Six Two Jack Three Eight Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ten )

	PLAYER 3: hand = Queen
	PLAYER 3: draws Six
	PLAYER 3: hand = Queen, Six
	PLAYER 3: does not win...
	PLAYER 3: discards Six
	PLAYER 3: exits round
	DECK: (Two Jack Three Eight Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ten Six )

	PLAYER 1: hand = Ten
	PLAYER 1: draws Two
	PLAYER 1: hand = Ten, Two
	PLAYER 1: does not win...
	PLAYER 1: discards Ten
	PLAYER 1: exits round
	DECK: (Jack Three Eight Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ten Six Ten )

	PLAYER 2: hand = Four
	PLAYER 2: draws Jack
	PLAYER 2: hand = Four, Jack
	PLAYER 2: does not win...
	PLAYER 2: discards Jack
	PLAYER 2: exits round
	DECK: (Three Eight Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ten Six Ten Jack )

	PLAYER 3: hand = Queen
	PLAYER 3: draws Three
	PLAYER 3: hand = Queen, Three
	PLAYER 3: does not win...
	PLAYER 3: discards Three
	PLAYER 3: exits round
	DECK: (Eight Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ten Six Ten Jack Three )

	PLAYER 1: hand = Two
	PLAYER 1: draws Eight
	PLAYER 1: hand = Two, Eight
	PLAYER 1: does not win...
	PLAYER 1: discards Eight
	PLAYER 1: exits round
	DECK: (Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ten Six Ten Jack Three Eight )

	PLAYER 2: hand = Four
	PLAYER 2: draws Four
	PLAYER 2: hand = Four, Four
	PLAYER 2: wins!!!
	DECK: (Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ten Six Ten Jack Three Eight )


	==== Starting Round 3 ====
	PLAYER 3: hand = Queen
	PLAYER 3: draws Ten
	PLAYER 3: hand = Queen, Ten
	PLAYER 3: does not win...
	PLAYER 3: discards Ten
	PLAYER 3: exits round
	DECK: (Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ten Six Ten Jack Three Eight Ten )

	PLAYER 1: hand = Ten
	PLAYER 1: draws Eight
	PLAYER 1: hand = Ten, Eight
	PLAYER 1: does not win...
	PLAYER 1: discards Eight
	PLAYER 1: exits round
	DECK: (Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ten Six Ten Jack Three Eight Ten Eight )

	PLAYER 2: hand = Seven
	PLAYER 2: draws Eight
	PLAYER 2: hand = Seven, Eight
	PLAYER 2: does not win...
	PLAYER 2: discards Seven
	PLAYER 2: exits round
	DECK: (Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Ten Six Ten Jack Three Eight Ten Eight Seven )

	PLAYER 3: hand = Queen
	DECK: cards shuffled
	PLAYER 3: draws Seven
	PLAYER 3: hand = Queen, Seven
	PLAYER 3: does not win...
	PLAYER 3: discards Queen
	PLAYER 3: exits round
	DECK: (Six Two Jack Three Eight Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Queen )

	PLAYER 1: hand = Ten
	PLAYER 1: draws Six
	PLAYER 1: hand = Ten, Six
	PLAYER 1: does not win...
	PLAYER 1: discards Six
	PLAYER 1: exits round
	DECK: (Two Jack Three Eight Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Queen Six )

	PLAYER 2: hand = Eight
	PLAYER 2: draws Two
	PLAYER 2: hand = Eight, Two
	PLAYER 2: does not win...
	PLAYER 2: discards Eight
	PLAYER 2: exits round
	DECK: (Jack Three Eight Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Queen Six Eight )

	PLAYER 3: hand = Seven
	PLAYER 3: draws Jack
	PLAYER 3: hand = Seven, Jack
	PLAYER 3: does not win...
	PLAYER 3: discards Jack
	PLAYER 3: exits round
	DECK: (Three Eight Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Queen Six Eight Jack )

	PLAYER 1: hand = Ten
	PLAYER 1: draws Three
	PLAYER 1: hand = Ten, Three
	PLAYER 1: does not win...
	PLAYER 1: discards Three
	PLAYER 1: exits round
	DECK: (Eight Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Queen Six Eight Jack Three )

	PLAYER 2: hand = Two
	PLAYER 2: draws Eight
	PLAYER 2: hand = Two, Eight
	PLAYER 2: does not win...
	PLAYER 2: discards Eight
	PLAYER 2: exits round
	DECK: (Four Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Queen Six Eight Jack Three Eight )

	PLAYER 3: hand = Seven
	PLAYER 3: draws Four
	PLAYER 3: hand = Seven, Four
	PLAYER 3: does not win...
	PLAYER 3: discards Four
	PLAYER 3: exits round
	DECK: (Ten Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Queen Six Eight Jack Three Eight Four )

	PLAYER 1: hand = Ten
	PLAYER 1: draws Ten
	PLAYER 1: hand = Ten, Ten
	PLAYER 1: wins!!!
	DECK: (Eight Eight Two Five Ace King Ten Jack Six Ten Jack Eight Ten Nine Two Ten Ace King Seven Nine Six Seven Seven Nine King Eight Eight Two Four Queen Queen Jack Eight King Two Ten Ace King Seven Six Nine Queen Six Eight Jack Three Eight Four )


	Game finished in 3 rounds.

# End of Report