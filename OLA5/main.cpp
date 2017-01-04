/* Kate Archer
** CSCI 2170-001
** OLA5
** Due: April 15th, 2016
** The purpose of this lab is to build a Dynamically Linked List, store objects inside of the Linked List
** and allocate and deallocate the necessary memory.
*/

#include <iostream>     // For cout, cin and endl.
#include <fstream>      // For file input stream.
#include <string>       // For strings!
#include "BigHero.h"    // Includes the BigHero header file.
using namespace std;    // Using the standard namespace.

struct Node {           // Create Node struct, containing BigHero data and Node pointer next.
    BigHero data;
    Node* next;
};

int main()
{
    // DECLARATIONS
    Node* head;         // Pointer for the first node in the list.
    Node* current;      // Pointer for the current node in the list.
    Node* newNode;      // Pointer for the new node.
    ifstream inFile;    // File input stream.
    
    
    // OPEN FILE
    inFile.open("ola5party.dat");      // Open file for reading.
    if(!inFile)                        // Verify successful opening.
    {
        cout << "There was an error in processing your file." << endl << "Good-bye!";
        return 1;                      // print error message and exit if unsuccessful.
    }
    
    
    // ALLOCATING
    head = new Node;                        // Head points to new node, which is now the beginning of the linked list.
    cout << "Allocated #" << head << endl;  // Cout memory address allocated.
    inFile >> head->data;                   // Read the data into the node.
    current = head;                         // Set current pointer to the head, first item in the list.
    
    newNode = new Node;                         // Create next node.
    cout << "Allocated #" << newNode << endl;   // Cout memory address.
    inFile >> newNode->data;                    // Read in data.
    
    while(inFile)                                   // While there is still data to be read:
    {
        current->next = newNode;                    // Set the next pointer of the current node to the new node.
        current = newNode;                          // Move the current pointer ahead.
        newNode = new Node;                         // Reassign the newNode pointer to a new node.
        cout << "Allocated #" << newNode << endl;   // Cout memory address.
        inFile >> newNode->data;                    // Read in data.
    }
    
    current->next = NULL;       // Set the memory address of the current pointer (the last one) to NULL.
    
    
    // PRINTING
    if(head != NULL)                    // Walk the list to print out the data.
    {
        current = head;                 // Set current to the head (beginning of the list).
        
        while(current->next != NULL)    // While the next pinter in current is not pointing to NULL (the end of the list).
        {
            cout << current->data << endl;  // Cout data from current node, using overloaded operator.
            current = current->next;        // Move current to the next node.
        }
        cout << current->data << endl;      // Cout the data from the last node.
    }
    
    // DEALLOCATING
    if(head != NULL)                    // Walk the list to deallocate the memory.
    {
        current = head;                 // Set current to the head (beginning of the list).
        while(head->next != NULL)       // While the next pointer in the head node is not NULL (end of the list).
        {
            head = head->next;          // Move the head pointer.
            cout << "Deallocating #" << current << endl;    // Cout memory address.
            delete current;             // Delete the current pointer.
            current = head;             // Move the current pointer to the head.
        }
        
        cout << "Deallocating #" << head << endl;   // Cout memory address.
        delete head;                                // Delete the head.
        
        cout << "Deallocating #" << newNode << endl;    // Cout memory address.
        delete newNode;                                 // Delete newNode.
        
        head = NULL;       // Set all pointers to NULL, no dangling around here!
        current = NULL;
        newNode = NULL;
        
        
    }
    
    // THE END
    inFile.close(); // CLose the file.
    return 0;       // Return 0.
    
}