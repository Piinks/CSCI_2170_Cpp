/* Kate Archer
** CSCI 2170-001
** OLA3
** Due: March 25, 2016
** The purpose of this lab is to read an input file containing RPG character information
** into an array of stracts, counting how many there are, and then display a user interface that will
** allow the user to sort the characters based on a perticular attribute.
*/


#include <fstream>      // For file input.
#include <string>       // For working with string data types.
#include <iostream>     // For cin, cout, and endl.
#include <iomanip>      // For formatting the output after sorting the party information.

using namespace std;    // Using standard namespace.

struct CharacterInfo    // Struct for data type CharacterInfo
{
    string name;        // name for Character name
    float health;       // Float for health
    int experience;     // int for experience
};

                                                                    // Function Prototypes
int ReadFile(ifstream& inFile, CharacterInfo party[]);              // Function to read the file, and also return the number of charcters in the party.
void DisplayMenu();                                                 // Void function to display the menu.
void NameInsertSort(CharacterInfo party[], int partySize);          // Insertion Sort function for sorting by name.
void HealthSelectSort(CharacterInfo party[], int partySize);        // Selection Sort function for sorting by health.
void ExperienceBubbleSort(CharacterInfo party[], int partySize);    // Bubble Sort Function for sorting by experience.
void ReferenceSwap(CharacterInfo& a, CharacterInfo& b);             // Swap function - by reference.
void PointerSwap(CharacterInfo* a, CharacterInfo* b);               // Swap function - by pointer. (I wanted to practice both!)
void PrintParty(CharacterInfo party[], int partySize);              // Function to print the sorted party.


int main ()                         // MAIN FUNCTION
{
    CharacterInfo party[40];        // Declares array of CharacterInfo structs, maximu of 40.
    ifstream inFile;                // Declares inout data stream inFile.
    int partySize;                  // int for number of characters in party.
    int menuChoice;                 // int for user's menu choice.
    
    inFile.open("party.dat");       // Opens the file for reading.
    if(!inFile)                     // Verifies successsful opening of the file.
    {
        cout << "There was an error in processing your file." << endl << "Good-bye!";
        return 1;                   // If the file cannot be opened for reading, an error message is printed and the program quits.
    }
    
    partySize = ReadFile(inFile, party);        // Call the ReadFile function, which reads the data into the array and returns the party size.
    
    cout << "Your party has " << partySize << " characters." << endl << endl;   // Display party size to the user.
    
    DisplayMenu();              // Display the menu.
    
    cin >> menuChoice;          // Read in user choice.
    
    while (menuChoice != 4)     // While loop will continue until the user inputs 4 to quit.
    {
        switch (menuChoice)     // Switch statement to perform the selection.
        {
            case 1: NameInsertSort(party, partySize);       // Calls the NameInsertSort function.
                break;
            case 2: HealthSelectSort(party, partySize);     // Calls the HealthSelectSort function.
                break;
            case 3: ExperienceBubbleSort(party, partySize); // Calls the ExperienceBubbleSort function.
                break;
            default: cout << "Not a valid option, please try again." << endl << endl;
                                                            // The default statement acts as an input validation, if the user has not entered
                                                            // 4 to quit, or another valid choice, they are prompted again.
        }
        
        DisplayMenu();          // Display the menu again.
        cin >> menuChoice;      // Read in new choice.
                                // End of while loop, will reiterate or end based on user input.
    }
    
    cout << endl << "Remember, an organized party conquers all!" << endl;
    cout << "Good-bye!" << endl;         // Say farewell!
    
    inFile.close();                     // Close the input file.
    
    return 0;                           // END OF MAIN
}




/* Function: ReadFile
** precondition: The function is passed two valid reference parameters.
**                  One is a valid file input stream, the other is an array of structs.
** postcondition: The data of the file is read into the array of structs. A count is kept of the number
**                  of characters read in.
*/
int ReadFile(ifstream& inFile, CharacterInfo party[])
{
    int i = 0;                      // Initializes the index used for accessing the array.
    inFile >> party[i].name;        // Priming read of the first Character name.
    
    while (inFile)                  // While loop parses the file until the inputstream enters a fail state.
    {
        inFile >> party[i].health;          // Reads in health.
        inFile >> party[i].experience;      // Reads in experience.
        i++;                                // Increments the index identifier.
        inFile >> party[i].name;            // Reads in the next name.
    }
    
    return i;   // Returns the number in the party.
                // The number is +1 from the last index of the array due to the last iteraton of the while loop.
}

