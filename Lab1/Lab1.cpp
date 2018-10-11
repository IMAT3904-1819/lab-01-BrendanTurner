// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <vector>
using namespace std;


const int kiMaxNumber=100;
const int kiLowNumber = 1;
vector<int>viGuessedNumbers;
char cPlayagain;
int iNumberToGuess;
int iGuessedNumber;
int iGuessCounter = 1;
bool bPlay = true;
int main()
{
	
	cout << "Im thinking of a number between " << kiLowNumber << " and " << kiMaxNumber << endl << "You have 5 guesses and i will tell you if you are higher or lower" << endl;
	system("pause");
	while (bPlay)
	{
		viGuessedNumbers.clear();
		iGuessCounter = 1;
		iNumberToGuess = rand() % kiMaxNumber + kiLowNumber;
		
		while (iGuessCounter <= 5)
		{
			cout << "guess number:" << iGuessCounter << endl;
			cin >> iGuessedNumber;
			if (iGuessedNumber == iNumberToGuess)
			{
				cout << "Congratulations, thats correct the answer was:" << iNumberToGuess << endl;
				iGuessCounter = 6;
				cout << "do you want to play again? Y/N" << endl;
				cin >> cPlayagain;
				cPlayagain = toupper(cPlayagain);
				if (cPlayagain != 'Y')
				{
					bPlay = false;
				}
			}
			else
			{
				for (int i = 0; i < viGuessedNumbers.size(); i++)
				{
					if (iGuessedNumber == viGuessedNumbers.at(i))
					{
						cout << "you have already guessed this number before!"<<endl<<"anyway..."<<endl;
					}
				}
				if (iGuessedNumber < iNumberToGuess)
				{
					cout << "you need to go higher" << endl;
					iGuessCounter++;
					viGuessedNumbers.push_back(iGuessedNumber);
				}
				if (iGuessedNumber > iNumberToGuess)
				{
					cout << "you need to go lower" << endl;
					iGuessCounter++;
					viGuessedNumbers.push_back(iGuessedNumber);
				}
			}
		}
		if (iGuessCounter >= 6&& iGuessedNumber != iNumberToGuess)
		{
			cout << "sorry you used all your guesses" << endl << "would you like to play again? Y/N" << endl;
			cin >> cPlayagain;
			cPlayagain = toupper(cPlayagain);
			if (cPlayagain != 'Y')
			{
				bPlay = false;
			}
		}
	}
    return 0;
}

