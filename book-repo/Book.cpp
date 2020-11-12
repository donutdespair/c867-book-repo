//
//  Book.cpp
//  book-repo
//
//  Created by carson harder-hyde on 11/11/20.
//

#include "Book.hpp"
Book::Book()//parameterless constructor - sets to default values
{
    //(pointer_name)->(variable_name)
    this->bookID = "";//an empty string is not null
    this->title = "";
    this->author = "";
    for (int i = 0; i < priceArraySize; i++) this->prices[i] = 0;//loops over array and sets default price to 0
    this->bookType = BookType::UNDECIDED;//sets default book type to undecided using value created in BookType.h
}

Book::Book(string bookID, string title, string author, double prices[], BookType bookType)//full constructor
{
    //(pointer_name)->(variable_name)
    this->bookID = bookID;//always use "this"
    this->title = title;
    this->author = author;
    for (int i = 0; i < priceArraySize; i++) this->prices[i] = this->prices[i];
    this->bookType = bookType;
}

Book::~Book(){}//destructor does nothing because nothing is created dynamically but write it anyway; always write the desctructor
//getters or accessors
string Book::getID() {return this->bookID;}
string Book::getTitle() {return this->title;}
string Book::getAuthor() {return this->author;}
double* Book::getPrices() {return this->prices;}//array name is a pointer; you don't want to return prices individually but the reference to them
BookType Book::getBookType() {return this->bookType;}

//setters or mutators; needs incoming parameter
void Book::setID(string ID) { this->bookID = ID;}
void Book::setTitle(string title) { this-> title = title;}
void Book::setAuthor(string author) { this->author = author;}
void Book::setPrices(double prices[])//set each price individually
{
    for (int i = 0; i < priceArraySize; i++) this->prices[i] = this->prices[i];
}
void Book::setBookType (BookType bt) { this->bookType = bt;}

void Book::printHeader()//print header
{
    cout << "Output format: ID|Title|Author|Prices|Type\n";//format of printout
}

void Book::print()
{
    cout << this->getID() << '\t';//tab delimited
    cout << this->getTitle() << '\t';
    cout << this->getAuthor() << '\t';
    cout << this->getPrices()[0] << ',';//grab prices individually instead of pointer
    cout << this->getPrices()[1] << ',';//comma delimeter
    cout << this->getPrices()[2] << ',';
    cout << bookTypeStrings[this->getBookType()] << '\n';//bookType to string; is an int but uses BookType.h for string
}
