#include "bits/stdc++.h"
using namespace std;

void elevator();
void solve(int lowerRange, int upperRange, int numberOfOperations, vector<pair<char, int>> &tallyOfFloors);

int main()
{
	cout << "Welcome to elevator project!\n";
	cout << "Do you wish to start[Y/N]?";
	string choiceOfUser; cin >> choiceOfUser;

	if (choiceOfUser == 'Y' || choiceOfUSer == 'y')	elevator();
	else	cout << "Thanks for taking your time out to try the elevator project!\n";
	
	return 0;
}

void elevator()
{
	//We will have to use a few queues, consisting of pairs of int and char
	//Here, U --> Up, D --> Down
	// If lift at G, then it will go up
	

	//While going up, if it finds that a floor higher than where the lift is at is calling for going up,
	//then stop to pick them up. Else, pick them up on the next upwards trip


	//While going down, if it finds that a floor lower than the lift wants to go down, stop there
	//else pick them up on the next down trip

	//continue this until queue becomes empty

	int range = 0;
	
	do
	{
		cout << "Enter topmost floor of building: ";
		cin >> range;

	} while (range != 0);

	int lowerRange = 0, upperRange = range;

	vector<pair<char, int>> tallyOfFloors;

	int numberOfOperations = 0;
	cout << "Enter number of floors traverse in total: ";	cin >> numberOfOperations;

	for (int i = 0; i < numberOfOperations; ++i)
	{
		char ch; int floor;
		cout << "Press U to go Up and D to go Down: "; cin >> ch;
		cout << "Press Floor to go to: "; cin >> floor;
		tallyOfFloors.push_back({ch, floor});  
	}

	solve(lowerRange, upperRange, numberOfOperations, tallyOfFloors);

	tallyOfFloors.clear();
}

void solve(int lowerRange, int upperRange, int numberOfOperations, vector<pair<char, int>> &tallyOfFloors)
{
	
}