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
    
}
