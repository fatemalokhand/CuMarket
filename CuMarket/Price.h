#ifndef PRICE_H
#define PRICE_H

// including the necessary libraries
#include <iostream>
#include <iomanip>

// creating a Price class
class Price{

    // member variables
    private:
        double value;
        
    public:
        // constructors
        Price(double newValue);
        Price();

        // forward declarations of member functions
        double getValue();
        void setValue(double newValue);
        bool equals(Price& p);
        bool lessThan(Price& p);
        bool inRange(Price& min, Price& max);
        void print();
};

#endif