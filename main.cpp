/*OBJECTIVE:
- FIX: user currently wins if a combination of O and X fills a winning line whereas it should only be one or the other filling a winning line that determines the win
- FIX: prevention of move overwiting only occurs once - on the second attempt, an unintentional overwrite occurs
- FIX: move overwiting prevention is inconsistent or not working for player 1
- FIX: creating a new game after an endgame, breaks while loop and runs into programmer-defined undefined behaviour error and also doesn't clear board
- FIX: occurrence endgame behaviour seems inconsistent?
*/

#include <iostream>

std::string clearBoard(std::string targetBoard);
void menuCommand(char targetMenuInput, std::string targetBoard);
std::string playerGameplay(std::string player, char playerChar, std::string targetBoard);
bool endgameCheck(std::string playerName, char playerChar, std::string targetBoard, bool endgameValidity);

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
	std::string playerOne;
	std::string playerTwo;
	char playerOneChar = 'O';
	char playerTwoChar = 'X';
	bool endgame = false;

	//Game experience
	std::cout << "Input the 'N' command to start a new game:\n";
	menuCommand(menuInput, activeBoard);
	std::cout << "Player 1, enter your name:\n";
	std::cin >> playerOne;
	std::cout << "Player 2, enter your name:\n";
	std::cin >> playerTwo;

	while(endgame == false)
	{
		activeBoard = playerGameplay(playerOne, playerOneChar, activeBoard);
		std::cout << activeBoard;
		endgame = endgameCheck(playerOne, playerOneChar, activeBoard, endgame);

		activeBoard = playerGameplay(playerTwo, playerTwoChar, activeBoard);
		std::cout << activeBoard;
		endgame = endgameCheck(playerTwo, playerTwoChar, activeBoard, endgame);

		if (endgame == true)
		{
			std::cout << "Input the 'N' command to start a new game or input the 'E' command to exit the game:\n";
			menuCommand(menuInput, activeBoard);
			continue;
		}
		else
		{
			continue;
		}
	}

	//If user has not deliberately exited and compiler has gone past the above while loop, display undefined behaviour error for debugging and continue program instance
	std::cout << "Error: Undefined Behaviour";
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
void menuCommand(char targetMenuInput, std::string targetBoard)
{
	bool targetValidInput = false;
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
std::string playerGameplay(std::string playerName, char playerChar, std::string targetBoard)
{
	bool invalidMove = false;
	char playerMovePosition;
	std::cout << playerName << ", which space on the grid would you like to place your character?\n";

	while(invalidMove == false)
	{
		std::cin >> playerMovePosition;
		switch(playerMovePosition)
		{
		case '1':
			if(targetBoard[16] == 'O' && 'X')
			{
				std::cout << "This is an invalid move.\n";
				break;
			}
			else
			{
				targetBoard[16] = playerChar;
				invalidMove = true;
				break;
			}
		case '2':
			if(targetBoard[20] == 'O' && 'X')
			{
				std::cout << "This is an invalid move.\n";
				break;
			}
			else
			{
				targetBoard[20] = playerChar;
				invalidMove = true;
				break;
			}
		case '3':
			if(targetBoard[24] == 'O' && 'X')
			{
				std::cout << "This is an invalid move.\n";
				break;
			}
			else
			{
				targetBoard[24] = playerChar;
				invalidMove = true;
				break;
			}
		case '4':
			if(targetBoard[44] == 'O' && 'X')
			{
				std::cout << "This is an invalid move.\n";
				break;
			}
			else
			{
				targetBoard[44] = playerChar;
				invalidMove = true;
				break;
			}
		case '5':
			if(targetBoard[48] == 'O' && 'X')
			{
				std::cout << "This is an invalid move.\n";
				break;
			}
			else
			{
				targetBoard[48] = playerChar;
				invalidMove = true;
				break;
			}
		case '6':
			if(targetBoard[52] == 'O' && 'X')
			{
				std::cout << "This is an invalid move.\n";
				break;
			}
			else
			{
				targetBoard[52] = playerChar;
				invalidMove = true;
				break;
			}
		case '7':
			if(targetBoard[72] == 'O' && 'X')
			{
				std::cout << "This is an invalid move.\n";
				break;
			}
			else
			{
				targetBoard[72] = playerChar;
				invalidMove = true;
				break;
			}
		case '8':
			if(targetBoard[76] == 'O' && 'X')
			{
				std::cout << "This is an invalid move.\n";
				break;
			}
			else
			{
				targetBoard[76] = playerChar;
				invalidMove = true;
				break;
			}
		case '9':
			if(targetBoard[80] == 'O' && 'X')
			{
				std::cout << "This is an invalid move.\n";
				break;
			}
			else
			{
				targetBoard[80] = playerChar;
				invalidMove = true;
				break;
			}
		default:
			std::cout << "This is an invalid move.\n";
			break;
		}
	}

	return targetBoard;
}

bool endgameCheck(std::string playerName, char playerChar, std::string targetBoard, bool endgameValidity)
{
	char topHorizontalLine[] =
	{
		topHorizontalLine[0] = targetBoard[16],
		topHorizontalLine[1] = targetBoard[20],
		topHorizontalLine[2] = targetBoard[24]
	};
	char midHorizontalLine[] =
	{
		midHorizontalLine[0] = targetBoard[44],
		midHorizontalLine[1] = targetBoard[48],
		midHorizontalLine[2] = targetBoard[52]
	};
	char bottHorizontalLine[] =
	{
		bottHorizontalLine[0] = targetBoard[72],
		bottHorizontalLine[1] = targetBoard[76],
		bottHorizontalLine[2] = targetBoard[80]
	};
	char leftVerticalLine[] =
	{
		leftVerticalLine[0] = targetBoard[16],
		leftVerticalLine[1] = targetBoard[44],
		leftVerticalLine[2] = targetBoard[72]
	};
	char midVerticalLine[] =
	{
		midVerticalLine[0] = targetBoard[20],
		midVerticalLine[1] = targetBoard[48],
		midVerticalLine[2] = targetBoard[76]
	};
	char rightVerticalLine[] =
	{
		rightVerticalLine[0] = targetBoard[24],
		rightVerticalLine[1] = targetBoard[52],
		rightVerticalLine[2] = targetBoard[80]
	};
	char decDiagonalLine[] =
	{
		decDiagonalLine[0] = targetBoard[16],
		decDiagonalLine[1] = targetBoard[48],
		decDiagonalLine[2] = targetBoard[80]
	};
	char incDiagonalLine[] =
	{
		incDiagonalLine[0] = targetBoard[72],
		incDiagonalLine[1] = targetBoard[48],
		incDiagonalLine[2] = targetBoard[24]
	};
	char winningLine[] =
	{
		winningLine[0] = topHorizontalLine[0, 1, 2],
		winningLine[1] = midHorizontalLine[0, 1, 2],
		winningLine[2] = bottHorizontalLine[0, 1, 2],
		winningLine[3] = leftVerticalLine[0, 1, 2],
		winningLine[4] = midVerticalLine[0, 1, 2],
		winningLine[5] = rightVerticalLine[0, 1, 2],
		winningLine[6] = decDiagonalLine[0, 1, 2],
		winningLine[7] = incDiagonalLine[0, 1, 2]
	};

	if(winningLine[0, 1, 2, 3, 4, 5, 6, 7] == playerChar)
	{
		std::cout << playerName << " wins!\n";
		endgameValidity = true;
	}

	return endgameValidity;
}