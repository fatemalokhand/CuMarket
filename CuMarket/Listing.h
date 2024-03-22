#ifndef LISTING_H
#define LISTING_H

// including the necessary libraries and header files
#include <iostream>
#include <string>
#include "Category.h"
#include "Price.h"

// creating a Listing class
class Listing{

    private:
        // member variables
        std::string userName;
        std::string itemTitle;
        std::string itemDescription;
        cat::Category itemCategory;
        Price itemPrice;

    public:
        // constructor
        Listing(std::string user, std::string title, cat::Category category, std::string description, Price& price);
        
        // forward declarations of member functions
        std::string getUserName();
        void setUserName(std::string newUserName);
        std::string getItemTitle();
        void setItemTitle(std::string newItemTitle);
        cat::Category getItemCategory();
        Price getItemPrice();
        bool lessThan(Listing& listing);
        void print();
};

#endif