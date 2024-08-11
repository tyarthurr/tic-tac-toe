#include <iostream>

std::string clearBoard(std::string targetBoard);
void menuCommand(bool targetValidInput, char targetMenuInput, std::string targetBoard);
std::string playerGameplay(std::string player, char playerChar, int playerMovePosition, std::string targetBoard);

int main() 
{
	//Game description
	std::string gameDescription =
		"Welcome to the game of Tic-Tac-Toe!\n"
		"	The game is played on a grid that is 3 squares by 3 squares.\n"
		"	The first player is X, and the second player is O.\n"
		"	Players take turns putting their marks in empty squares.\n"
		"	The first player to get 3 of their marks in a row (up, down, across, or diagonally) is the winner.\n\n"
		"How to play:\n"
		"	See the example Tic-Tac-Toe grid below.\n"
		"	Each space in the grid is represented by a number as seen in the example grid\n" 
		"		Note: Use the example grid as a reference. The grid spaces at the start of a new game will be blank.\n"
		"	Type in a number then press 'Enter' on your keyboard to place your character in the corresponding grid space.\n\n"
		"Legend:\n"
		"	N = New game (ends any ongoing game)\n"
		"	Z = Undo the previous move\n"
		"	H = Help (shows available moves)\n"
		"	E = End game and quit program\n";

	std::string blueprintBoard =
		"             \n"
		"  1 | 2 | 3  \n"
		" ----------- \n"
		"  4 | 5 | 6  \n"
		" ----------- \n"
		"  7 | 8 | 9  \n"
		"             \n";

	//Initialise game
	std::cout << gameDescription + blueprintBoard;
	std::string activeBoard = clearBoard(blueprintBoard);
	char menuInput = ' ';
	bool validInput = false;
	std::string playerOne;
	std::string playerTwo;
	int playerOneMovePosition = 0;
	int playerTwoMovePosition = 0;
	char playerOneChar = 'O';
	char playerTwoChar = 'X';

	//Game experience
	std::cout << "Input the 'N' command to start a new game:\n";
	menuCommand(validInput, menuInput, activeBoard);
	std::cout << "Player 1, enter your name:\n";
	std::cin >> playerOne;
	std::cout << "Player 2, enter your name:\n";
	std::cin >> playerTwo;
	playerGameplay(playerOne, playerOneChar, playerOneMovePosition, activeBoard);
	

	//Keep the game running until player decides to quit
	while(menuInput != 'E')
	{
		continue;
	}

	return 0;
}

//replaces any character in specified string position with *space* whichc orresponds to grid spaces on the game board
std::string clearBoard(std::string targetBoard)
{
	targetBoard[16] = ' ';
	targetBoard[20] = ' ';
	targetBoard[24] = ' ';
	targetBoard[44] = ' ';
	targetBoard[48] = ' ';
	targetBoard[52] = ' ';
	targetBoard[72] = ' ';
	targetBoard[76] = ' ';
	targetBoard[80] = ' ';

	return targetBoard;
}

//forces player to either create new board or quit game
void menuCommand(bool targetValidInput, char targetMenuInput, std::string targetBoard)
{
	while(targetValidInput != true)
	{
		std::cin >> targetMenuInput;
		if(targetMenuInput == 'N')
		{
			targetValidInput = true;
			std::cout << targetBoard;
		}
		else if(targetMenuInput == 'E')
		{
			targetValidInput = true;
			std::exit(EXIT_SUCCESS);
		}
		else
		{
			targetValidInput = false;
			std::cout << "This is not a valid command. Input the 'N' command to start a new game:\n";
		}
	}
}

//events when a player makes a move (player is determined by whichever player variable is in the function call argument)
std::string playerGameplay(std::string player, char playerChar, int playerMovePosition, std::string targetBoard)
{
	std::cout << player << ", which space on the grid would you like to place your character?\n";
	std::cin >> playerMovePosition;
	switch(playerMovePosition)
	{
	case 1:
		targetBoard[16] = playerChar;
	case 2:
		targetBoard[20] = playerChar;
	case 3:
		targetBoard[24] = playerChar;
	case 4:
		targetBoard[44] = playerChar;
	case 5:
		targetBoard[48] = playerChar;
	case 6:
		targetBoard[52] = playerChar;
	case 7:
		targetBoard[72] = playerChar;
	case 8:
		targetBoard[76] = playerChar;
	case 9:
		targetBoard[80] = playerChar;
	default:
		std::cout << "This is an invalid move.";
	}

	return targetBoard;
}

/*OBJECTIVE:
* make the switch case work properly
* clean up unnecessary main variables being used as arguments and parameters for functions when these variables can be made within just the function scope instead
*/