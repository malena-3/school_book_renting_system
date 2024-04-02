//
// Created by Malena Lodi on 3/25/24.

#ifndef CS003AFINALPROJECT_SORTLINKEDLISTS_H
#define CS003AFINALPROJECT_SORTLINKEDLISTS_H

#include "bookClass.h"
#include "personClass.h"


//struct for filebook linkedlists
typedef struct NodeBook* NodePtr;
typedef struct NodePerson* NodePtr2;

struct NodeBook {class Book* data; struct NodeBook* link; };
struct NodePerson { class Person* data2; struct NodePerson* link2; };


NodePtr sortBookList(NodePtr& head);
NodePtr2 sortPersonList(NodePtr2& head);


#endif //CS003AFINALPROJECT_SORTLINKEDLISTS_H
