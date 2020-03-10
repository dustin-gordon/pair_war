# pair_war

	CS 4328 Operating Systems
	Programming Assignment 1

	Dustin Gordon - dmg210
	Jose Mayorga  - jmm498

"Pair War" is a simple card game that implements POSIX threads. In our implementation, the "dealer" and 3 "players" are represented as 4 separate threads. The dealer thread controls a data structure representing the deck of cards. The player threads control data structures representing the player's hand. The threads are created in main and player threads are called in turn order. A random seed is generated at runtime for use in randomizing the order of the deck. This performed at the beginning of every round when the dealer calls the shuffle method. During each player's turn, the respective thread will check if drawn card is a match. If so, the game is over and all other threads will exit. If a match is not drawn, a randomly selected card is discarded from the player's hand and their turn ends. The game is designed to continue rounds until a player wins.


# To compile and run:

Please copy "main.cpp" to a Linux environment, and enter the following command to compile:

	g++ -pthread main.cpp -o pw; ./pw

To run, enter the following command:

	./pw

# Result 1:

	==== Round 1 ====
	DEALER: cards shuffled
	DEALER: current deck = (Six Nine Five Seven Seven Six Two Six Four Jack Ace King Jack Four Ten Queen Eight Eight Two Two Nine Six Ace Jack King Three Seven Five Queen Ten Six Four Seven Ten Jack Two Two Ace Nine Seven Queen Nine Six Nine Queen Four Seven Seven Jack Ten Ten Eight )

	Player 1's turn
	PLAYER 1: draws 1st card 
	PLAYER 1: hand = Six
	PLAYER 1: draws Nine
	PLAYER 1: hand = Six, Nine
	PLAYER 1: does not win...
	PLAYER 1: discards Six
	PLAYER 1: exits round

	Player 2's turn
	PLAYER 2: draws 1st card 
	PLAYER 2: hand = Five
	PLAYER 2: draws Seven
	PLAYER 2: hand = Five, Seven
	PLAYER 2: does not win...
	PLAYER 2: discards Five
	PLAYER 2: exits round

	Player 3's turn
	PLAYER 3: draws 1st card 
	PLAYER 3: hand = Seven
	PLAYER 3: draws Six
	PLAYER 3: hand = Seven, Six
	PLAYER 3: does not win...
	PLAYER 3: discards Six
	PLAYER 3: exits round

	==== Round 2 ====
	DEALER: cards shuffled
	DEALER: current deck = (Six Nine Five Seven Seven Six Two Six Four Jack Ace King Jack Four Ten Queen Eight Eight Two Two Nine Six Ace Jack King Three Seven Five Queen Ten Six Four Seven Ten Jack Two Two Ace Nine Seven Queen Nine Six Nine Queen Four Seven Seven Jack Ten Ten Eight )

	Player 1's turn
	PLAYER 1: hand = Nine
	PLAYER 1: draws Six
	PLAYER 1: hand = Nine, Six
	PLAYER 1: does not win...
	PLAYER 1: discards Nine
	PLAYER 1: exits round

	Player 2's turn
	PLAYER 2: hand = Seven
	PLAYER 2: draws Nine
	PLAYER 2: hand = Seven, Nine
	PLAYER 2: does not win...
	PLAYER 2: discards Seven
	PLAYER 2: exits round

	Player 3's turn
	PLAYER 3: hand = Seven
	PLAYER 3: draws Five
	PLAYER 3: hand = Seven, Five
	PLAYER 3: does not win...
	PLAYER 3: discards Five
	PLAYER 3: exits round

	==== Round 3 ====
	DEALER: cards shuffled
	DEALER: current deck = (Six Nine Five Seven Seven Six Two Six Four Jack Ace King Jack Four Ten Queen Eight Eight Two Two Nine Six Ace Jack King Three Seven Five Queen Ten Six Four Seven Ten Jack Two Two Ace Nine Seven Queen Nine Six Nine Queen Four Seven Seven Jack Ten Ten Eight )

	Player 1's turn
	PLAYER 1: hand = Six
	PLAYER 1: draws Six
	PLAYER 1: hand = Six, Six
	PLAYER 1: wins!!!
	PLAYER 1: exits round


	Game finished in 3 rounds.

