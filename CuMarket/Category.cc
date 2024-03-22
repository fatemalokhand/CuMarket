#include "Category.h"

std::string cat::categoryToString(cat::Category c){
    switch(c){
        case computers: return "computers";
        case cars: return "cars";
        case books: return "books";
        case music: return "music";
        case clothing: return "clothing";
        case furniture: return "furniture";
        case misc: return "misc";
    }
    return "unknown";
}