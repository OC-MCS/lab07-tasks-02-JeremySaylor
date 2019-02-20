#include <iostream>
#include<iomanip>
#include "Die.h"

using namespace std;
// client code to use the Die class goes here
void million(Die s, int track[]);
void display(int track[], int size);

int main()
{
	Die six(6);
	Die twelve(12);
	int size = 7;
	int track[7] = { 0,0,0,0,0,0,0 };
	int track2[13] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
	int size2 = 13;

	million(six, track);

	display(track, size);

	cout << endl << endl;

	million(twelve, track2);

	display(track2, size2);

	return 0;
}
void display(int track[], int size)
{
	double percent;

	cout << "Stats for " << (size - 1) << " sided die." << endl;
	for (int i = 1; i < size; i++)
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "Side " << (i) << ": ";
		percent = track[i] / 1000000.0;
		percent *= 100;
		cout << percent << "%" << endl;

	}
	
}


void million(Die s, int track[])
{
	int i;
	
	for (int index = 0; index < 1000000; index++)
	{
		s.roll();

		i = s.getValue();

		track[i]++;
	}

}

//void roll();     // Rolls the die
//int getSides();  // Returns the number of sides
//int getValue();  // Returns the die's value