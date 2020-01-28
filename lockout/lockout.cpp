#include "pch.h"
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>

namespace Print
{
	bool InitialPrint = false;
}

int UserDefinedDifficulty()
{
	int Difficulty = 0;

	std::cout << "Enter a number 1 - 5 for level difficulty or 0 to quit.\n";
	std::cout << "Difficulty: ";
	std::cin >> Difficulty;

	return Difficulty;
}

void PrintIntroduction(int Difficulty)
{
	HANDLE ConsoleHandle;
	ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Print the welcome message to the terminal with a little color added
	std::cout << "\n\nYou can't get into the emergency shelter because you are ";
	SetConsoleTextAttribute(ConsoleHandle, 14); // Yellow
	std::cout << "LEVEL " << Difficulty;
	SetConsoleTextAttribute(ConsoleHandle, 15); // White (default color)
	std::cout << " locked out.";
	std::cout << "\nSo, you'll need to enter the correct codes to get in AND the codes become more difficult as the level increases.";
	std::cout << "\nEnter each digit of the code with a space in between (e.g., 1 2 5) and then hit the enter key to see if you are correct!";
	std::cout << "\nNobody likes being stuck in a nuclear apocalypse so get to it!\n\n";
}

bool PlayGame(int Difficulty, int Max)
{
	if (Print::InitialPrint == false)
	{
		// Print the welcome message only once
		PrintIntroduction(Max);
	}

	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	// Used for testing purposes 
	std::cout << std::endl;
	std::cout << "Debug: " << CodeA << CodeB << CodeC;
	std::cout << std::endl;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	// Print the CodeSum and CodeProduct to the terminal
	std::cout << std::endl;
	std::cout << "++ There are three numbers in the code.";
	std::cout << "\n++ The codes add-up to: " << CodeSum;
	std::cout << "\n++ The codes multiply to give: " << CodeProduct << std::endl;

	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	// Check if the players guess is correct
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		if (Difficulty == Max)
		{
			if (Difficulty == 1 && Max == 1)
			{
				std::cout << "\nWOW!!!! You completed level " << Difficulty << "!!!";
				return true;
			}
			else
			{
				std::cout << "\nWOW!!!! You completed all " << Difficulty << " levels!!!";
				return true;
			}
		}

		// TODO: This if statement needs to be changed to a switch
		if (Difficulty == 1)
		{
			std::cout << "\nYea!!! Almost there...you are now at level: " << Difficulty + 1;
			Print::InitialPrint = true;
			return true;
		}
		else if (Difficulty == 2)
		{
			std::cout << "\nGetting closer...you are now at level: " << Difficulty + 1;
			Print::InitialPrint = true;
			return true;
		}
		else if (Difficulty == 3)
		{
			std::cout << "\nSo close...you are now at level: " << Difficulty + 1;
			Print::InitialPrint = true;
			return true;
		}
		else
		{
			std::cout << "\nThis is really getting hard but you are right there...you are now at level: " << Difficulty + 1;
			Print::InitialPrint = true;
			return true;
		}
	}
	else
	{
		std::cout << "\nRats!!! You can't get in the emergency shelter. Repeat level: " << Difficulty;
		Print::InitialPrint = true;
		return false;
	}
}

// TODO: main() is too large and I need to make at least two new functions 
int main()
{
	system("CLS"); // We'll start with a fresh looking console
	srand((unsigned int)time(NULL)); // Create a new random sequence based on the time of day

	int LevelDifficulty = 1;
	int MaxDifficulty = UserDefinedDifficulty();

	if (MaxDifficulty == 0)
	{
		std::cout << "\nGoodbye!!!\n";

		return 0;
	}
	else
	{
		while (LevelDifficulty <= MaxDifficulty)
		{
			bool bLevelComplete = PlayGame(LevelDifficulty, MaxDifficulty);
			std::cin.clear(); // Clears any errors
			std::cin.ignore(); // Clears the buffer

			if (bLevelComplete)
			{
				++LevelDifficulty;
			}
		}

		std::cout << "\nYou made it inside!!!\n";
	}

	return 0;
}