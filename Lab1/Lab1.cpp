// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;


const int kiMaxNumber=100;
const int kiLowNumber = 1;
int main()
{
	bool bPlay = true;
	while (bPlay)
	{
		char cPlayagain;
		int iNumberToGuess;
		int iGuessedNumber;
		int iGuessCounter = 1;
		iNumberToGuess = rand() % kiMaxNumber + kiLowNumber;
		cout << "Im thinking of a number between "<<kiLowNumber<<" and "<<kiMaxNumber << endl << "You have 5 guesses and i will tell you if you are higher or lower" << endl;
		system("pause");
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
				if (iGuessedNumber < iNumberToGuess)
				{
					cout << "higher" << endl;
					iGuessCounter++;
				}
				if (iGuessedNumber > iNumberToGuess)
				{
					cout << "lower" << endl;
					iGuessCounter++;
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