# Result 2:

	==== Round 1 ====
	DEALER: cards shuffled
	DEALER: current deck = (Four Queen Four Five Ace Seven Six Two Three Two King Eight Seven Nine Jack Ten Ten Queen Jack King Two Seven Ace Three Ace Three Nine Three Ten Seven Eight Two Seven Ace Eight Seven Seven Ace Ten Jack Four Nine Eight Ten Six Seven Nine Two Five Six Four Six )

	Player 1's turn
	PLAYER 1: draws 1st card 
	PLAYER 1: hand = Four
	PLAYER 1: draws Queen
	PLAYER 1: hand = Four, Queen
	PLAYER 1: does not win...
	PLAYER 1: discards Queen
	PLAYER 1: exits round

	Player 2's turn
	PLAYER 2: draws 1st card 
	PLAYER 2: hand = Four
	PLAYER 2: draws Five
	PLAYER 2: hand = Four, Five
	PLAYER 2: does not win...
	PLAYER 2: discards Five
	PLAYER 2: exits round

	Player 3's turn
	PLAYER 3: draws 1st card 
	PLAYER 3: hand = Ace
	PLAYER 3: draws Seven
	PLAYER 3: hand = Ace, Seven
	PLAYER 3: does not win...
	PLAYER 3: discards Seven
	PLAYER 3: exits round

	==== Round 2 ====
	DEALER: cards shuffled
	DEALER: current deck = (Four Queen Four Five Ace Seven Six Two Three Two King Eight Seven Nine Jack Ten Ten Queen Jack King Two Seven Ace Three Ace Three Nine Three Ten Seven Eight Two Seven Ace Eight Seven Seven Ace Ten Jack Four Nine Eight Ten Six Seven Nine Two Five Six Four Six )

	Player 1's turn
	PLAYER 1: hand = Four
	PLAYER 1: draws Four
	PLAYER 1: hand = Four, Four
	PLAYER 1: wins!!!
	PLAYER 1: exits round


	Game finished in 2 rounds.

# Result 3:

	==== Round 1 ====
	DEALER: cards shuffled
	DEALER: current deck = (Nine Jack Ace Five Five Jack Ten King Seven Five Ace King Six Nine King Four Five Two Eight Two Seven Ace Two Eight Three Ace Four Two Two Five Two Jack Three Three Two Seven King Jack Six Nine Two Six Ten Nine Three Nine Ace Seven Queen Ten Jack Six )

	Player 1's turn
	PLAYER 1: draws 1st card 
	PLAYER 1: hand = Nine
	PLAYER 1: draws Jack
	PLAYER 1: hand = Nine, Jack
	PLAYER 1: does not win...
	PLAYER 1: discards Jack
	PLAYER 1: exits round

	Player 2's turn
	PLAYER 2: draws 1st card 
	PLAYER 2: hand = Ace
	PLAYER 2: draws Five
	PLAYER 2: hand = Ace, Five
	PLAYER 2: does not win...
	PLAYER 2: discards Ace
	PLAYER 2: exits round

	Player 3's turn
	PLAYER 3: draws 1st card 
	PLAYER 3: hand = Five
	PLAYER 3: draws Jack
	PLAYER 3: hand = Five, Jack
	PLAYER 3: does not win...
	PLAYER 3: discards Jack
	PLAYER 3: exits round

	==== Round 2 ====
	DEALER: cards shuffled
	DEALER: current deck = (Nine Jack Ace Five Five Jack Ten King Seven Five Ace King Six Nine King Four Five Two Eight Two Seven Ace Two Eight Three Ace Four Two Two Five Two Jack Three Three Two Seven King Jack Six Nine Two Six Ten Nine Three Nine Ace Seven Queen Ten Jack Six )

	Player 1's turn
	PLAYER 1: hand = Nine
	PLAYER 1: draws Nine
	PLAYER 1: hand = Nine, Nine
	PLAYER 1: wins!!!
	PLAYER 1: exits round


	Game finished in 2 rounds.

