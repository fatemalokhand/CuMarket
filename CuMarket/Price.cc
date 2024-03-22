// including the header file
#include "Price.h"

// constructors 
Price::Price(double newValue){
    value = newValue;
}

Price::Price(){
    value = 0;
}

// get method for value
double Price::getValue(){
    return value;
}

// set method for value
void Price::setValue(double newValue){
    value = newValue;
}

// equals method to check if the values of the two prices are equal
bool Price::equals(Price& p){
    if(this->value == p.value){
        return true;
    }
    else{
        return false;
    }
}

// lessThan method to check if the Price in question is less than p
bool Price::lessThan(Price& p){
    if(this->value < p.value){
        return true;
    }
    else{
        return false;
    }
}

// inRange method to check if the value of price falls in between the min and max
bool Price::inRange(Price& min, Price& max){
    if(this->value >= min.value && this->value <= max.value){
        return true;
    }
    else{
        return false;
    }
}

// print method to print out the price value to two decimal places 
void Price::print(){
    std::cout << "$" << std::fixed << std::setprecision(2) << this->value << std::endl;
}