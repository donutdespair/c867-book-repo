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
    books[++lastIndex] = new Book(bookID, title, author, parr, bt);//use full constructor
}

//display all books using tab delimited output
void Repo::printAll()
{
    Book::printHeader();
    for (int i = 0; i <= Repo::lastIndex; i++) Repo::books[i]->print();
}

//display books matching type
void Repo::printByBookType(BookType bt)
{
    Book::printHeader();
    for (int i = 0; i <= Repo::lastIndex; i++) {
        if (Repo::books[i]->getBookType() == bt) books[i]->print();
    }
    cout << std::endl;
}

//print books with IDs that don't contain and underscore and an "X" or "x"
void Repo::printInvalidIDs()
{
    bool any = false;
    //assume no ivalid IDs
    for (int i = 0; i <= Repo::lastIndex; i++)
    {
        string bID = (books[i]->getID());
        //create variable to shorten statement below
        if (bID.find('_') == string::npos || (bID.find('x') == string::npos && bID.find('X') == string::npos ))
        {
            any = true;
            //any reassigned true if if-statement met
            cout << bID << ":" << books[i]->getTitle() << std::endl;
            //prints invalid book id/email
        }
    }
    if (!any) cout << "NONE" << std::endl;
    //prints if no invalid IDs
}

void Repo::printAveragePrices(string bookID)
{
    for (int i = 0; i <= Repo::lastIndex; i++)
    {
        if (books[i]->getID()==bookID)
        {
            cout << bookID << ":";
            cout << (books[i]->getPrices()[0]+
                books[i]->getPrices()[1]+
                books[i]->getPrices()[2]/3.0) << std::endl;
    //divide by number of prices, use floating point number when getting avg
        }
    }
}

bool Repo::removeBookByID(string bookID)
//takes book id for book to be removed as param
{
    bool success = false; //assume book does not exist
    for (int i=0; i <= Repo::lastIndex; i++)
    //use lastIndex since index may change
    {
        if (books[i]->getID() == bookID)
        {
            success = true;//found book
            if (i < numBooks - 1)
            {
                Book* temp = books[i];//swaps places with last book
                books[i] = books[numBooks - 1];//moves pointer not data in memory
                books[numBooks - 1] = temp;
            }
            Repo::lastIndex--;//last book is hidden but not destroyed
        }
    }
    if (success)
    {
        cout << bookID << " removed from repository." << std::endl << std::endl;
        this->printAll();//display all books except removed books
    }
    else cout << bookID << " not found." << std::endl << std::endl;;
    return 0;
}


Repo::~Repo()
//removes objects that are dynamically allocated; the repo creates book objects dynamically and must be used to destroy
{
    cout << "Destructor called!" << std::endl << std::endl;
    for (int i=0; i < numBooks; i++)
    //size of numBooks stays the same unlike lastIndex
    {
        cout << "Destroying book# " << i + 1 << std::endl;
        delete books[i];
        books[i] = nullptr;
        //set to nullptr so it is no longer pointed at that address otherwise could crash
    }
}
