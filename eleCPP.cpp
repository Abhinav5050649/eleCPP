#include "bits/stdc++.h"
using namespace std;

void elevator();
void solve(int lowerRange, int upperRange, int numberOfOperations, vector<pair<char, int>> &tallyOfFloors);
void printDownTrajectory(int lowerRange, int UpperRange,  vector<<pair<char, int>> &upWards, vector<<pair<char, int>> &downWards);
void printUpTrajectory(int lowerRange, int UpperRange, vector<<pair<char, int>> &upWards, vector<<pair<char, int>> &downWards);
void printFloors(vector<int> &floors);

int main()
{
	cout << "Welcome to elevator project!\n";
	cout << "Do you wish to start[Y/N]?";
	string choiceOfUser; cin >> choiceOfUser;

	if (choiceOfUser == 'Y' || choiceOfUSer == 'y')	elevator();
	else	cout << "Thanks for taking your time out to try the elevator project!\n";
	
	return 0;
}

/*
// Problem to resolve:- Agar user upar ya niche ja raha hai
Case 1: down ops
	agar niche ja rahi hai lift and ek interval mein lowest floor is not gorund floor, but lets say 1, and fir 5th floor se koi 
	bula rahe hai niche jane ke liye, then fir mujhe direct fifth vale ko preference dena padega

case 2: up ops
	vice-versa of down ops

problem that I am encountering: queue mein am looking at extreme cases only. not these cases. so, we can use a vector for this

Note: Do look at kunal's suggestion
*/

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
	vector<pair<char,int>> upWards, downWards;

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
			
			printDownTrajectory(lowerRange, upperRange, upWards, downWards);
		}
		else if (downWards.empty() && (!upWards.empty()))
		{
			//case (b)

			printUpTrajectory(lowerRange, upperRange, upWards, downWards);
		}
		else if ((!downWards.empty()) && (!upWards.empty()))
		{
			//case (c)
			
		}
	}
}

void printFloors(vector<int> &floors)
{
	for (auto it: floors)
	{
		cout << it << "\n";
	}
	floors.clear();
}

void printDownTrajectory(int lowerRange, int UpperRange, vector<<pair<char, int>> &upWards, vector<<pair<char, int>> &downWards)
{
		//change this implementation --> done
		//Logic: Same as with queue implementation, but checks difference between adjacent floors and works accordingly
	vector<int> floors;
	for (int i = 0, lengthOfdownWards = downWards.size(), mid = ((upperRange - lowerRange)/2); i < lengthOfdownWards; ++i)
	{
		floors.push_back(downWards[i]);
		if (i == n - 1)
		{
			
			sort(floors.begin(), floors.end());
			reverse(floors.begin(), floors.end());
			printFloors(floors);
			break;
		}
		else if (abs(downWards[i] - downWards[i + 1]) >= mid)
		{
			sort(floors.begin(), floors.end());
			reverse(floors.begin(), floors.end());
			printFloors(floors);
		}
		downWards.clear();
	}
	return;
}

void printUpTrajectory(int lowerRange, int UpperRange, vector<<pair<char, int>> &upWards, vector<<pair<char, int>> &downWards)
{
	vector<int> floors;
	for (int i = 0, lengthOfdownWards = upWards.size(), mid = ((upperRange - lowerRange)/2); i < lengthOfupWards; ++i)
	{
		floors.push_back(upWards[i]);
		if (i == n - 1)
		{
			
			sort(floors.begin(), floors.end());
			reverse(floors.begin(), floors.end());
			printFloors(floors);
			break;
		}
		else if (abs(upWards[i] - upWards[i + 1]) >= mid)
		{
			sort(floors.begin(), floors.end());
			reverse(floors.begin(), floors.end());
			printFloors(floors);
		}
	}
	upWards.clear();
	return;
}