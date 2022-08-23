#include "bits/stdc++.h"
using namespace std;

void elevator();

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
}