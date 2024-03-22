#include <iostream>
#include <random>
#include <sstream>
#include "CuMarket.h"
#include "Tester.h"

#define NUM_EVENTS 4

using namespace std;


// void addUser(string name, int rating);
// void addListing(string userName, string title, Category category, string description, Price& price);
// void removeListing(string title);
// void removeUser(string name);

// void printUsers();
// void printListings();
// void printListingsByUser(string name);
// void printListingsByCategory(Category category);
// void printListingsByPrice(Price& min, Price& max);


// CuMarket tests
int testAddUser();   
int testAddListing(); 
int testRemoveUserListings();
int testPrintByUser();
int testPrintByCategory(); 
int testPrintByPrice();

int main(){
    int choice = -1;
    while(choice != 0 && cin.good()){
        std::cout<<endl;
        std::cout<<" 0. Exit"<<endl;
        
        std::cout<<" 1. [8 marks] Test add, remove and print Users"<<endl;

        std::cout<<" 2. [10 marks] Test add, remove and print Listings"<<endl;
        std::cout<<" 3. [4 marks] Test if remove User also removes appropriate Listings"<<endl;
        std::cout<<" 4. [4 marks] Test print Listings by User"<<endl;
        std::cout<<" 5. [4 marks] Test print Listings by Category"<<endl; 
        std::cout<<" 6. [4 marks] Test print Listings by Price"<<endl;


        std::cout<<" 7. [34 marks] Test all and get mark"<<endl<<endl;
        cin >> choice;
        std::cout<<endl;

        // clear the buffer since buffers are a pain in the butt
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (choice)
        {
            case 1: testAddUser(); break;  
            case 2: testAddListing(); break;  
            case 3: testRemoveUserListings(); break;
            case 4: testPrintByUser(); break;
            case 5: testPrintByCategory(); break;
            case 6: testPrintByPrice(); break;   
            case 7: 
                int score = 0;
                score += testAddUser();   
                score += testAddListing();
                score += testRemoveUserListings();
                score += testPrintByUser();
                score += testPrintByCategory(); 
                score += testPrintByPrice();
                std::cout << "Your score is "<<score<<" out of 34" << endl << endl;   
                break;
        }
    }
    std::cout<<"Bye!"<<endl;
    return 0;  
}


Tester tester;


int testAddUser(){
    CuMarket market;

    cout<<"Testing addUser(), removeUser, and printUsers()"<<endl<<endl;
    vector<string> names = {"Alice", "Bob", "Charlie", "Dave"};

    cout<<"Adding users"<<endl;
    for (int i = 0; i < names.size(); i++){
        market.addUser(names[i], i+2);
    }
    
    cout<<endl<<"Printing users"<<endl<<endl;
    tester.initCapture();
    market.printUsers();
    tester.endCapture();
    int points = 0;
    int error = 0;
    tester.find(names, error);
    if(error > 0){
        cout<<"Error: Users not added properly or printUsers() did not print all users"<<endl;
        return points;
    }
    cout<<"Users found, 1 point earned"<<endl;
    ++points;
    vector<string> ratings = {"2", "3", "4", "5"};
    tester.find(ratings, error);
    if(error > 0){
        cout<<"Error: Ratings not printed properly"<<endl;
    }else{
        cout<<"Ratings found, 1 point earned"<<endl;
        ++points;
    }

    cout<<"Testing for proper order"<<endl<<endl;
    tester.findInOrder(names, error); 
    if(error > 0){
        cout<<"Error: Users not printed in proper order"<<endl;
    }else{
        cout<<"Users printed in proper order, 2 points earned"<<endl;
        points+=2;
    }
    cout<<"Add users test passed"<<endl<<endl<<"Removing users"<<endl<<endl;
    vector<string> removed = {"Alice", "Bob"};
    vector<string> remaining = {"Charlie", "Dave"};

    for (int i = 0; i < names.size()-2; i++){  // remove all but last two
        market.removeUser(names[i]);
    }

    cout<<endl<<"Printing users"<<endl<<endl;
    tester.initCapture();
    market.printUsers();
    tester.endCapture();

    tester.find(remaining, error);
    if(error > 0){
        cout<<"Error: Users not removed properly or printUsers() did not print all users"<<endl;
    }else{
        cout<<"Remaining Users found, 2 points earned"<<endl;
        points+=2;
    }


    tester.confirmAbsent(removed, error);
    if(error > 0){
        cout<<"Error: Found removed Users"<<endl;
    }else{
        cout<<"Removed Users not found (test passed), 2 points earned"<<endl;
        points += 2;
    }

    cout<<"Remove users test passed"<<endl<<endl;


    cout<<"Points earned: "<<points<<"/8"<<endl<<endl;
    return points;
}

