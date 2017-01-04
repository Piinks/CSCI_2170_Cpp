#include <string>
#include <iostream>

using namespace std;

#ifndef BIGHERO_H
#define BIGHERO_H

class BigHero
{
public:
    /* Default constructor
     * Sets name = "Default" and all other values to 1 */
    BigHero();
    
    /* Parameterized constructor
     * Set private members to parameter values
     * NOTE:  level is initialized as the interger division of exp/100
     *        i.e. if exp = 250 -> level = 2       */
    BigHero(string newName, int newExp, int newStr, int newIntel, int newDex);
    
    /* Accessors:  each accessor will return the value of the appropriate private data member */
    string getName() const;
    int getExp() const;
    int getStr() const;
    int getInt() const;
    int getDex() const;
    int getLevel() const;
    
    /* Mutators:  each mutator will take one parameter and update the appropriate private data member
     * The domain for each mutator is listed below.
     * The mutator should protect against invalid values.
     * An Invalid entry should result in the original value remaining unchanged. */
    void setName( string newName );   // All strings are valid
    void setExp( int newExp );        // 0 <= newExp <= 9000
    void setStr( int newStr );        // 0 <= newStr <= 300
    void setInt( int newInt );        // 0 <= newInt <= 300
    void setDex( int newDex );        // 0 <= newDex <= 300
    void setLevel( int newLevel );    // 1 <= newLevel <= 100
    
    /* Helpful Member methods */
    /* addExp increases the previous amount of exp by the amount passed, and the corresponding level value
     * is recalculated to be the integer division of exp/100
     * If the previous level has increased, return 'true', otherwise 'false'
     * Preconditions: class has been initialized and exp has an initial value
     * Postconditions:  exp value is increased and level value is adjusted accordingly.  If level is increased,
     *                  return true, otherwise return false */
    bool addExp( int amount );
    
    /* levelUp increases the previous level by one.  This method can make the level go higher than 100 (no upper limit)
     * Preconidtions: class has been initialized and level has an initial value
     * Postconditions: level value is increased by one.  */
    void levelUp();
    
    /* Overloaded operators:  <, >, ==
     * Comparisons of less than (<) or equal to (>) should be done using exp as the key
     * Comparisons of equal to (==) should compare exp, Str, Intel, and
     *             Dex values (all four should be equal in compared objects) */
    bool operator<( const BigHero& rhs ) const;
    bool operator>( const BigHero& rhs ) const;
    bool operator==( const BigHero& rhs ) const;
    
    /* Output should be in the format:  "Hero: SampleNameÂ­ - Level 10, (10,20,30)Â­ - Exp: 352" */
    friend ostream& operator<< (ostream& os, const BigHero& rhs);
    
    /* Input should be in the format: "Name exp Str Intel Dex"
     * Don't forget to update level value to be equal to the integer division of exp/100 */
    friend istream& operator>> (istream& is, BigHero& rhs);
    
    ~BigHero();
    
private:
    string name;    // Hero's name
    int exp;        // Experience points (100 exp = 1 level)
    int level;      // Hero's level
    int Str;        // Hero's strength
    int Intel;      // Hero's intelligence
    int Dex;        // Hero's dexterity
};

#endif // BIGHERO_H
