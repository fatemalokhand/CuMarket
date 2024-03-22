// including the header files
#include "Listing.h"
#include "Category.h"
#include "Price.h"

// constructor
Listing::Listing(std::string user, std::string title, cat::Category category, std::string description, Price& price){
    userName = user; 
    itemTitle = title;
    itemCategory = category;
    itemDescription = description;
    itemPrice = price;
}

// get method for user name
std::string Listing::getUserName(){
    return userName;
}

// set method for user name
void Listing::setUserName(std::string newUserName){
    userName = newUserName;
}

// get method for item title
std::string Listing::getItemTitle(){
    return itemTitle;
}

// set method for item title
void Listing::setItemTitle(std::string newItemTitle){
    itemTitle = newItemTitle;
}

cat::Category Listing::getItemCategory(){
    return itemCategory;
}

Price Listing::getItemPrice(){
    return itemPrice;
}

// lessThan method that corresponds to alphabetical order by title
bool Listing::lessThan(Listing& listing){
    if(this->itemTitle < listing.itemTitle){
        return true;
    }
    else{
        return false;
    }
}

// print method to print out all the Listing data nicely formatted
void Listing::print(){
    std::cout << "User:\t\t" << this->userName << std::endl;
    std::cout << "Title:\t\t" << this->itemTitle << std::endl;
    std::cout << "Category:\t" << cat::categoryToString(this->itemCategory) << std::endl;
    std::cout << "Description:\t" << this->itemDescription << std::endl;
    std::cout << "Price:\t\t";
    this->itemPrice.print();
    std::cout << std::endl;
}