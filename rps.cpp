#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <array>

using namespace std;

int playerInput;
int pcInput;


int defPcIn() 
{
	srand(time(0));
	return rand() % 3 + 1;
};

float getWinRate(int winCount, int loseCount) {
	int sum = (winCount + loseCount);
	if (sum == 0) {
		return 0.0f;
	}

	return static_cast<float>(winCount) / sum * 100;
};

int main()
{
	map<short, string> rpsMap;
	
	rpsMap[1] = "ROCK";
	rpsMap[2] = "PAPER";
	rpsMap[3] = "SCISSORS";

	int winCount = 0;
	int loseCount = 0;
	int winRate;

	while(true) {
	
		cout << "Choose rock, paper or scissors.\n 1 - Rock\n 2 - Paper\n 3 - Scissors\n 0 - Exit" << endl;
		
		cin >> playerInput;
		cout << endl;

		if (playerInput >= 0 && playerInput <= rpsMap.size()) {

			
			if (playerInput == 0) {
				break;
			} 
			
			pcInput = defPcIn();
						
			cout << "Your choose: " << rpsMap[playerInput] << endl;
			cout << "PC choose: " << rpsMap[pcInput] << endl;

			if (playerInput == pcInput) {
				cout << "==================" << endl;
				cout << "It's a draw, try again" << endl;
			} else if ((playerInput == 1 && pcInput == 2) || (playerInput == 2 && pcInput == 3) || (playerInput == 3 && pcInput ==1)) {
				cout << "==================" << endl;
				cout << "You died" << endl;
				loseCount++;
			} else {
				cout << "==================" << endl;
				cout << "You won" << endl;
				winCount++;
			}

			cout << "==================" << endl;
			cout << "Wins: " << winCount << endl;
			cout << "Loses: " << loseCount << endl;
			cout << "Success rate: " << getWinRate(winCount, loseCount) << endl;
			cout << "==================" << endl;
			cout << endl;
			
		} else {
			cout << "Wrong input,  try again" << endl;
			cout << endl;
		}
	
	}

	return 0;
}

