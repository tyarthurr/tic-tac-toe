#include <iostream>

std::string clearBoard(std::string targetBoard);
void menuCommand(bool targetValidInput, char targetMenuInput, std::string targetBoard);

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
	std::string newBoard = clearBoard(blueprintBoard);
	char menuInput = ' ';
	bool validInput = false;

	//Game experience
	std::cout << "Input the 'N' command to start a new game:\n";
	menuCommand(validInput, menuInput, newBoard);

	//Keep the game running until player decides to quit
	while (menuInput != 'E')
	{
		continue;
	}

	return 0;
}

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

void menuCommand(bool targetValidInput, char targetMenuInput, std::string targetBoard)
{
	while (targetValidInput != true)
	{
		std::cin >> targetMenuInput;
		if (targetMenuInput == 'N')
		{
			targetValidInput = true;
			std::cout << targetBoard;
		}
		else if (targetMenuInput == 'E')
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