# Result 4:

	==== Round 1 ====
	DEALER: cards shuffled
	DEALER: current deck = (Nine Eight King Nine Six Four Five King Queen Five Five Ace Three Ten Four Ten Two Queen Four Ten Ten Five Ace Jack Four Seven Queen Four Jack Ten Two Six Four Three Ace Nine Six Five Nine Seven Jack King Nine Ace Nine Queen Queen King Jack Four Jack Nine )

	Player 1's turn
	PLAYER 1: draws 1st card 
	PLAYER 1: hand = Nine
	PLAYER 1: draws Eight
	PLAYER 1: hand = Nine, Eight
	PLAYER 1: does not win...
	PLAYER 1: discards Nine
	PLAYER 1: exits round

	Player 2's turn
	PLAYER 2: draws 1st card 
	PLAYER 2: hand = King
	PLAYER 2: draws Nine
	PLAYER 2: hand = King, Nine
	PLAYER 2: does not win...
	PLAYER 2: discards Nine
	PLAYER 2: exits round

	Player 3's turn
	PLAYER 3: draws 1st card 
	PLAYER 3: hand = Six
	PLAYER 3: draws Four
	PLAYER 3: hand = Six, Four
	PLAYER 3: does not win...
	PLAYER 3: discards Four
	PLAYER 3: exits round

	==== Round 2 ====
	DEALER: cards shuffled
	DEALER: current deck = (Nine Eight King Nine Six Four Five King Queen Five Five Ace Three Ten Four Ten Two Queen Four Ten Ten Five Ace Jack Four Seven Queen Four Jack Ten Two Six Four Three Ace Nine Six Five Nine Seven Jack King Nine Ace Nine Queen Queen King Jack Four Jack Nine )

	Player 1's turn
	PLAYER 1: hand = Eight
	PLAYER 1: draws Nine
	PLAYER 1: hand = Eight, Nine
	PLAYER 1: does not win...
	PLAYER 1: discards Eight
	PLAYER 1: exits round

	Player 2's turn
	PLAYER 2: hand = King
	PLAYER 2: draws Eight
	PLAYER 2: hand = King, Eight
	PLAYER 2: does not win...
	PLAYER 2: discards Eight
	PLAYER 2: exits round

	Player 3's turn
	PLAYER 3: hand = Six
	PLAYER 3: draws King
	PLAYER 3: hand = Six, King
	PLAYER 3: does not win...
	PLAYER 3: discards King
	PLAYER 3: exits round

	==== Round 3 ====
	DEALER: cards shuffled
	DEALER: current deck = (Nine Eight King Nine Six Four Five King Queen Five Five Ace Three Ten Four Ten Two Queen Four Ten Ten Five Ace Jack Four Seven Queen Four Jack Ten Two Six Four Three Ace Nine Six Five Nine Seven Jack King Nine Ace Nine Queen Queen King Jack Four Jack Nine )

	Player 1's turn
	PLAYER 1: hand = Nine
	PLAYER 1: draws Nine
	PLAYER 1: hand = Nine, Nine
	PLAYER 1: wins!!!
	PLAYER 1: exits round


	Game finished in 3 rounds.

# Result 5:

	==== Round 1 ====
	DEALER: cards shuffled
	DEALER: current deck = (Four Three Queen Eight Two Six Three Seven Jack King Five Ace Five Nine Six Ten Two Six Jack Two Nine Seven Five Five Seven Queen Seven Six Three Ace Ace Eight Three Ace Three Six Six Seven Queen Five Six Six Six Queen Three Jack Eight Five Five Six Six Ace )

	Player 1's turn
	PLAYER 1: draws 1st card 
	PLAYER 1: hand = Four
	PLAYER 1: draws Three
	PLAYER 1: hand = Four, Three
	PLAYER 1: does not win...
	PLAYER 1: discards Four
	PLAYER 1: exits round

	Player 2's turn
	PLAYER 2: draws 1st card 
	PLAYER 2: hand = Queen
	PLAYER 2: draws Eight
	PLAYER 2: hand = Queen, Eight
	PLAYER 2: does not win...
	PLAYER 2: discards Queen
	PLAYER 2: exits round

	Player 3's turn
	PLAYER 3: draws 1st card 
	PLAYER 3: hand = Two
	PLAYER 3: draws Six
	PLAYER 3: hand = Two, Six
	PLAYER 3: does not win...
	PLAYER 3: discards Two
	PLAYER 3: exits round

	==== Round 2 ====
	DEALER: cards shuffled
	DEALER: current deck = (Four Three Queen Eight Two Six Three Seven Jack King Five Ace Five Nine Six Ten Two Six Jack Two Nine Seven Five Five Seven Queen Seven Six Three Ace Ace Eight Three Ace Three Six Six Seven Queen Five Six Six Six Queen Three Jack Eight Five Five Six Six Ace )

	Player 1's turn
	PLAYER 1: hand = Three
	PLAYER 1: draws Four
	PLAYER 1: hand = Three, Four
	PLAYER 1: does not win...
	PLAYER 1: discards Three
	PLAYER 1: exits round

	Player 2's turn
	PLAYER 2: hand = Eight
	PLAYER 2: draws Three
	PLAYER 2: hand = Eight, Three
	PLAYER 2: does not win...
	PLAYER 2: discards Eight
	PLAYER 2: exits round

	Player 3's turn
	PLAYER 3: hand = Six
	PLAYER 3: draws Queen
	PLAYER 3: hand = Six, Queen
	PLAYER 3: does not win...
	PLAYER 3: discards Six
	PLAYER 3: exits round

	==== Round 3 ====
	DEALER: cards shuffled
	DEALER: current deck = (Four Three Queen Eight Two Six Three Seven Jack King Five Ace Five Nine Six Ten Two Six Jack Two Nine Seven Five Five Seven Queen Seven Six Three Ace Ace Eight Three Ace Three Six Six Seven Queen Five Six Six Six Queen Three Jack Eight Five Five Six Six Ace )

	Player 1's turn
	PLAYER 1: hand = Four
	PLAYER 1: draws Four
	PLAYER 1: hand = Four, Four
	PLAYER 1: wins!!!
	PLAYER 1: exits round


	Game finished in 3 rounds.

# End of report