/*OBJECTIVE:
- debug singleplayer implementation: after players first move, program idles
*/

#include <iostream>
#include <ctime>
#include <random>

std::string clearBoard(std::string targetBoard);
void menuCommand(char targetMenuInput, std::string targetBoard);
std::string playerGameplay(std::string player, char playerChar, std::string targetBoard, bool computerMode = false);
bool endgameCheck(std::string playerName, char playerChar, std::string targetBoard, bool endgameValidity);

int main() 
{
	//game description
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

	//initialise game
	std::cout << gameDescription + blueprintBoard;
	std::string activeBoard;
	std::string *pActiveBoard = &activeBoard;
	*pActiveBoard = clearBoard(blueprintBoard);
	char menuInput = ' ';
	int gamemode;
	bool validGamemode = false;
	std::string computerName = "COMPUTER";
	std::string playerOne;
	std::string playerTwo;
	char playerOneChar = 'O';
	char playerTwoChar = 'X';
	bool endgame = false;

	//new game experience
	std::cout << "Input the 'N' command to start a new game:\n";
	menuCommand(menuInput, activeBoard);

	while (validGamemode == false)
	{
		std::cout << "Choose a gamemode (input the number representing each listed gameplay option below to select that gamemode):\n"
			<< "1 - Singleplayer (Player vs Computer)\n" << "2 - Multiplayer (Player vs Player)\n";
		std::cin >> gamemode;
		if (gamemode != 1 && gamemode != 2)
		{
			std::cout << "This is an invalid gamemode selection. Try again.\n";
			validGamemode = false;
		}
		else
		{
			validGamemode = true;
		}
	}
	
	//singleplayer gameplay
	if (gamemode == 1)
	{
		bool initialiseComputerGameplay = true;
		std::cout << "Player 1, enter your name:\n";
		std::cin >> playerOne;

		while (endgame == false)
		{
			activeBoard = playerGameplay(playerOne, playerOneChar, activeBoard);
			std::cout << activeBoard;
			endgame = endgameCheck(playerOne, playerOneChar, activeBoard, endgame);

			if (endgame == true)
			{
				std::cout << "Input the 'N' command to start a new game or input the 'E' command to exit the game:\n";
				*pActiveBoard = clearBoard(blueprintBoard);
				menuCommand(menuInput, *pActiveBoard);
				endgame = false;
			}

			activeBoard = playerGameplay(computerName, playerTwoChar, activeBoard, initialiseComputerGameplay);
			std::cout << activeBoard;
			endgame = endgameCheck(computerName, playerTwoChar, activeBoard, endgame);

			if (endgame == true)
			{
				std::cout << "Input the 'N' command to start a new game or input the 'E' command to exit the game:\n";
				*pActiveBoard = clearBoard(blueprintBoard);
				menuCommand(menuInput, *pActiveBoard);
				endgame = false;
			}
		}
	}

	//mutiplayer gameplay
	else if (gamemode == 2)
	{
		std::cout << "Player 1, enter your name:\n";
		std::cin >> playerOne;
		std::cout << "Player 2, enter your name:\n";
		std::cin >> playerTwo;

		while (endgame == false)
		{
			activeBoard = playerGameplay(playerOne, playerOneChar, activeBoard);
			std::cout << activeBoard;
			endgame = endgameCheck(playerOne, playerOneChar, activeBoard, endgame);

			if (endgame == true)
			{
				std::cout << "Input the 'N' command to start a new game or input the 'E' command to exit the game:\n";
				*pActiveBoard = clearBoard(blueprintBoard);
				menuCommand(menuInput, *pActiveBoard);
				endgame = false;
			}

			activeBoard = playerGameplay(playerTwo, playerTwoChar, activeBoard);
			std::cout << activeBoard;
			endgame = endgameCheck(playerTwo, playerTwoChar, activeBoard, endgame);

			if (endgame == true)
			{
				std::cout << "Input the 'N' command to start a new game or input the 'E' command to exit the game:\n";
				*pActiveBoard = clearBoard(blueprintBoard);
				menuCommand(menuInput, *pActiveBoard);
				endgame = false;
			}
		}
	}

	//if user has not deliberately exited and compiler has gone out of the gameplay bounds (above), display error for debugging and continue program instance
	else
	{
		std::cerr << "Error: The main function has gone out of bounds.";
	}

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
std::string playerGameplay(std::string playerName, char playerChar, std::string targetBoard, bool computerMode)
{
	bool invalidMove = false;
	
	//computer gameplay
	if (computerMode == true)
	{
		unsigned computerBrainSeed = static_cast<unsigned>(std::time(0));
		std::mt19937 computerBrainRNG(computerBrainSeed);
		std::uniform_int_distribution<> computerBrainSeedRange(0, 9);
		int computerBrain = computerBrainSeedRange(computerBrainRNG);
		static_cast<char>(computerBrain);

		while (invalidMove == false)
		{
			switch (computerBrain)
			{
			case '1':
				if (targetBoard[16] == 'X' || targetBoard[16] == 'O')
				{
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[16] = playerChar;
					invalidMove = true;
					break;
				}
			case '2':
				if (targetBoard[20] == 'X' || targetBoard[20] == 'O')
				{
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[20] = playerChar;
					invalidMove = true;
					break;
				}
			case '3':
				if (targetBoard[24] == 'X' || targetBoard[24] == 'O')
				{
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[24] = playerChar;
					invalidMove = true;
					break;
				}
			case '4':
				if (targetBoard[44] == 'X' || targetBoard[44] == 'O')
				{
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[44] = playerChar;
					invalidMove = true;
					break;
				}
			case '5':
				if (targetBoard[48] == 'X' || targetBoard[48] == 'O')
				{
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[48] = playerChar;
					invalidMove = true;
					break;
				}
			case '6':
				if (targetBoard[52] == 'X' || targetBoard[52] == 'O')
				{
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[52] = playerChar;
					invalidMove = true;
					break;
				}
			case '7':
				if (targetBoard[72] == 'X' || targetBoard[72] == 'O')
				{
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[72] = playerChar;
					invalidMove = true;
					break;
				}
			case '8':
				if (targetBoard[76] == 'X' || targetBoard[76] == 'O')
				{
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[76] = playerChar;
					invalidMove = true;
					break;
				}
			case '9':
				if (targetBoard[80] == 'X' || targetBoard[80] == 'O')
				{
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[80] = playerChar;
					invalidMove = true;
					break;
				}
			default:
				invalidMove = false;
				break;
			}
		}
	}

	//player gameplay
	else if (computerMode == false)
	{
		char playerMovePosition;
		std::cout << playerName << ", which space on the grid would you like to place your character?\n";

		while (invalidMove == false)
		{
			std::cin >> playerMovePosition;
			switch (playerMovePosition)
			{
			case '1':
				if (targetBoard[16] == 'X' || targetBoard[16] == 'O')
				{
					std::cout << "This is an invalid move.\n";
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[16] = playerChar;
					invalidMove = true;
					break;
				}
			case '2':
				if (targetBoard[20] == 'X' || targetBoard[20] == 'O')
				{
					std::cout << "This is an invalid move.\n";
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[20] = playerChar;
					invalidMove = true;
					break;
				}
			case '3':
				if (targetBoard[24] == 'X' || targetBoard[24] == 'O')
				{
					std::cout << "This is an invalid move.\n";
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[24] = playerChar;
					invalidMove = true;
					break;
				}
			case '4':
				if (targetBoard[44] == 'X' || targetBoard[44] == 'O')
				{
					std::cout << "This is an invalid move.\n";
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[44] = playerChar;
					invalidMove = true;
					break;
				}
			case '5':
				if (targetBoard[48] == 'X' || targetBoard[48] == 'O')
				{
					std::cout << "This is an invalid move.\n";
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[48] = playerChar;
					invalidMove = true;
					break;
				}
			case '6':
				if (targetBoard[52] == 'X' || targetBoard[52] == 'O')
				{
					std::cout << "This is an invalid move.\n";
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[52] = playerChar;
					invalidMove = true;
					break;
				}
			case '7':
				if (targetBoard[72] == 'X' || targetBoard[72] == 'O')
				{
					std::cout << "This is an invalid move.\n";
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[72] = playerChar;
					invalidMove = true;
					break;
				}
			case '8':
				if (targetBoard[76] == 'X' || targetBoard[76] == 'O')
				{
					std::cout << "This is an invalid move.\n";
					invalidMove = false;
					break;
				}
				else
				{
					targetBoard[76] = playerChar;
					invalidMove = true;
					break;
				}
			case '9':
				if (targetBoard[80] == 'X' || targetBoard[80] == 'O')
				{
					std::cout << "This is an invalid move.\n";
					invalidMove = false;
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
				invalidMove = false;
				break;
			}
		}
	}

	//undefined situations deserve an error
	else
	{
		std::cerr << "Error: The gameplay function has gone out of bounds.\n";
	}

	return targetBoard;
}

//check if a player's characters are present on all grid spaces that would make up a winning line - if so, start endgame behaviour otherwise continue game
bool endgameCheck(std::string playerName, char playerChar, std::string targetBoard, bool endgameValidity)
{
	//if draw - no moves available
	bool gridspace1 = (targetBoard[16] == 'X' || targetBoard[16] == 'O');
	bool gridspace2 = (targetBoard[20] == 'X' || targetBoard[20] == 'O');
	bool gridspace3 = (targetBoard[24] == 'X' || targetBoard[24] == 'O');
	bool gridspace4 = (targetBoard[44] == 'X' || targetBoard[44] == 'O');
	bool gridspace5 = (targetBoard[48] == 'X' || targetBoard[48] == 'O');
	bool gridspace6 = (targetBoard[52] == 'X' || targetBoard[52] == 'O');
	bool gridspace7 = (targetBoard[72] == 'X' || targetBoard[72] == 'O');
	bool gridspace8 = (targetBoard[76] == 'X' || targetBoard[76] == 'O');
	bool gridspace9 = (targetBoard[80] == 'X' || targetBoard[80] == 'O');

	if (gridspace1 &&
		gridspace2 &&
		gridspace3 &&
		gridspace4 &&
		gridspace5 &&
		gridspace6 &&
		gridspace7 &&
		gridspace8 &&
		gridspace9)
	{
		std::cout << "Draw! No more moves are available.\n";
		endgameValidity = true;
	}

	//top horizontal line
	else if(targetBoard[16] == playerChar &&
	targetBoard[20] == playerChar &&
	targetBoard[24] == playerChar)
	{
		std::cout << playerName << " wins!\n";
		endgameValidity = true;
	}

	//mid horizontal line
	else if(targetBoard[44] == playerChar &&
		targetBoard[48] == playerChar &&
		targetBoard[52] == playerChar)
	{
		std::cout << playerName << " wins!\n";
		endgameValidity = true;
	}

	//bottom horizontal line
	else if (targetBoard[72] == playerChar &&
		targetBoard[76] == playerChar &&
		targetBoard[80] == playerChar)
	{
		std::cout << playerName << " wins!\n";
		endgameValidity = true;
	}

	//left vertical line
	else if (targetBoard[16] == playerChar &&
		targetBoard[44] == playerChar &&
		targetBoard[72] == playerChar)
	{
		std::cout << playerName << " wins!\n";
		endgameValidity = true;
	}

	//mid vertical line
	else if (targetBoard[20] == playerChar &&
		targetBoard[48] == playerChar &&
		targetBoard[76] == playerChar)
	{
		std::cout << playerName << " wins!\n";
		endgameValidity = true;
	}

	//right vertical line
	else if (targetBoard[24] == playerChar &&
		targetBoard[52] == playerChar &&
		targetBoard[80] == playerChar)
	{
		std::cout << playerName << " wins!\n";
		endgameValidity = true;
	}

	//decline diagonal line
	else if (targetBoard[16] == playerChar &&
		targetBoard[48] == playerChar &&
		targetBoard[80] == playerChar)
	{
		std::cout << playerName << " wins!\n";
		endgameValidity = true;
	}

	//incline diagonal line
	else if (targetBoard[72] == playerChar &&
		targetBoard[48] == playerChar &&
		targetBoard[24] == playerChar)
	{
		std::cout << playerName << " wins!\n";
		endgameValidity = true;
	}

	//if no winning lines are present
	else
	{
		endgameValidity = false;
	}

	return endgameValidity;
}