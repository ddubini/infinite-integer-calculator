#ifndef _INF_INT_H_
#define _INF_INT_H_

#include <iostream>


using namespace std;

class inf_int
{
private :
    char* digits;
    unsigned int length;
    bool thesign;   // true if positive , false if negative.
    // ex) 15311111111111111 -> digits="11111111111111351", length=17, thesign=true;
    // ex) -12345555555555 -> digits="55555555554321", length=14, thesign=false
    // you may insert additional private members here.

public :
    inf_int();               // assign 0 as a default value
    inf_int(int);
    inf_int(const char* );
    inf_int(const inf_int&); // copy constructor
    ~inf_int(); // destructor

    inf_int& operator=(const inf_int&); 
    
    friend bool operator==(const inf_int& , const inf_int&);
    friend bool operator!=(const inf_int& , const inf_int&);
    friend bool operator>(const inf_int& , const inf_int&);
    friend bool operator<(const inf_int& , const inf_int&);
    
    friend inf_int operator+(const inf_int& , const inf_int&);
    friend inf_int operator-(const inf_int& , const inf_int&);
    friend inf_int operator*(const inf_int& , const inf_int&);
    friend inf_int operator/(const inf_int& , const inf_int&);
    friend inf_int operator%(const inf_int& , const inf_int&);
    
    friend ostream& operator<<(ostream& , const inf_int&);
    // friend istream& operator>>(istream& , inf_int&);    // not required

    void Add(const char num, const unsigned int index);
    void Subtract(const char num, const unsigned int index);
    inf_int ShiftLeft(const unsigned int dec);      // used for multiplication operator => shifting digits multiplied by mult of 10 to the left  
    inf_int ShiftRight(const unsigned int dec); // used for division operator => shifting digits to the right   ex) ShiftRight(2) 5400000 = > 54000
    inf_int EraseZero(void);                    // erase any zero that is unnecessary. ex) 0000052345 => 52345 
};

#endif