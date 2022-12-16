/*
 * Filename:	m5.cpp
 * Project:	    Major 3 Assignment
 * By:	    	Hoang Phuc Tran
 * Student ID:  8789102
 * Date:		February 25, 2022
 * Description: The functions in this file are used to calculates hotel bills for a meeting.
 */



#include <iostream>
#include <string>

using namespace std;


#define ERROR -1


// Prototypes
int dayToIndex(const string day);
double calculateCostOfRoom(const double arr[], int dayCheckIn, int dayCheckOut);



int main()
{
	int i = 0;
	const double arr[6] = { 127.50, 128.25, 130.50, 150, 150, 162.50 };
	double totalCost = 0;

	while (i < 4)
	{
		string name;
		string checkIn;
		string checkOut;

		cout << "Name: ";

		// Get string input from the user
		getline(cin, name);

		// if the name is not empty, prompt the day check-in
		if (name.empty() == 0)
		{
			cout << "When are they checking in: ";
			
			// Get the day check-in (day abbreviations)
			getline(cin, checkIn);

			// Convert the string of day check-in into the number correspondingly (0 - 6)
			int dayCheckIn = dayToIndex(checkIn);

			// if the dayCheckIn is valid ( 0 -> 6), prompt the day check-out
			if (dayCheckIn >= 0 && dayCheckIn <= 6)
			{
				cout << "When are they checking out: ";

				// Get the day check-out from the user
				getline(cin, checkOut);

				// Convert the string of day check-in into the number correspondingly (0 - 6)
				int dayCheckOut = dayToIndex(checkOut);

				// if the dayCheckOut is valid ( 0 -> 6), calculate the total cost of the room for the user
				if (dayCheckOut >= 0 && dayCheckOut <= 6)
				{
					/* if dayCheckin is less than the dayCheckOut and the dayCheckOut is after thursday
					and the dayCheckIn is before thursday and dayCheckIn is not the same, execute the calculateCostOfRoom function */
					if (dayCheckIn < dayCheckOut && dayCheckOut >= 4 && dayCheckIn <= 4 && dayCheckIn != dayCheckOut)
					{
						double sum = 0;

						// Add the cost of a person to the variable sum
						sum = calculateCostOfRoom(arr, dayCheckIn, dayCheckOut);

						// the total cost for four people
						totalCost = totalCost + sum;

						// Display the name and the cost of a person
						cout << "The room cost for " << name << " is " << sum << ".\n\n";

					}
					/* If the user checks in before thursday and checks out after thursday or they check in and check
						out the same day, display an error message */
					else if (dayCheckIn >= 4 && dayCheckOut <= 4 || dayCheckIn == dayCheckOut || dayCheckIn > dayCheckOut)
					{
						cout << "Error: Invalid length of stay. Skipping this person.\n\n";
					}
					// if the user checks out before thursday and checks in after thursday, display an error message.
					else
					{
						cout << "Error: This person is missing the meeting. Skipping this person.\n\n";
					}
				}
				// If the dayCheckOut is out of range, display an error message
				else
				{
					cout << "Error: Invalid check-out day. Skipping this person.\n\n";
				}
			}
			// If the dayCheckIn is out of range, display an error message
			else
			{
				cout << "Error: Invalid check-in day. Skipping this person.\n\n";
			}
		}
		// If the name is empty, display an error message
		else
		{
			cout << "Error: name missing. Skipping this person.\n\n";
		}

		i++;
	}

	cout << "The total room cost for everyone is " << totalCost << ".\n";



	return 0;
}

/*
* Function: dayToIndex()
* Description: the function converts day abbreviations that was entered (0 represents Sunday, 1 
is Monday, etc. to 6 being Saturday) into the number correspondingly or, in the case of the user not entering a valid day string, -1 indicating an error.
* Parameters: There is one string parameter (const string day)
* Returns: int: indicating the valid day that was entered. Otherwise returns ERROR (-1).
*/
int dayToIndex(const string day)
{
	if (day.compare("sun") == 0 )
	{
		return 0;
	}
	else if (day.compare("mon") == 0)
	{
		return 1;
	}
	else if (day.compare("tue") == 0)
	{
		return 2;
	}
	else if (day.compare("wed") == 0)
	{
		return 3;
	}
	else if (day.compare("thu") == 0)
	{
		return 4;
	}
	else if (day.compare("fri") == 0)
	{
		return 5;
	}
	else if (day.compare("sat") == 0)
	{
		return 6;
	}
	else
	{
		return ERROR;
	}

}


/*
* Function: calculateCostOfRoom
* Description: It calculates the total cost of the room for a person from the day check-in to the day check-out.
( Not inlcude the cost of the day check_out)
* Parameters: There are two int parameters and one double array.
* Returns: double value (the total cost of the room for a person)
*/
double calculateCostOfRoom(const double arr[], int dayCheckIn, int dayCheckOut)
{	
	int i = dayCheckIn;
	double sum = 0;

	// Loop from the day check-in to the day check_out
	for (i = dayCheckIn; i < dayCheckOut; i++)
	{
		// Add the rate of each day to the variable sum
		sum += arr[i];

	}

	return sum;
}