//
//  Repo.hpp
//  book-repo
//
//  Created by carson harder-hyde on 11/11/20.
//
#pragma once
#include "Book.hpp"
#ifndef Repo_hpp
#define Repo_hpp
#include <stdio.h>

class Repo
{
public:
    int lastIndex = -1;
    const static int numBooks = 5;
    Book* books[numBooks]; //not decalred dynamically
    
public:
    //parse method parses set of comma delimted strings and extracts data
    void parse(string row);
    //pulls book data and creates book object in repo
    void add(string bID,
             string bTitle,
             string bAuthor,
             double bprice1,
             double bprice2,
             double bprice3,
             BookType bt);
    //once book object created, can call functions on it
    void printAll();//calls print() for each book
    void printByBookType(BookType bt);//book type passed in, print by book type
    void printInvalidIDs();//each id needs an underscore and either an uppercase "X" or lowercase "x"
    void printAveragePrices(string bookID);//prints average price for each book
    bool removeBookByID(string bookID);//find book and remove
    ~Repo();//destructor
    //if you don't write a constructor, c++ provides and sets all instances to 0
};


#endif /* Repo_hpp */
