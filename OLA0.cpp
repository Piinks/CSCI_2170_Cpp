/* Kate Archer
 * CSCI 2170-001
 * Mr. Michael Murphy
 * February 3, 2016
 * OLA0
 * The purpose of this program is to read input from the user for an
 * amount of Fibonacci numbers. After reading the input, the numbers
 * are calculated and displayed
 */


#include <iostream>		// Includes iostream for cout, cin, and endl.

using namespace std;		// Using namespace standard.

int main ()
{ 							// Declarations:
	int displayNum;			// Inputted number of Fibonacci Numbers to display
	int fibNum1 = 0;		// First Fibonacci Number
	int fibNum2 = 1;		// Second Fibonacci Number
	
	cout << "How many Fibonacci Numbers should be displayed? ";
	cin >> displayNum;		// Requests input from user and stores in displayNum
	
	if (displayNum == 0)	// If the user enters zero, display no numbers.
	{
		cout << "No numbers for you!"<< endl;
	}
	else if (displayNum == 1)	// If the user enters 1, display fibNum1.
	{	
		cout << fibNum1;
	}
	else if (displayNum == 2)	// If the user enters 2, display fibNum1 & fibNum2
	{
		cout << fibNum1 << endl << fibNum2 << endl;
	}
	else						// For all other amounts, print the first 2 fiNums,
	{				
		cout << fibNum1 << endl << fibNum2 << endl;
		
		for (int x = 2; x < (displayNum); x++)	// Then use for loop to calculate the remaining 
		{										// fibNums and diplay on the screen.
			int newFibNum = fibNum1 + fibNum2; // Declares newFibNum for calculation.
			cout << newFibNum <<endl;
			fibNum1 = fibNum2;					// Reassigns fibNums for calculation when the
			fibNum2 = newFibNum;				// loop reiterates.
		}
	}
	
	return 0;	// Return 0 at the end of the main function.
	
}

