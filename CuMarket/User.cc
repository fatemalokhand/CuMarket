// including the header file
#include "User.h"

// constructor
User::User(std::string newName, int newRating){

    name = newName;
    rating = newRating;

    if(rating < 0){
        rating = 0;
    }

    if(rating > 5){
        rating = 5;
    }
}

// get method for rating
int User::getRating(){
    return rating;
}

// set method for rating
void User::setRating(int newRating){
    rating = newRating;
}

// get method for name
std::string User::getName(){
    return name;
}

// set method for name
void User::setName(std::string newName){
    name = newName;
}

// lessThan method that corresponds to alphabetical order by name
bool User::lessThan(User& user){
    if(this->name < user.name){
        return true;
    }
    else{
        return false;
    }
}

// print method to print out the user's name and rating
void User::print(){
    std::cout << "User " << this->name << " with a rating of " << this->rating << "." << std::endl;
}