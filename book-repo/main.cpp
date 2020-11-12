//
//  main.cpp
//  book-repo
//
//  Created by carson harder-hyde on 11/11/20.
//

#include <iostream>
#include "Repo.hpp"
//using std::endl;

int main()
{
    //long string to parse
    const string bookData[] =
    {"NX_1,Tuna Melt Recipes of New Jersey,A. Thisguy,20,30,35,NONFICTION","Fx0_F2,Champ vs Nessie,Creepshow Creep,50,31,40,FICTION","UXU1x,Soft Pretzels Are Gross Unless Covered in Cheese or Mustard,Gritty,27,42,33,UNDECIDED", "F3-F,Wall Street Puffer Vest Zombies on the Hudson,Patagonia McSpoopy,43,58,39,FICTION", "N_W1,Ticks and You: It's Worse Than You Thought,Dr. Arachnid,28,37,20,NONFICTION"
    };
    
    const int numBooks = 5;//sets array size
    Repo repo;//creates repo using default parameterless constructor; everything set to 0
    
    for (int i = 0; i < numBooks; i++) repo.parse(bookData[i]);
    cout << "Displaying all books: " << std::endl;
    repo.printAll();
    
    for (int i = 0; i < 3; i++)
    {
    cout << "Displaying by book type: " << bookTypeStrings[i] << std::endl;
    repo.printByBookType((BookType)i);//force book type into integer; has underlying integer value
    }
    
    cout << "Displaying books with invalid IDs" << std::endl;
    repo.printInvalidIDs();
    cout << std::endl;
    
    cout << "Displaying average prices" << std::endl;
    for (int i = 0; i < numBooks; i++)
    {
    repo.printAveragePrices(repo.books[i]->getID());
    }
    cout << "Removing book with ID N_W1:" << std::endl;
    repo.removeBookByID("N_W1");
    cout << std::endl;
    
    cout << "Removing book with ID N_W1:" << std::endl;//run again to make sure removed
    repo.removeBookByID("N_W1");
    cout << std::endl;
    
    system("pause");//hold window open so destructor shows
    return 0;
}
/*notes
 
 note about pointers:
A pointer is a variable that contains a memory address, rather than containing data like most variables introduced earlier. Appending * after a data type in a variable declaration declares a pointer variable, as in int* myPtr. One might imagine that the programming language would have a type like address in addition to types like int, char, etc., but instead the language requires each pointer variable to indicate the type of data to which the address points. So valid pointer variable declarations are int* myPtr1, char* myPtr2, double* myPtr3, and even Seat* myPtr4; (where Seat is a class type); all such variables will contain memory addresses. - WGU zyBooks C 867: Scripting & Programming 9.2
 see also - https://www.cs.fsu.edu/~myers/c++/notes/pointers1.html
 
 note about npos:
 npos is a constant static member value with the greatest possible value for an element of type size_t. This value, when used as the value for a len parameter in string’s member functions, means until the end of the string. This constant is defined with a value of -1. Since size_t is an unsigned integral type, -1 is the largest possible representable value for this type. To put it simply, think of npos as no-position. As a return value, it is usually used to indicate that no matches were found in the string. Thus, if it returns true, matches were found at no positions (i.e., no matches). - https://www.educative.io/edpresso/what-is-stringnpos-in-cpp

if there's an error about unidentified "i", you probably forgot a curly bracket somewhere 
 */
