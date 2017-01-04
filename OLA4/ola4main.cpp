#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "BigHero.h"


int main(int argc, char **argv)
{
    BigHero h1;
    BigHero h2("Bob",1234,11,12,13);
    
    cout << ">> Testing Accessors " << endl;
    
    cout << h1.getName() << " ";
    cout << h1.getLevel() << " ";
    cout << h1.getExp() << " ";
    cout << h1.getStr() << " ";
    cout << h1.getInt() << " ";
    cout << h1.getDex() << endl;
    
    cout << h2.getName() << " ";
    cout << h2.getLevel() << " ";
    cout << h2.getExp() << " ";
    cout << h2.getStr() << " ";
    cout << h2.getInt() << " ";
    cout << h2.getDex() << endl;
    
    cout << ">> Testing Mutators " << endl;
    
    h1.setName("Phyllis");
    h2.setLevel(24);
    
    cout << h1 << endl;
    cout << h2 << endl;
    
    cout << ">> Testing Methods " << endl;
    
    h1.levelUp();
    h2.addExp(2300);
    
    cout << h1 << endl;
    cout << h2 << endl;
    
    cout << ">> Testing Operator Overloading " << endl;
    
    if( h1 > h2 ){
        cout << h1 << " is the greatest" << endl;
    }
    else{
        cout << h2 << " is the greatest" << endl;
    }
    
    if( h1 < h2 ){
        cout << h1 << " is the least" << endl;
    }
    else{
        cout << h2 << " is the least" << endl;
    }
    
    if( !(h1 == h2) ){
        cout << "Hero's Not Equal" << endl;
        h1.setExp( h2.getExp() );
        h1.setStr( h2.getStr() );
        h1.setInt( h2.getInt() );
        h1.setDex( h2.getDex() );
    }
    cout << h1 << endl;
    cout << h2 << endl;
    
    cout << ">> Testing Input Overloading " << endl;
    
    /* The file named Anna.dat contains the information to create one BigHero character */
    ifstream inFile;
    inFile.open("anna.dat");
    if(!inFile){
        cout << "Error in opening file" << endl;
        return 0;
    }
    
    BigHero h3;
    inFile >> h3;
    cout << h3 << endl;
    
    return 0;
}
