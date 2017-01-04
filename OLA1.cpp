/* Kate Archer
** CSCI 2170-001
** OLA1
** Due: February 17th, 2016
** The purpose of this lab is to take a file name inputted by the user and proces it.
** The file contains products and their pricing information.
** The user will be asked to select a function: calculating the minimum, maximum or average price 
** of the items in the file. Selected calculation will be completed, output, and the file closed.
*/

#include <iostream>			// For cin, cout, and endl.
#include <string>			// For input of file name.
#include <fstream>			// For file input and output.
#include <iomanip>			// For formatting output.

using namespace std;		// Standard variale names will be used for the aboce libraries.

										// Fuction Prototypes
char MenuSelect(); 						// Displays the menu, reads selection, and verifies selection before returning.
void FindMinPrice(ifstream& inFile);	// Finds and displays minimum price.
void FindAvgPrice(ifstream& inFile);	// Finds the average price.
void FindMaxPrice(ifstream& inFile);	// Finds the maximum price.

int main()
{
	string fileName;					// String variable for reading file name.
	ifstream inFile;					// File input stream.
	char menuSelection;					// Character selected from menu choices.
	
	cout << "Please enter a file to process: ";
	cin >> fileName;					// Prompt and read file name from the user.
	
	inFile.open(fileName.c_str());		// Opens the file after converting string input to c string.
	if (!inFile)						// Verifies successful open of the file.
	{									// If file could not be opened, program quits.
		cout << endl << "The file you entered could not be found"<< endl << "Goodbye!";
		return 1;						// Returns 1 to indicate error and location of error.
	}
	
	menuSelection = MenuSelect();		// Calls the MenuSelect function which display menu, reads
										// selection and returns to the menuSelection variable.
									
	if (menuSelection == 'A')			// Calls the FindMinPrice function if selection was A. 
		FindMinPrice(inFile);
	
	else if (menuSelection == 'B')		// Calls the FindAvgPrice function if selection was B.
		FindAvgPrice(inFile);
	
	else								// Calls the only remaining choice, FindMaxPrice.
		FindMaxPrice(inFile);
		
	cout << endl << "Thanks for shopping with us!" << endl;
	cout << "Remember to shop local!";
	
	inFile.close();						// Closes the file.
	
	return 0;							// Returns 0 for the main function, ending the program.
}

/*Function: MenuSelect
 * precondition: None.
 * postcondition: Function returns the char read from the user from the menu choices.
 */
 
 char MenuSelect()
 {
	 char choice;		// Declares character vaiarble for menu choice.
	 
	 // Diplays menu.
	 cout << endl << "What option would you like?" << endl;
	 cout << " (A) Find minimum price" << endl;
	 cout << " (B) Find average price" << endl;
	 cout << " (C) Find maximum price" << endl;
	 
	 // Reads input from user for choice.
	 cin >> choice;
	 
	 // Verifies input.
	 while (!(choice == 'A' || choice == 'B' || choice == 'C'))
	 {
		 cout << "That is not a valid choice." << endl;
		 cout << "Please enter A, B, or C." << endl;
		 cin >> choice;			// If input was invalid, it is retaken until correct.
	 }
	 
	 return choice;				// Returns choice to the main function.
 }
 
/* Function: FindMinPrice
 * precondition: The function is passed a valid input file stream, inFile.
 * postcondition: The file is processed and  minimum price displayed.
 * 					No return.
 */
  
void FindMinPrice(ifstream& inFile)
{
	float price;					// Variable for reading price.
	float min = 9999999.99; 		// Initialized the min variable for comparison.
	
	while (inFile)
	{
		inFile.ignore(100, '$');	// Ignores characters up to the $.
		inFile >> price;			// Reads float number into price.
		
		
		if (min > price)			// If price is less than the current minumum, it it reasssigned.
			min = price;
	}
	
	cout << "The minimum price is $" << fixed << setprecision(2) << min << endl; // Output results.
}

/*Function: FindAvgPrice
 * precondition: The function is passed a valid input file stream, inFile.
 * postcondition: The file is processed and average price is displayed.
 * 					No return.
 */
 
void FindAvgPrice(ifstream& inFile)
{
	float price;					// Vairable for reading price.
	float count = 0;				// Variable for counting the number of prices read.
	float priceSum = 0.0;			// Variable for summation of prices.
	float average;					// Variable for average price.
	
	inFile.ignore(100, '$');		// Ignores characters prior to $.
	inFile >> price;				// Prime read of float number into price.
	
	while (inFile)
	{
		count++;						// increment the count.
		priceSum = priceSum + price;	// Summation operation of price.
		inFile.ignore(100, '$');		// Ignores characters up to the $.
		inFile >> price;				// Reads the next float number into price.
	}
	
	average = priceSum / count;			// Calculates average price.
	
	cout << fixed << setprecision(2) << "The average price is $" << average << endl;	// Outputs formatted results.
}


/*Function: FindMaxPrice
 * precondition: The function is passed a valid input file stream, inFile.
 * postcondition: The file is processed and maximum price is displayed.
 * 					No return.
 */ 

void FindMaxPrice(ifstream& inFile)
{
	float price;					// Variable for reading price.
	float max = 0.0;				// Initialized the max variable for comparison.
	
	while (inFile)
	{
		inFile.ignore(100, '$');	// Ignores characters up to the dollar sign.
		inFile >> price;			// Reads float number into price.
		
		if (max < price)			// If the price is greater than the max it is reassigned.
			max = price;
	}
	
	cout << "The maximum price is $" << fixed << setprecision(2) << max << endl;	// Outputs formated results.
}