int testAddListing(){
    CuMarket market;

    cout<<"Testing addListing(), removeListing, and printListings()"<<endl<<endl;
    vector<string> names = {"Alice", "Bob", "Charlie", "Dave"};
    vector<string> titles = {"Car for sale!", "My Junk Can be your Junk!", "Computer", "Assignment Answers!"};
    vector<string> descriptions = {"It's a car", "It's junk", "It's a computer", "It's answers"};
    vector<cat::Category> categories = {cat::cars, cat::misc, cat::computers, cat::misc};
    vector<string> categoriesStr = {"cars", "misc", "computers", "misc"};
    vector<Price> prices = {Price(1000), Price(0), Price(500), Price(100)};
    vector<string> priceStr = {"$1000.00", "$0.00", "$500.00", "$100.00"};

    cout<<"Adding users"<<endl;
    for (int i = 0; i < names.size(); i++){
        market.addUser(names[i], i+2);
    }

    cout<<"Adding listings"<<endl;
    for (int i = 0; i < names.size(); i++){
        market.addListing(names[i], titles[i], categories[i], descriptions[i], prices[i]);
    }

    cout<<endl<<"Printing listings"<<endl<<endl;
    tester.initCapture();
    market.printListings();
    tester.endCapture();
    int points = 0;
    int error = 0;
    tester.find(titles, error);
    if(error > 0){
        cout<<"Error: Listings not added properly or printListings() did not print all listings"<<endl;
        return points;
    }
    ++points;
    tester.find(descriptions, error);
    if(error > 0){
        cout<<"Error: Descriptions not printed properly"<<endl;
    }else{
        cout<<"Descriptions found, 1 point earned"<<endl;
        ++points;
    }
    tester.find(categoriesStr, error);
    if(error > 0){
        cout<<"Error: Categories not printed properly"<<endl;
    }else{
        cout<<"Categories found, 1 point earned"<<endl;
        ++points;
    }
    tester.find(priceStr, error);
    if(error > 0){
        cout<<"Error: Prices not printed properly"<<endl;
    }else{
        cout<<"Prices found, 1 point earned"<<endl;
        ++points;
    }
    cout<<"Add listings test passed"<<endl<<endl<<"Removing listings"<<endl<<endl;
    vector<string> removed = {"Car for sale!", "My Junk Can be your Junk!"};
    vector<string> remaining = {"Computer", "Assignment Answers!"};

    for (int i = 0; i < names.size()-2; i++){  // remove all but last two
        market.removeListing(titles[i]);
    }

    cout<<endl<<"Printing listings"<<endl<<endl;
    tester.initCapture();
    market.printListings();
    tester.endCapture();

    tester.find(remaining, error);
    if(error > 0){
        cout<<"Error: Listings not removed properly or printListings() did not print all listings"<<endl;
    }else{
        cout<<"Remaining Listings found, 2 points earneed"<<endl;
        points += 2;
    }

    tester.confirmAbsent(removed, error);
    if(error > 0){
        cout<<"Error: Found removed Listings"<<endl;
    }else{
        cout<<"Removed Listings not found (test passed), 2 points earned"<<endl;
        points += 2;
    }

    cout<<"Remove listings test passed"<<endl<<endl;

    cout<<"Adding listing with no User"<<endl;
    Price price(100);
    market.addListing("Eve", "Should not print", cat::misc, "fake description", price);

    cout<<endl<<"Printing listings"<<endl<<endl;
    tester.initCapture();
    market.printListings();
    tester.endCapture();

    vector<string> shouldNotPrint = {"Should not print", "fake description"};

    tester.confirmAbsent(shouldNotPrint, error);
    if(error > 0){
        cout<<"Error: Found listing with no User"<<endl;
    }else{
        cout<<"Listing with no User not found (test passed)"<<endl;
        points += 2;
    }

    cout<<endl<<"Points earned: "<<points<<"/10"<<endl<<endl;

    return points;
}

