//
//  Book.hpp
//  book-repo
//
//  Created by carson harder-hyde on 11/11/20.
//
#pragma once
#ifndef Book_hpp
#define Book_hpp
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "BookType.h"
//local file
using std::string;
using std::cout;
//using std::endl;

class Book
{
public://need to define constant
    const static int priceArraySize = 3;//the size of an array must be constant; each book has 3 prices
private://accessible to object only
    string bookID;
    string title;
    string author;
    double prices[priceArraySize];
    BookType bookType;//enum; customary to give type names upper camel case, lower camel case for instances (variables)
public://methods
    Book();//parameterless constructor - sets to default values - always include
    Book(string bookID, string title, string author, double prices[]);
};


#endif /* Book_hpp */
