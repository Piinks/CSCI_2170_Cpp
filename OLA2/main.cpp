 /* Kate Archer
** CSCI 2170-001
** OLA2
** Due: March 2nd, 2016
** The purpose of this lab is to parse an input file containing RPG character information
** and create an output character sheet that details each character's attributes.
*/

#include <fstream>          // For file input and output.
#include <string>           // For working with string data types.
#include <iostream>         // For cin, cout, and endl.

using namespace std;        // Usung the standard namespace.

struct CharacterInfo        // Struct for datatype CharacterInfo
{
    string name;            // name for Character Name
    char classType;         // classType for class (did not use class as it is a keyword)
    int strength;           // ints for strength, intelligence, and constituion.
    int intelligence;
    int constitution;
};
                            // Function Prototype for writing output to the file.
void WriteOutput(ofstream& outFile, CharacterInfo& aCharacter);

int main()
{
    ifstream inFile;                // Declares input data stream inFile.
    ofstream outFile;               // Delcares output data stream outFile.
    CharacterInfo aCharacter;       // Declares data type CharacterInfo for aCharacter.
    
    outFile.open("character_sheet.txt");    // Opens a file for writing to.
    inFile.open("rpg.dat");                 // Opens the file for reading.
    if (!inFile)                            // Verifies successful open of the file.
    {
        cout << "There appears to be an error in reading this file."<< endl;
        return 1;                   // If the file cannot be opened for reading, and error message
                                    // is printed and the program quits.
    }
    
    inFile >> aCharacter.name;              // Priming read of the file into aCharacter.name.
    while (inFile)                          // While loop for reading the file, while the stream is valid.
    {
        inFile >> aCharacter.classType;     // Reads into aCharacter.classType.
        inFile >> aCharacter.strength;      // Reads into aCharacter.strength
        inFile >> aCharacter.intelligence;  // Reads into aCharacter.intelligence
        inFile >> aCharacter.constitution;  // Reads into aCharacter.constitution
        
        WriteOutput(outFile, aCharacter);   // The output file, outFile, and aCharacter struct
                                            // are passed to the WriteOutput function.
        
        inFile >> aCharacter.name;          // The next charcater name is read into aCharacter.name,
                                            // which it tested for the loop to reiterate.
        
    }
    
    cout << endl << "The file has finished processing." << endl;    // Provide a verification, and exit
    cout << "May you have mighty saving throws" << endl;            // statement for the user.
    cout << "and meet a bard along the way!" << endl;
    cout << "(I hear they are lovely!)" << endl << endl;
    
    inFile.close();                 // Close the input file.
    outFile.close();                // Close the output file.
    return 0;                       // Return 0, end of the program.
}


/* Function: WriteOutput
** precondtiton: The function is passed two refernece parameters.
**               The first is an open output stream, the second is a struct of type CharacterInfo.
** postcondition: The information from the struct is written to the output file after processing
**                and calcualating totals with the data.
*/

void WriteOutput(ofstream& outFile, CharacterInfo& aCharacter)
{
    if (aCharacter.classType != 'E')                        // Eliminates Enemy characters from the output.
    {
        outFile << "Name: " << aCharacter.name << endl;     // Writes the aCharacter.name to the file.
        
        switch (aCharacter.classType)                       // Switch statement determines correct class type from
        {                                                   // char aCharacter.classType and outputs it to the file.
            case 'W': outFile << "Class: Warrior" << endl;
                break;
            case 'M': outFile << "Class: Mage" << endl;
                break;
            case 'R': outFile << "Class: Rogue" << endl;
                break;
            default: break;
        }
                                                            // Output the remaining data after making proper
                                                            // calculations for statistics.
        outFile << "Health: " << (10 * aCharacter.constitution) + (3 * aCharacter.strength) << endl;
        outFile << "Mana: " << (10 * aCharacter.intelligence) + (2 * aCharacter.constitution) << endl;
        outFile << "Defense: " << (10 * aCharacter.strength) + (3 * aCharacter.intelligence) << endl;
        outFile << "-------------------" << endl;
    }
    
    return;     // This is a void function, it does not return anything, return statement is just to idicate
                // the exit of the function, returning control to the main function.
}