/* Function: DisplayMenu
** precondtion: None. The function receives no parameters.
** postcondition: The menu is outputted for the user.
*/
void DisplayMenu()
{
    cout << "Please select an option" << endl;                  // Prints menu and displays prompt for user.
    cout << "(1) Display characters arranged by name" << endl;
    cout << "(2) Display characters arranged by health" << endl;
    cout << "(3) Display characters arranged by experience" << endl;
    cout << "(4) Exit" << endl;
    cout << "Please enter your choice: ";                       // Input from the user will be read when control returns to the main function.
    
    return;
}

/* Function: NameInsertSort
** precondition: The function receives an array of structs and the size of the array as parameters.
** postcondition: The function will sort the array by name using the Insertion method.
**                  It will then call the PrintParty function to display the newly organized party.
*/
void NameInsertSort(CharacterInfo party[], int partySize)
{
    for(int i = 1; i < partySize; i++)            // Outer loop keeps track of the first index on the unsorted list.
    {
        CharacterInfo itemtoInsert = party[i];    // Make a copy of item to insert.
        int j = i;
        while(j > 0 && party[j-1].name > itemtoInsert.name)
        {
            party[j] = party[j-1];                // Starting at j = i, items are shifted down until the correct location
            j--;                                  // to insert is found.
        }
        party[j] = itemtoInsert;
    }
    PrintParty(party, partySize);                 // Print party after sorting.
    return;
}


/* Function: HealthSelectSort
** precondition: The function receives an array of structs and the size of the array as parameters.
** postcondition: The function will sort the array by health using the Selection method.
**                  It will then call the PrintParty function to display the newly organized party.
*/
void HealthSelectSort(CharacterInfo party[], int partySize)
{
    for(int i = partySize-1; i > 0; i--)        // Outer loops keeps track of the end index destination.
    {
        int largestIndex = 0;                   // largestIndex is the largest unsorted index value.
        for(int j = 1; j <= i; j++)             // Inner loop searches for highest value
        {
            if(party[j].health > party[largestIndex].health)
                largestIndex = j;
        }
        ReferenceSwap(party[largestIndex], party[i]);   // At the end, swap largestIndex into i.
    }
    PrintParty(party, partySize);               // Print party after sorting.
    return;
}

/* Function: ExperienceBubbleSort
** precondition: The function receives an array of structs and the size of the array as parameters.
** postcondition: The function will sort the array by experience using the Bubble method.
**                  It will then call the PrintParty function to display the newly organized party.
*/
void ExperienceBubbleSort(CharacterInfo party[], int partySize)
{
    for(int i = partySize-1; i > 0; i--)            // Outer loop keeps track of the end index destination.
    {
        for(int j = 0; j < i; j++)                  // Inner loop searches array for highest value.
        {
            if(party[j].experience > party[j+1].experience)
                PointerSwap(&party[j], &party[j+1]);    // Swaps the pair of values is the array of the left is greater than the right.
        }
    }
    PrintParty(party, partySize);                   // Print Party after sorting.
    return;
}

/* Function: ReferenceSwap
** preconditon: The funtion receives two CharacterInfo datatypes as references.
** postcondition: The function swaps the values of the two.
*/
void ReferenceSwap(CharacterInfo& a, CharacterInfo& b)
{
    CharacterInfo temp = a;     // Assign first character to a.
    a = b;                      // Assign the second character to the first.
    b = temp;                   // Assing the first character (temp) to the second.
    return;
}

/* Function: PointerSwap
** preconditon: The funtion receives two CharacterInfo datatypes as pointers.
** postcondition: The function swaps the values of the two.
*/
void PointerSwap(CharacterInfo* a, CharacterInfo* b)
{
    CharacterInfo temp = *a;    // Assign dereferenced first character to temp.
    *a = *b;                    // Assign dereferenced second chacarter to the first.
    *b = temp;                  // Assign the dereferenced character (temp) to the second.
    return;
}

/* Function: PrintParty
** preconditions: The function recives the party array and size from one of the sorting functions.
** postcondition: The party arrray of structs is outputted for th user.
*/
void PrintParty(CharacterInfo party[], int partySize)
{
    cout << endl;
    cout << left << setw(10) << "Name" << "Health" << " Experience" << endl;
    
    for (int k = 0; k < partySize; k++)             // Loop iterates through the array.
    {
        cout << left << setw(10) << party[k].name;  // Print the array formatting the output.
        cout << party[k].health << "   ";
        cout << party[k].experience << endl;
    }
    
    cout << endl;
    return;
}









