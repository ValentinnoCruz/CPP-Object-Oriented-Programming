#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>
using namespace std;

const int totalDice = 5;

struct Dice
{
	int number;
	bool hold = false;
};

struct Scorecard 
{
	string categoryNames[13] = { "Ones", "Twos", "Threes", "Fours", "Fives", "Sixes", "3 of a Kind", "4 of a Kind", "Full House", "Small Straight", "Large Straight", "Yahtzee", "Chance" };
	bool categorySelected[13] = { false, false, false, false, false, false, false, false, false, false, false, false, false };
	int* categoryPoints[13] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
};

struct Player
{
	Dice dices[totalDice];
	Scorecard scorecard;
};

void displayRules();
void playGame();
void playTurn(Player& player);
void rollAllDice(Player& player);
void rollSpecificDice(Player& player);
void showDices(Player& player);
void rollDice(Dice& dice);
int getIndex(string choice);
bool recordScore(Player& player, string choice);
void displayCurrentScoreBoard(Player& player);
void displayUpdatedScoreBoard(Player& player);
void calculateScore(Player& player);
int totalScore(Player& player);


int main()
{
	srand(time(0));
	displayRules();
	playGame();
	return 0;
}

void displayRules()
{
	cout << "\nThe objective of Yahtzee is to get as many points as possible\n";
	cout << "by rolling five dice and getting specific combinations of the dice.\n\n";
	cout << "Each turn a player may throw the dice up to three times.\n";
	cout << "However, a player doesn't have to roll all five dice on the second and third throw of a round, \n";
	cout << "he may lockdown as many dice as he wants and only throw the \n";
	cout << "ones that don't have the numbers he's trying to get. \n\n";
}

void playGame()
{
	Player player;
	for (int i = 0; i < 13; i++)
	{
		cout << "\n" << "Turn " << (i + 1) << ":\n";
		playTurn(player);
	}
	cout << "\n" << " total score is: " << totalScore(player) << "\n";
}

void playTurn(Player& player)
{
	rollAllDice(player);
	showDices(player);
	for (int i = 0; i < 2; i++) 
	{
		string input;
		do {
			cout << "Do you want to record your score? (Y or N)  ";
			cin >> input;
		} while (!(input == "Y" || input == "y" || input == "N" || input == "n"));
		if (input == "Y" || input == "y")
		{
			break;
		}
		rollSpecificDice(player);
		showDices(player);
	}
	calculateScore(player);
	cout << "\nHere is current score card:\n";
	displayCurrentScoreBoard(player);
	string choice;
	do {
		cout << "Choose a category TAG to score dice that can select: ";
		cin >> choice;
	} while (!recordScore(player, choice));
	cout << "\nHere is updated scorecard: \n";
	displayUpdatedScoreBoard(player);
}

void showDices(Player& player)
{
	for (int i = 0; i < totalDice; i++)
	{
		cout << player.dices[i].number << "   ";
	}
	cout << "\n";
}

void rollAllDice(Player& player)
{
	for (int i = 0; i < totalDice; i++)
	{
		rollDice(player.dices[i]);
	}
}

void rollDice(Dice& dice)
{
	dice.number = 1 + rand() % 6;
	dice.hold = false;
}

void rollSpecificDice(Player& player)
{
	cout << "For each die, enter K: keep or R: reroll.\n";
	string kOrR = " ";
	for (int i = 0; i < totalDice; i++)
	{
		do 
		{
			cout << "Die " << (i + 1) << "(" << player.dices[i].number << ")  ";
			cin >> kOrR;
		} while (!(kOrR == "K" || kOrR == "k" || kOrR == "R" || kOrR == "r"));
		if (kOrR == "K" || kOrR == "k")
		{
			player.dices[i].hold = true;
		}
		else
		{
			rollDice(player.dices[i]);
		}
	}
}

int getIndex(string choice)
{
	string category[13] = { "1","2","3","4","5","6","3Kind","4Kind","FH","SS","LS","Y","C" };
	for (int i = 0; i < 13; i++)
	{
		if (choice == category[i])
		{
			return i;
		}
	}
	return -1;
}

bool recordScore(Player& player, string choice) 
{
	int i = getIndex(choice);
	if (i == -1 || player.scorecard.categorySelected[i] == true || player.scorecard.categoryPoints[i] == nullptr)
	{
		cout << "Please select a valid category TAG.\n";
		return false;
	}
	calculateScore(player);
	player.scorecard.categorySelected[i] = true;
	for (int j = 0; j < 13; j++) 
	{
		if (player.scorecard.categorySelected[j] == false) 
		{
			player.scorecard.categoryPoints[j] = nullptr;
		}
	}
	return true;
}

