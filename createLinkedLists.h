// Created by Malena Lodi
#ifndef CS003AFINALPROJECT_CREATELINKEDLISTS_H
#define CS003AFINALPROJECT_CREATELINKEDLISTS_H
#include<fstream> //include libraries
#include<iostream>
#include<string>
#include "bookClass.h" //include files
#include "personClass.h"
#include "sortLinkedLists.h"
#include "print.h"
#include "theMenus.h"

void create()
{
    std::string bookFile = "book.txt", personFile = "person.txt";
    std::ifstream infileBook, infilePerson;

    infileBook.open(bookFile);
    if(infileBook.fail())
    {std::cout << "Input file opening 'book.txt' failed.\n";
        exit(1);}
    infilePerson.open(personFile);
    if(infilePerson.fail())
    {std::cout << "Input file opening 'people.txt' failed.\n";
        exit(1);}

    NodePtr head1 = nullptr, head2 = nullptr, head3 = nullptr;
    Book *a = nullptr, *b = nullptr, *c = nullptr;

//Temporary variables to hold linked list information temporarily
    int holdCode, holdAge, holdAvailable, holdRented, holdPubDate;
    std::string holdTitle, holdPublisher;

    while (!infileBook.eof()) //while not at the end of the file add information to respective linked lists. case: 'Book'
    {
        infileBook >> holdCode;
        if (holdCode >= 1001 && holdCode <= 2000) //case: ChildrenBook
        {
            NodePtr temp1 = new struct NodeBook;
            a = new ChildrenBook;

            infileBook >> holdTitle >> holdAge >> holdAvailable >> holdRented;
            a->setCode(holdCode);
            a->setTitle(holdTitle);
            a->setAge(holdAge);
            a->setAvailable(holdAvailable);
            a->setRented(holdRented);

            temp1->data = a;
            temp1->link = head1;
            head1 = temp1;
        } else if (holdCode >= 2001 && holdCode <= 3000) //case: ComputerBook
        {
            NodePtr temp2 = new struct NodeBook;
            b = new ComputerBook;

            infileBook >> holdTitle >> holdPublisher >> holdAvailable >> holdRented;
            b->setCode(holdCode);
            b->setTitle(holdTitle);
            b->setPublisher(holdPublisher);
            b->setAvailable(holdAvailable);
            b->setRented(holdRented);

            temp2->data = b;
            temp2->link = head2;
            head2 = temp2;
        } else if (holdCode >= 3001 && holdCode <= 4000) //case: Novel
        {
            NodePtr temp3 = new struct NodeBook;
            c = new Novel;

            infileBook >> holdTitle >> holdPubDate >> holdAvailable >> holdRented;
            c->setCode(holdCode);
            c->setTitle(holdTitle);
            c->setpublish_date(holdPubDate);
            c->setAvailable(holdAvailable);
            c->setRented(holdRented);

            temp3->data = c;
            temp3->link = head3;
            head3 = temp3;
        }
    }
//creating new heads for SORTED linked lists
    NodePtr sHead1 = sortBookList(head1), sHead2 = sortBookList(head2), sHead3 = sortBookList(head3);

//creating a static array to hold pointers to the heads of the sorted linked lists
    NodeBook library[3] = {*sHead1, *sHead2, *sHead3};

//Creating link lists for each person array: teacherArray and studentArray
    NodePtr2 head4 = nullptr, head5 = nullptr;

    Person *d = nullptr, *e = nullptr;

//Temporary variables to hold linked list information temporarily
    int holdId, temp0, holdCode0, holdCode1, holdCode2;
    std::string holdName;

    while (!infilePerson.eof()) //while not at the end of the file add information to linked lists. case: 'Person'
    {
        infilePerson >> holdId;
        if (holdId >= 1 && holdId <= 100) //Linked list for 'Teacher' information
        {
            NodePtr2 temp4 = new struct NodePerson;
            d = new Teacher;

            infilePerson >> holdName >> temp0;
            d->setId(holdId);
            d->setName(holdName);
            d->setCount(temp0);
            if (temp0 == 1) {
                infilePerson >> holdCode0;
                d->setTeacherCode0(holdCode0);
            } else if (temp0 == 2) {
                infilePerson >> holdCode0 >> holdCode1;
                d->setTeacherCode0(holdCode0);
                d->setTeacherCode1(holdCode1);
            } else if (temp0 == 3) {
                infilePerson >> holdCode0 >> holdCode1 >> holdCode2;
                d->setTeacherCode0(holdCode0);
                d->setTeacherCode1(holdCode1);
                d->setTeacherCode2(holdCode2);
            }

            temp4->data2 = d;
            temp4->link2 = head4;
            head4 = temp4;
        } else if (holdId >= 101 && holdId <= 300) //linked lists for 'Student' linked lists
        {
            NodePtr2 temp5 = new struct NodePerson;
            e = new Student;

            infilePerson >> holdName >> temp0;
            e->setId(holdId);
            e->setName(holdName);
            e->setCount(temp0);
            if (temp0 == 1) {
                infilePerson >> holdCode0;
                e->setStudentCode0(holdCode0);
            } else if (temp0 == 2) {
                infilePerson >> holdCode0 >> holdCode1;
                e->setStudentCode0(holdCode0);
                e->setStudentCode1(holdCode1);
            }

            temp5->data2 = e;
            temp5->link2 = head5;
            head5 = temp5;
        }
    }

//creating new linked list heads for sorted 'Person' linked lists
    NodePtr2 sHead4 = sortPersonList(head4), sHead5 = sortPersonList(head5);

//creating a static array to hold pointers to the heads of the sorted linked lists
    NodePerson person[2] = {*sHead4, *sHead5};


    bool repeat = true; //Bool statement to repeat MENU while the User does not select option 6 (to exit the program)
    do {
//Menu of program:
        int selected;
        std::cout << std::endl;
        std::cout << "------------------------" << std::endl;
        std::cout << "           Menu         " << std::endl;
        std::cout << "------------------------" << std::endl;

        std::cout << " 1.  Search a book" << std::endl;
        std::cout << " 2.  Rent a book" << std::endl;
        std::cout << " 3.  Return a book" << std::endl;
        std::cout << " 4.  Show my information" << std::endl;
        std::cout << " 5.  Show all books" << std::endl;
        std::cout << " 6.  Exit" << std::endl;
        std::cout << std::endl;
        std::cout << "Select (1~6) : ";
        std::cin >> selected;

        switch (selected) //Switch-statement with the selected number option chosen by the User
        {
            case 1:
//'Search a book'
                menuOne(&library[0], &library[1], &library[2]);
                break;
//'Rent a book'
            case 2:
                menuTwo(&library[0], &library[1], &library[2], &person[0], &person[1]);
                break;
//'Return a book'
            case 3:
                menuThree(&library[0], &library[1], &library[2], &person[0], &person[1]);
                break;
//'Show my information'
            case 4:
                menuFour(&library[0], &library[1], &library[2], &person[0], &person[1]);
                break;
//'Show all books'
            case 5:
                std::cout << "\n" << "\n";
                printChildrenBookList(&library[0]);
                std::cout << "\n";
                printComputerBookList(&library[1]);
                std::cout << "\n";
                printNovelBookList(&library[2]);
                std::cout << "\n";
                break;
//'Exit Program'
            case 6:
                std::cout << "Exiting...";
                repeat = false; //If User picks Menu #6 'repeat' will become false and the program will cease
        }
    } while (repeat); //Continue including menu while 'repeat is true'
}

#endif //CS003AFINALPROJECT_CREATELINKEDLISTS_H