int testRemoveUserListings(){
    CuMarket market;

    cout<<"Testing if remove user correctly removes listings"<<endl<<endl;
    vector<string> names = {"Alice", "Bob"};
    vector<string> titles = {"Car for sale!", "My Junk Can be your Junk!", "Computer", "Assignment Answers!"};
    vector<string> descriptions = {"It's a car", "It's junk", "It's a computer", "It's answers"};
    vector<cat::Category> categories = {cat::cars, cat::misc, cat::computers, cat::misc};
    vector<Price> prices = {Price(1000), Price(0), Price(500), Price(100)};

    cout<<"Adding users"<<endl;
    for (int i = 0; i < names.size(); i++){
        market.addUser(names[i], i+2);
    }

    cout<<"Adding listings"<<endl;
    for (int i = 0; i < titles.size(); i++){
        market.addListing(names[i%2], titles[i], categories[i], descriptions[i], prices[i]);
    }

    cout<<endl<<"Checking all Listing exist"<<endl<<endl;
    tester.initCapture();
    market.printListings();
    tester.endCapture();
    int points = 0;
    int error = 0;
    tester.find(titles, error);
    if(error > 0){
        cout<<"Error: Listings not added properly or printListings() did not print all listings - cannot complete test"<<endl;
        return points;
    }

    cout<<"Removing user Alice"<<endl;
    market.removeUser("Alice");
    cout<<endl<<"Checking for Alice's listings"<<endl<<endl;
    
    tester.initCapture();
    market.printListings();
    tester.endCapture();
    vector<string> absent = {"Computer", "Car for sale!"};
    vector<string> present = {"Assignment Answers!", "My Junk Can be your Junk!"};
    tester.confirmAbsent(absent, error);
    if(error > 0){
        cout<<"Error: Found Alice's listings"<<endl;
    }else{
        cout<<"Alice's listings not found (test passed), 2 points earned"<<endl;
        points += 2;
    }

    cout<<"Checking Bob's listings"<<endl<<endl;
    
    tester.find(present, error);
    if(error > 0){
        cout<<"Error: Bob's listings not found"<<endl;
    }else{
        cout<<"Bob's listings found (test passed), 2 points earned"<<endl;
        points += 2;
    }

    cout<<"Remove user listings test passed"<<endl<<endl;

    cout<<"Points earned: "<<points<<"/4"<<endl<<endl;

    return points;
}

