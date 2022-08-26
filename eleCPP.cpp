#include "bits/stdc++.h"
using namespace std;

void elevator();
void solve(int lowerRange, int upperRange, int numberOfOperations, vector<pair<char, int>> &tallyOfFloors);
void printDownTrajectory(int lowerRange, int UpperRange, vector<int> arrdownWards, queue<<pair<char, int>> upWards, queue<<pair<char, int>> downWards);
void printUpTrajectory(int lowerRange, int UpperRange, vector<int> arrupWards, queue<<pair<char, int>> upWards, queue<<pair<char, int>> downWards);

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
		cout << "Press Floor to go to(0 being the lowest, " + upperRange + " being the highest): "; cin >> floor;
		tallyOfFloors.push_back({ch, floor});  
	}

	solve(lowerRange, upperRange, numberOfOperations, tallyOfFloors);

	tallyOfFloors.clear();
}

void solve(int lowerRange, int upperRange, int numberOfOperations, vector<pair<char, int>> &tallyOfFloors)
{
	queue<pair<char,int>> upWards, downWards;

	for (auto it: tallyOfFloors)
	{
		if (it.first == 'U' || it.first == 'u')
		{
			upWards.push(it);
		}
		else
		{
			downWards.push(it);
		}
	}

	//Initially lift will start from the ground floor in current case
	//And, lift will go up by default initially as is expected from a lift

	/*
	There will be four main cases:
	a) upWards is empty --> in this case lift will go up to the topmost floor and then descend again as it will ensure that maximum people
	will be able to go down at once
	b) downWards is empty --> in this case, lift will go up like usual, stopping at floors where people are present
	c) both the queues are not empty --> in this case, lift will first go up, carrying people up and then go down accordingly
	d) if both queues empty, then lift will stay at ground floor
	*/

	if (upWards.empty() && downWards.empty())	return;	//case (d)
	else
	{
		if (upWards.empty() && (!downWards.empty()))
		{
			//case (a)
			vector<int> arrdownWards;
			
			printDownTrajectory(lowerRange, upperRange, arrDownWards, upWards, downWards);
		}
		else if (downWards.empty() && (!upWards.empty()))
		{
			//case (b)
			vector<int> arrupWards;

			printUpTrajectory(lowerRange, upperRange, arrupWards, upWards, downWards);
		}
		else if ((!downWards.empty()) && (!upWards.empty()))
		{
			//case (c)

		}
	}
}

void printDownTrajectory(int lowerRange, int UpperRange, vector<int> arrdownWards, queue<<pair<char, int>> upWards, queue<<pair<char, int>> downWards)
{
	do
	{
		while (!downWards.empty())
		{
			if (downWards.front().second == lowerRange)
			{
				arrdownWards.push_back(downWards.front().second);
				downWards.pop();
				break;
			}else{
				arrdownWards.push_back(downWards.front().second);
				downWards.pop();
			}
		}	

		if (arrdownWards.size() == 0)
		{
			break;
		}else{
			sort(arrdownWards.begin(), arrdownWards.end());
			reverse(arrdownWards.begin(), arrdownWards.end());

			int check = arrdownWards[0];
			cout << check << " ";
			for (int i = 0, n = arrdownWards.length(); i < n; ++i)
			{
				if (check != arrdownWards[i])
				{
					check = arrdownWards[i];
					cout << arrdownWards[i] <<  "\n";
				}
			}

			arrdownWards.clear();
		}
		
	}
	while (!downWards.empty());
}

void printUpTrajectory(int lowerRange, int UpperRange, vector<int> arrupWards, queue<<pair<char, int>> upWards, queue<<pair<char, int>> downWards)
{
	do
	{
		while (!upWards.empty())
		{
			if (upWards.front().second == higherRange)
			{
				arrupWards.push_back(upWards.front().second);
				upWards.pop();
				break;
			}else{
				arrupWards.push_back(upWards.front().second);
				upWards.pop();
			}
		}	

		if (arrupWards.size() == 0)
		{
			break;
		}else{
			sort(arrupWards.begin(), arrupWards.end());

			int check = arrupWards[0];
			cout << check << " ";
			for (int i = 0, n = arrupWards.length(); i < n; ++i)
			{
				if (check != arrupWards[i])
				{
					check = arrupWards[i];
					cout << arrupWards[i] <<  "\n";
				}
			}

			arrupWards.clear();
		}
		
	}
	while (!upWards.empty());
}