void displayCurrentScoreBoard(Player& player) 
{
	string tag[13] = { "1", "2", "3", "4", "5", "6", "3Kind", "4Kind", "FH", "SS", "LS", "Y", "C" };
	cout << setw(10) << "TAG" << setw(20) << "Category" << setw(10) << "Score" << setw(20) << "Status" << "\n";
	for (int i = 0; i < 13; i++) 
	{
		cout << setw(10) << tag[i] + ":" << setw(20) << player.scorecard.categoryNames[i];
		if (player.scorecard.categoryPoints[i] != nullptr)
		{
			cout << setw(10) << *(player.scorecard.categoryPoints[i]);
		}
		else
		{
			cout << setw(10) << " ";
		}
		if (player.scorecard.categorySelected[i])
		{
			cout << setw(20) << "Setected";
		}
		else if (player.scorecard.categoryPoints[i] != nullptr)
		{
			cout << setw(20) << "Can Select";
		}
		else
		{
			cout << setw(20) << "Empty";
		}
		cout << "\n";
	}
}

void displayUpdatedScoreBoard(Player& player) 
{
	cout << setw(20) << "Category" << setw(10) << "Score" << "\n";
	for (int i = 0; i < 13; i++) 
	{
		if (player.scorecard.categoryPoints[i] != nullptr)
		{
			cout << setw(20) << player.scorecard.categoryNames[i] << setw(10) << *(player.scorecard.categoryPoints[i]) << "\n";
		}
		else
		{
			cout << setw(20) << player.scorecard.categoryNames[i] << setw(10) << " " << "\n";
		}
	}
}

void calculateScore(Player& player) 
{
	int ones = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0;
	int threeKind = 0, fourKind = 0, fullHouse = 0, smallStraight = 0, largeStraight = 0, yahtzee = 0, chance = 0;

	for (int i = 0; i < 5; i++) 
	{
		if (player.dices[i].number == 1) ones++;
		if (player.dices[i].number == 2) twos++;
		if (player.dices[i].number == 3) threes++;
		if (player.dices[i].number == 4) fours++;
		if (player.dices[i].number == 5) fives++;
		if (player.dices[i].number == 6) sixes++;
	}
	if (ones >= 3 || twos >= 3 || threes >= 3 || fours >= 3 || fives >= 3 || sixes >= 3)
	{
		for (int i = 0; i < 5; i++)
		{
			threeKind += player.dices[i].number;
		}
	}
	if (ones >= 4 || twos >= 4 || threes >= 4 || fours >= 4 || fives >= 4 || sixes >= 4)
	{
		for (int i = 0; i < 5; i++)
		{
			fourKind += player.dices[i].number;
		}
	}
	if ((ones == 3 && (twos == 2 || threes == 2 || fours == 2 || fives == 2 || sixes == 2))
		|| (twos == 3 && (ones == 2 || threes == 2 || fours == 2 || fives == 2 || sixes == 2))
		|| (threes == 3 && (ones == 2 || twos == 2 || fours == 2 || fives == 2 || sixes == 2))
		|| (fours == 3 && (ones == 2 || twos == 2 || threes == 2 || fives == 2 || sixes == 2))
		|| (fives == 3 && (ones == 2 || twos == 2 || threes == 2 || fours == 2 || sixes == 2))
		|| (sixes == 3 && (ones == 2 || twos == 2 || threes == 2 || fours == 2 || fives == 2)))
	{
		fullHouse = 25;
	}
	if ((ones >= 1 && twos >= 1 && threes >= 1 && fours >= 1)
		|| (twos >= 1 && threes >= 1 && fours >= 1 && fives >= 1)
		|| (threes >= 1 && fours >= 1 && fives >= 1 && sixes >= 1))
	{
		smallStraight = 30;
	}
	if ((ones >= 1 && twos >= 1 && threes >= 1 && fours >= 1 && fives >= 1)
		|| (twos >= 1 && threes >= 1 && fours >= 1 && fives >= 1 && sixes >= 1))
	{
		largeStraight = 40;
	}
	if (ones == 5 || twos == 5 || threes == 5 || fours == 5 || fives == 5 || sixes == 5)
	{
		yahtzee = 50;
	}
	for (int i = 0; i < 5; i++)
	{
		chance += player.dices[i].number;
	}
	ones *= 1;
	twos *= 2;
	threes *= 3;
	fours *= 4;
	fives *= 5;
	sixes *= 6;

	int val[13] = { ones, twos, threes, fours, fives, sixes, threeKind, fourKind, fullHouse, smallStraight, largeStraight, yahtzee, chance };
	bool found = false;
	for (int i = 0; i < 13; i++) 
	{
		if (!player.scorecard.categorySelected[i]) 
		{
			if (val[i] > 0) 
			{
				player.scorecard.categoryPoints[i] = new int(val[i]);
				found = true;
			}
			else 
			{
				player.scorecard.categoryPoints[i] = nullptr;
			}
		}
	}
	if (!found) 
	{
		for (int i = 0; i < 13; i++) 
		{
			if (!player.scorecard.categorySelected[i]) 
			{
				player.scorecard.categoryPoints[i] = new int{ 0 };
			}
		}
	}
}

int totalScore(Player& player) 
{
	int totalScore = 0;
	for (int i = 0; i < 13; i++) 
	{
		totalScore += *(player.scorecard.categoryPoints[i]);
		if (i == 5 && totalScore >= 63) 
		{
			totalScore += 35;
		}
	}
	return totalScore;
}