int testPrintByUser(){
    CuMarket market;

    cout<<"Testing printListingsByUser()"<<endl<<endl;
    vector<string> names = {"Alice", "Bob", "Charlie"};
    vector<string> titles = {"Car for sale!", "My Junk Can be your Junk!", "Computer", "Assignment Answers!", "My other Junk", "My other other Junk"};
    vector<string> descriptions = {"It's a car", "It's junk", "It's a computer", "It's answers", "It's other junk", "It's other other junk"};
    vector<cat::Category> categories = {cat::cars, cat::misc, cat::computers, cat::misc, cat::misc, cat::misc};
    vector<Price> prices = {Price(1000), Price(0), Price(500), Price(100), Price(0), Price(0)};

    cout<<"Adding users"<<endl;
    for (int i = 0; i < names.size(); i++){
        market.addUser(names[i], i+2);
    }

    cout<<"Adding listings"<<endl;
    for (int i = 0; i < titles.size(); i++){
        market.addListing(names[i%3], titles[i], categories[i], descriptions[i], prices[i]);
    }

    cout<<endl<<"Printing listings by user"<<endl<<endl;
    tester.initCapture();
    market.printListingsByUser("Alice");
    tester.endCapture();
    int points = 0;
    int error = 0;
    vector<int> indices = {0, 3};
    tester.find(indices, titles, error);
    if(error > 0){
        cout<<"Error: Listings not printed properly"<<endl;
    }else{
        cout<<"Listings found, 2 points earned"<<endl;
        points += 2;
    }

    vector<int>absent = {1, 2, 4, 5};
    tester.confirmAbsent(absent, titles, error);
    if(error > 0){
        cout<<"Error: Found listings that should not be printed"<<endl; 
    }else{
        cout<<"Listings not found, 2 points earned"<<endl;
        points += 2;
    }

    cout<<"Print by user test passed"<<endl<<endl;

    cout<<"Points earned: "<<points<<"/4"<<endl<<endl;

    return points;
}
int testPrintByCategory(){
    CuMarket market;

    cout<<"Testing printListingsByCategory()"<<endl<<endl;
    vector<string> names = {"Alice", "Bob", "Charlie"};
    vector<string> titles = {"Car for sale!", "My Junk Can be your Junk!", "Computer", "Assignment Answers!", "My other Junk", "My other other Junk"};
    vector<string> descriptions = {"It's a car", "It's junk", "It's a computer", "It's answers", "It's other junk", "It's other other junk"};
    vector<cat::Category> categories = {cat::cars, cat::misc, cat::computers, cat::misc, cat::misc, cat::misc};
    vector<Price> prices = {Price(1000), Price(0), Price(500), Price(100), Price(0), Price(0)};

    cout<<"Adding users"<<endl;
    for (int i = 0; i < names.size(); i++){
        market.addUser(names[i], i+2);
    }

    cout<<"Adding listings"<<endl;

    for (int i = 0; i < titles.size(); i++){
        market.addListing(names[i%3], titles[i], categories[i], descriptions[i], prices[i]);
    }

    cout<<endl<<"Printing listings by category"<<endl<<endl;
    tester.initCapture();
    market.printListingsByCategory(cat::misc);
    tester.endCapture();
    int points = 0;
    int error = 0;
    vector<int> indices = {1, 3, 4, 5};
    tester.find(indices, titles, error);
    if(error > 0){
        cout<<"Error: Listings not printed properly"<<endl;
    }else{
        cout<<"Listings found, 2 points earned"<<endl;
        points += 2;
    }

    vector<int>absent = {0, 2};
    tester.confirmAbsent(absent, titles, error);
    if(error > 0){
        cout<<"Error: Found listings that should not be printed"<<endl;
    }else{
        cout<<"Listings not found, 2 points earned"<<endl;
        points += 2;
    }

    cout<<"Print by category test passed"<<endl<<endl;

    cout<<"Points earned: "<<points<<"/4"<<endl<<endl;

    return points;
}
int testPrintByPrice(){
    CuMarket market;

    cout<<"Testing printListingsByPrice()"<<endl<<endl;

    vector<string> names = {"Alice", "Bob", "Charlie"};
    vector<string> titles = {"Car for sale!", "My Junk Can be your Junk!", "Computer", "Assignment Answers!", "My other Junk", "My other other Junk"};
    vector<string> descriptions = {"It's a car", "It's junk", "It's a computer", "It's answers", "It's other junk", "It's other other junk"};
    vector<cat::Category> categories = {cat::cars, cat::misc, cat::computers, cat::misc, cat::misc, cat::misc};
    vector<Price> prices = {Price(1000), Price(50), Price(500), Price(100), Price(150), Price(200)};

    cout<<"Adding users"<<endl;
    for (int i = 0; i < names.size(); i++){
        market.addUser(names[i], i+2);
    }

    cout<<"Adding listings"<<endl;
    for (int i = 0; i < titles.size(); i++){
        market.addListing(names[i%3], titles[i], categories[i], descriptions[i], prices[i]);
    }

    cout<<endl<<"Printing listings by price"<<endl<<endl;
    tester.initCapture();
    Price min(150);
    Price max(500);
    market.printListingsByPrice(min, max);
    tester.endCapture();

    int points = 0;
    int error = 0;
    vector<int> indices = {2, 4, 5};
    tester.find(indices, titles, error);
    if(error > 0){
        cout<<"Error: Listings not printed properly"<<endl;
    }else{
        cout<<"Listings found, 2 points earned"<<endl;
        points += 2;
    }

    vector<int>absent = {0, 1, 3};
    tester.confirmAbsent(absent, titles, error);
    if(error > 0){
        cout<<"Error: Found listings that should not be printed"<<endl;
    }else{
        cout<<"Listings not found, 2 points earned"<<endl;
        points += 2;
    }

    cout<<"Print by price test passed"<<endl<<endl;

    cout<<"Points earned: "<<points<<"/4"<<endl<<endl;

    return points;


}