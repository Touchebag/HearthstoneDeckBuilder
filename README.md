HearthstoneDeckBuilder
======================

An application for saving and rebuilding decks in Hearthstone

###Compilation
You will need to have g++ installed to be able to compile the project. Compiling the program is done via the (extremely simple) makefile. Just run "make" (without the quotes) from the root directory of this project. 

_Note:_ This assumes that both g++ and make is in your path.

###Usage
First start Hearthstone and begin creating a new deck. You must have selected a hero and be on the card select screen.

Just run the program via the command line with a path to a file. If no file is specified (or if run via explorer) it will assume there's a file named "deck.txt" in the current directory.

The program will wait for five seconds to allow you to switch to Hearthstone.

###Deck file format:
The format of a deck files is based on the Cocaktrice format exported from https://hearthpwn.com and is subsequently able to read Cockatrice files out of the box. Just copy and paste into a text file and you're golden.

However I have added some extra stuff depending on the inital character of each line. Which can be seen in the table below.

|Character | Command | Notes|
|:--------:|:--------|:------|
| / | Comment | Regular comment. Program ignores line.|
| # | Deck name | The program will rename the deck to whatever comes after #.|
| 1/2 | Number of cards | Specifies whether to inlcude one or two copies of the card.|

If the first character of a line is not one of the aforementioned special characters it will treat the line as just a single copy of a card. This means you can just write "Ysera" (without the quotes) on a line and it will include a copy of Ysera.

If a line is empty it will be ignored.
