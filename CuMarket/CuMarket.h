#ifndef CUMARKET_H
#define CUMARKET_H

// including the necessary libraries and header files
#include <iostream>
#include <string>
#include "Category.h"
#include "Price.h"
#include "User.h"
#include "Listing.h"
#include "defs.h"

// creating the CuMarket class
class CuMarket{

    // member variables
    private:
        User* users[MAX_ARRAY];
        Listing* listings[MAX_ARRAY];
        int noOfUsers;
        int noOfListings;

    public:
        // constructor
        CuMarket();

        // destructor 
        ~CuMarket();

        // forward declarations of member functions
        void addUser(std::string name, int rating);
        void addListing(std::string userName, std::string title, cat::Category category, std::string description, Price& price);
        void removeUser(std::string name);
        void removeListing(std::string title);
        void printUsers();
        void printListings();
        void printListingsByUser(std::string name);
        void printListingsByCategory(cat::Category category);
        void printListingsByPrice(Price& min, Price& max);
};

#endif