// including the header file
#include "CuMarket.h"
#include "User.h"

// constructor 
CuMarket::CuMarket(){
    noOfUsers = 0;
    noOfListings = 0;
}

// destructor
CuMarket::~CuMarket(){

    for(int i=0; i<= noOfListings-1; i++){
        delete listings[i];
    }

    for(int i=0; i<=noOfUsers-1; i++){
        delete users[i];
    }
}

// adds the user into the array if there is space in the array
void CuMarket::addUser(std::string name, int rating){

    // checking if the users[] is empty
    if(noOfUsers == 0){

        // adding the new user into the array
        User* newUser = new User(name, rating);
        users[0] = newUser;
        noOfUsers++;
    }
    else{

        // checking if the users[] has space
        if(noOfUsers < MAX_ARRAY){

            // creating the user
            User* newUser = new User(name, rating);

            // adding newUser into the users[]
            for(int i=0; i<noOfUsers; i++){

                if(newUser->lessThan((*(users[i]))) == true){

                    for(int j = (noOfUsers - 1); j >= i; j--){

                        users[j+1] = users[j];
                        users[j] = nullptr;
                    }

                    // adding the newUser
                    users[i] = newUser;
                    noOfUsers++;
                    break;
                }
            }

            if(newUser->lessThan((*(users[noOfUsers-1]))) == false){
                users[noOfUsers] = newUser;
                noOfUsers++;
            }
        }
        else{
            // array is full
            std::cout << "The user cannot be added because the array is full." << std::endl;
        }
    }
}

void CuMarket::addListing(std::string userName, std::string title, cat::Category category, std::string description, Price& price){

    bool userExists = false;

    // looping through the users[] to check if the user with the given username exists
    for(int i=0; i<=(noOfUsers-1); i++){

        if(users[i]->getName() == userName){
            userExists = true;

            // checking if the listings[] is empty
            if(noOfListings == 0){
                // adding the new listing into the array
                Listing* newListing = new Listing(userName, title, category, description, price);
                listings[0] = newListing;
                noOfListings++;
            }
            else{

                // checking if the listings[] has space
                if(noOfListings < MAX_ARRAY){

                    // creating the listing
                    Listing* newListing = new Listing(userName, title, category, description, price);

                    // adding newListing into the listings[]
                    for(int i=0; i<noOfListings; i++){

                        if(newListing->lessThan((*(listings[i]))) == true){

                            for(int j = (noOfListings - 1); j >= i; j--){

                                listings[j+1] = listings[j];
                                listings[j] = nullptr;
                            }

                            // adding the newListing
                            listings[i] = newListing;
                            noOfListings++;
                            break;
                        }
                    }

                    if(newListing->lessThan((*(listings[noOfListings-1]))) == false){
                        listings[noOfListings] = newListing;
                        noOfListings++;
                    }
                }
                else{
                    // array is full
                    std::cout << "Cannot add the listing because the array is full." << std::endl;
                }
            }
        }
    }
    if(userExists == false){
        std::cout << "Cannot add the listing because the user does not exist." << std::endl;
    }
}

// removes the User with the given name and also removes every Listing associated with this User
void CuMarket::removeUser(std::string name){

    bool userExists = false;

    // looping through the users[]
    for(int i=0; i<noOfUsers; i++){

        if(users[i]->getName() == name){

            userExists = true;
            // removing the user
            delete users[i];
            users[i] = nullptr;

            for(int j=i; j<(noOfUsers-1); j++){

                users[j] = users[j+1];
            }

            noOfUsers--;
            break;
        }
    }

    if(userExists == false){
        std::cout << "Cannot remove the user because the user does not exist." << std::endl;
    }

    // remove all the listings associated with the user

    // looping through the listings[]
    for(int i=0; i<noOfListings; i++){

        if(listings[i]->getUserName() == name){

            removeListing(listings[i]->getItemTitle());
        }
    }
}

// removes the Listing with the given title
void CuMarket::removeListing(std::string title){

    bool listingExists = false;

    // Important: I'm assuming that the listing titles are unique

    // checking if the listings[] is empty
    if(noOfListings == 0){

        std::cout << "No listing to remove because the array is empty." << std::endl;
    }
    else{

        // looping through the listings[]
        for(int i=0; i<=noOfListings-1; i++){

            if(listings[i]->getItemTitle() == title){
                listingExists = true;
                // deleting the listing
                delete listings[i];
                listings[i] = nullptr;
                noOfListings--;

                for(int j=i+1; j<=noOfListings; j++){

                    listings[j-1] = listings[j];
                    listings[j] = nullptr;
                }

                break;
            }
        }
    }

    if(listingExists == false){
        std::cout << "Cannot remove the listing because the listing does not exist." << std::endl;
    }
}

// function to print out all the Users
void CuMarket::printUsers(){
    
    for(int i=0; i<noOfUsers; i++){

        // printing out the user
        (*(users[i])).print();
    }
}

// function to print out all the Listings
void CuMarket::printListings(){

    for(int i=0; i <= noOfListings-1; i++){

        // printing out the listing
        (*(listings[i])).print();
    }
}

// prints all Listings associated with the User with the given name.
void CuMarket::printListingsByUser(std::string name){

    bool userExists = false;

    // looping through the users[]
    for(int i=0; i<= noOfUsers-1; i++){

        if((*(users[i])).getName() == name){

            // user exists
            userExists = true;

            // looping through the listings[]
            for(int j=0; j<= noOfListings-1; j++){

                if((*(listings[j])).getUserName() == name){

                    // printing out the listing
                    (*(listings[j])).print();
                }
            }

            break;
        }
    }

    if(userExists == false){
        std::cout << "The user does not exist." << std::endl;
    }
}

// print all Listings in the given category
void CuMarket::printListingsByCategory(cat::Category category){

    for(int i=0; i <= noOfListings - 1; i++){

        if((*(listings[i])).getItemCategory() == category){

            // printing out the listing with the given category
            (*(listings[i])).print();
        }
    }
}

// print all Listings in the given price range
void CuMarket::printListingsByPrice(Price& min, Price& max){

    for(int i=0; i <= noOfListings-1; i++){

        if((*(listings[i])).getItemPrice().inRange(min, max) == true){

            // printing out the listing
            (*(listings[i])).print();
        }
    }
}