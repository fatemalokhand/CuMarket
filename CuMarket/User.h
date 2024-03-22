#ifndef USER_H
#define USER_H

// including the necessary libraries
#include <iostream>
#include <string>

// creating a User class
class User{

    private:
        // member variables
        int rating;
        std::string name;

    public:
        // constructor
        User(std::string newName, int newRating);

        // forward declarations of member functions
        int getRating();
        void setRating(int newRating);
        std::string getName();
        void setName(std::string newName);
        bool lessThan(User& user);
        void print();
};

#endif