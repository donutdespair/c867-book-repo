//
//  BookType.h
//  book-repo
//
//  Created by carson harder-hyde on 11/11/20.
//
#pragma once
#ifndef BookType_h
#define BookType_h
#include <string>

enum BookType {UNDECIDED, FICTION, NONFICTION};

/*Parralell array pops out a string for each book type; use book type as an index*/
static const std::string bookTypeStrings[] = {UNDECIDED, FICTION, NONFICTION};

#endif /* BookType_h */
