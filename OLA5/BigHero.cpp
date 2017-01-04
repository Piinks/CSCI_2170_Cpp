/* Kate Archer
 ** CSCI 2170-001
 ** OLA4
 ** Due: April 4, 2016
 ** The purpose of this lab is to implement a specified ADT
 ** including advanced class features such as accessors, mutators
 ** and overloaded operators.
 */

#include "BigHero.h"
#include <string>
#include <iostream>


// Default Constructor
BigHero::BigHero() {
    
    name = "Default";
    exp = 1;
    level = 1;
    Str = 1;
    Intel = 1;
    Dex = 1;
}

// Parameterized Constructor
BigHero::BigHero(string newName, int newExp, int newStr, int newIntel, int newDex) {
    
    name = newName;
    exp = newExp;
    Str = newStr;
    Intel = newIntel;
    Dex = newDex;
    level = exp/100;
}


// Accessors, return specific data member.
string BigHero::getName()const {
    return name;
}

int BigHero::getExp()const {
    return exp;
}

int BigHero::getStr()const {
    return Str;
}

int BigHero::getInt()const {
    return Intel;
}

int BigHero::getDex()const {
    return Dex;
}

int BigHero::getLevel()const {
    return level;
}


// Mutators
void BigHero::setName(string newName) {     // Sets new name.
    name = newName;
}

void BigHero::setExp(int newExp) {
    if((newExp >= 0) && (newExp <= 9000))   // Sets valid new exp, or goes unchanged.
        exp = newExp;
}

void BigHero::setStr(int newStr) {
    if((newStr >= 0) && (newStr <= 300))    // Sets valid new Str, or goes unchanged.
        Str = newStr;
}

void BigHero::setInt(int newInt) {          // Sets valid new Intel, or goes unchanged.
    if((newInt >= 0) && (newInt <= 300))
        Intel = newInt;
}

void BigHero::setDex(int newDex) {          // Sets valid new Dex, or goes unchanged.
    if((newDex >= 0) && (newDex <= 300))
        Dex = newDex;
}

void BigHero::setLevel(int newLevel) {      // Sets valid new level, or goes unchanged.
    if((newLevel >= 1) && (newLevel <= 100))
        level = newLevel;
}

bool BigHero::addExp(int amount) {          // Adds experience, and adjusts level accordingly.
    int oldLevel = level;                   // Returns true if the level has changed, false if otherwise.
    exp += amount;
    level = exp/100;
    if(level > oldLevel)
        return true;
    return false;
}

void BigHero::levelUp() {                   // Increments level up.
    level++;
}

bool BigHero::operator<(const BigHero& rhs) const { // Overloads less than operator to compare
    if(exp < rhs.exp)                               // by experience and return true or false.
        return true;
    else
        return false;
}

bool BigHero::operator>(const BigHero& rhs) const { // Overloads greater than operator to compare
    if(exp > rhs.exp)                               // by experience and return treu or false.
        return true;
    else
        return false;
}

bool BigHero::operator==(const BigHero& rhs) const {    // Overloads == operator, comparing exp, Str, Intel, and Dex.
    if((exp == rhs.exp) && (Str == rhs.Str))            // Only returns true is all are equal, false otherwise.
    {
        if((Intel == rhs.Intel) && (Dex == rhs.Dex))
            return true;
    }
    return false;
}


ostream& operator<< (ostream& os, const BigHero& rhs) { // Overloads << operator for custom output of BigHero data members.
    os << "Hero: "<< rhs.name
    << " - Level " << rhs.level << ", ("
    << rhs.Str << ',' << rhs.Intel << ',' << rhs.Dex
    << ") - Exp: " << rhs.exp;
    
    return os;
}

istream& operator>> (istream& is, BigHero& rhs) {       // Overloads >> operator for custom input of BigHero data members.
    is >> rhs.name >> rhs.exp >> rhs.Str >> rhs.Intel >> rhs.Dex;
    rhs.level = rhs.exp/100;
    return is;
}

// Destructor
BigHero::~BigHero() {}















