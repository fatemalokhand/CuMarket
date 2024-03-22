#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <string>

namespace cat{
    
    enum Category {computers, cars, books, music, clothing, furniture, misc};

    std::string categoryToString(Category c);

}
#endif