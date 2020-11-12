//
//  Repo.cpp
//  book-repo
//
//  Created by carson harder-hyde on 11/11/20.
//

#include "Repo.hpp"

//using std::endl;
void Repo::parse(string bookdata)//parses each row
{
    BookType bt = UNDECIDED;//default value; initialize
    if (bookdata.at(0)== 'F') bt = FICTION;
    else if (bookdata.at(0)== 'N') bt = NONFICTION;
    
    int rhs = bookdata.find(',');//find the comma, return index
    string bID = bookdata.substr(0, rhs);//extract substring in front of comma
    
    int lhs = rhs + 1;//move past previous comma
    rhs = bookdata.find(',', lhs);
    string ttl = bookdata.substr(lhs, rhs - lhs);//book title
    
    lhs = rhs + 1;//continue
    rhs = bookdata.find(',', lhs);
    string aut = bookdata.substr(lhs, rhs - lhs);//author
    
    lhs = rhs + 1;//continue
    rhs = bookdata.find(',', lhs);
    double p1 = stod(bookdata.substr(lhs, rhs - lhs));//first price, convert double
    lhs = rhs + 1;
    rhs = bookdata.find(',', lhs);
    double p2 = stod(bookdata.substr(lhs, rhs - lhs));//second price, convert double
    lhs = rhs + 1;
    rhs = bookdata.find(',', lhs);
    double p3 = stod(bookdata.substr(lhs, rhs - lhs));//third price, convert double
    lhs = rhs + 1;
    rhs = bookdata.find(',', lhs);
    
    add(bID, ttl, aut, p1, p2, p3, bt);//prices added separately
}

//add method combines strings and creates object in repo
void Repo::add(string bookID,string title, string author, double price1, double price2, double price3, BookType bt)
{
    //prices back into an array for constructor
    double parr[3] = {price1, price2, price3};
    //make new book object; first index -1
    //be sure to use ++ prefix not postfix because starting at -1
    bookRepoArray[++lastIndex] = new Book(bookID, title, author, parr, bt);//use full constructor
}

//display all books using tab delimited output
void Repo::printAll()
{
    Book::printHeader();
    for (int i = 0; i <= Repo::lastIndex; i++)
    {
    cout << bookRepoArray[i]->getID(); cout << '\t';
    cout << bookRepoArray[i]->getAuthor(); cout << '\t';
    cout << bookRepoArray[i]->getTitle(); cout << '\t';
    cout << bookRepoArray[i]->getPrices()[0]; cout << '\t';
    cout << bookRepoArray[i]->getPrices()[1]; cout << '\t';
    cout << bookRepoArray[i]->getPrices()[2]; cout << '\t';
    cout << bookTypeStrings[bookRepoArray[i]->getBookType()] << std::endl;//index of book type enum to string
    }
}

//display books matching type
void Repo::printByBookType(BookType bt)
{
    Book::printHeader();
    for (int i = 0; i <= Repo::lastIndex; i++) {
        if (Repo::bookRepoArray[i]->getBookType() == bt) bookRepoArray[i]->print();
    }
    cout << std::endl;
}

//print books with IDs that don't contain and underscore and an "X" or "x"
void Repo::printInvalidIDs()
{
    bool any = false;
    for (int i = 0; i <= Repo::lastIndex; i++)
    {
        string bID = (bookRepoArray[i]->getID());
    }
}


