//
//  main.cpp
//  Sorting
//
//  Created by Katherine Archer on 3/10/16.
//  Copyright © 2016 Katherine Archer. All rights reserved.
//

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
    int array[7] = {5, 6, 3, 4, 1, 7, 8};
    int i;
    int j;
    int k;
    int largestIndex;
    
    
    // SELECTION SORT
    cout << "Selection Sort" << endl << endl;
    
    cout << "before: ";
    // Print the current order of the array.
    for (k = 0; k < 7; k++)
    {
        cout << array[k] << ' ';
    }
    
    cout << endl;
    
    // Sort the array.
    
    for (i = 6; i > 0; i--)
    {
        largestIndex = 0;
        for ( j = 1; j <= i; j++)
        {
            if (array[j] > array[largestIndex])
                largestIndex = j;
        }
        swap(array[largestIndex], array[i]);
        
    }
    cout << "after: ";
    // Print the array in the new order.
    for (k = 0; k < 7; k++)
    {
        cout << array[k] << ' ';
    }
    
    cout << endl << endl;
    
    // BUBBLE SORT
    cout << "Bubble Sort" << endl;
    int array2[9] = {6, 5, 8, 2, 1, 4, 0, 4, 6};
    
    cout << "before: ";
    for( k=0; k<9; k++)
        cout << array2[k] << ' ';
    
    cout << endl;
    for( i = 8; i > 0; i--)
    {
        for(j = 0; j <= i; j++)
        {
            if(array2[j]>array2[j+1])
                swap(array2[j], array2[j+1]);
        }
    }
    
    cout<< "after: ";
    for( k = 0; k<9; k++)
        cout << array2[k]<< ' ';
    
    cout << endl << endl;
    
    // INSERTION SORT
    cout << "Insertion Sort"<< endl;
    
    int array3[6] = {5, 8, 2, 1, 3, 0};
    
    cout << "before: ";
    for(k=0; k <6; k++)
        cout << array3[k]<< ' ';
    cout<< endl;
    
    for(i=1; i<6; i++)
    {
        int itemtoInsert = array3[i];
        j=i;
        while(j>0 && array3[j-1]>itemtoInsert)
        {
            array3[j] = array3[j-1];
            j--;
        }
        array3[j]=itemtoInsert;
    }
    
    cout << "after: ";
    for(k=0; k<6; k++)
        cout << array3[k]<< ' ';
    cout<< endl;
    
    
    
    
    return 0;
}