#ifndef CS003AFINALPROJECT_THEMENUS_H
#define CS003AFINALPROJECT_THEMENUS_H

#include "sortLinkedLists.h"
#include <iostream>


void menuOne(NodePtr head1, NodePtr head2, NodePtr head3) //menuOne: searches for the existence and information of a particular book inputted by the User
{
    int checkCode; //holds Code inputted by User
    std::string checkTitle; //holds Title inputted by User

    NodePtr ptr = nullptr;
    try //exception handling for when code and title DO NOT match
    {
//User interface to gather book code and book title:
        std::cout << "\nEnter code : ";
        std::cin >> checkCode;
        std::cout << "Enter title : ";
        std::cin >> checkTitle;
        std::cout << "\n";

        if (checkCode >= 1001 && checkCode <= 2000) //for ChildrenBook case. includes book's age:
        {
            for(ptr = head1; ptr != nullptr; ptr = ptr->link)
            {
                if(ptr->data->getCode() != checkCode && ptr->data->getTitle() == checkTitle || ptr->data->getCode() == checkCode && ptr->data->getTitle() != checkTitle) throw " "; //Throw Statement if bookCode and bookTitle DO NOT match
//output: bookTitle, bookCode, bookCategory, bookAge, bookAvailability, bookRented
                if(ptr->data->getCode() == checkCode && ptr->data->getTitle() == checkTitle)
                {
                    std::cout << checkTitle << "(" << checkCode << ")" << " exists.\n";
                    std::cout << "category : children\n";
                    std::cout << "age : " << ptr->data->getAge() << std::endl;
                    std::cout << ptr->data->getAvailable() << " available, " << ptr->data->getRented() << " rented\n";
                }}}
        else if (checkCode >= 2001 && checkCode <= 3000) //for ComputerBook case. includes book's publisher:
        {
            for(ptr = head2; ptr != nullptr; ptr = ptr->link)
            {
                if(ptr->data->getCode() != checkCode && ptr->data->getTitle() == checkTitle || ptr->data->getCode() == checkCode && ptr->data->getTitle() != checkTitle) throw " "; //Throw Statement if bookCode and bookTitle DO NOT match
//output: bookTitle, bookCode, bookCategory, bookPublisher, bookAvailability, bookRented
                if(ptr->data->getCode() == checkCode && ptr->data->getTitle() == checkTitle)
                {
                    std::cout << checkTitle << "(" << checkCode << ")" << " exists.\n";
                    std::cout << "category : computer\n";
                    std::cout << "publisher : " << ptr->data->getPublisher() << std::endl;
                    std::cout << ptr->data->getAvailable() << " available, " << ptr->data->getRented() << " rented\n";
                }}}
        else if (checkCode >= 3001 && checkCode <= 4000) //for Novel case. includes book's publish date:
        {
            for(ptr = head3; ptr != nullptr; ptr = ptr->link)
            {
                if(ptr->data->getCode() != checkCode && ptr->data->getTitle() == checkTitle || ptr->data->getCode() == checkCode && ptr->data->getTitle() != checkTitle) throw " "; //Throw Statement if bookCOde and bookTitle DO NOT match
//output: bookTitle, bookCode, bookCategory, bookPublishDate, bookAvailability, bookRented
                if(ptr->data->getCode() == checkCode && ptr->data->getTitle() == checkTitle)
                {
                    std::cout << checkTitle << "(" << checkCode << ")" << " exists.\n";
                    std::cout << "category : novel\n";
                    std::cout << "published date : " << ptr->data->getpublish_date() << std::endl;
                    std::cout << ptr->data->getAvailable() << " available, " << ptr->data->getRented() << " rented\n";
                }}}}
    catch(const char* noMatch) //catch of exception. outputs error message for User
    {
        std::cout << "Book code and Title do not match.\n";
    }
    std::cout << std::endl << std::endl;
} //END OF MENU ONE

void menuTwo(NodePtr head1, NodePtr head2, NodePtr head3, NodePtr2 head4, NodePtr2 head5) //menuTwo: rents a book chosen by the User. adding the book to the User's info and removing the book from the Book's info
{
    //'checkId' holds id inputted by User, 'holdCode' holds code inputted by User.
    int checkId, holdCode, one = 1, two = 2, three = 3;
    char answer; //'answer' is the student's answer if they want to rent a book or not.
    std::string checkTitle; //holds title inputted by User

    NodePtr ptr = nullptr;
    NodePtr2 ptr2 = nullptr;

    Person *d = nullptr, *e = nullptr;

//User interface to get User Id and Title of book
    std::cout << "\nEnter your id : ";
    std::cin >> checkId;
    try //Exception handling #1 for the chosen book being all rented out
    {
        std::cout << "Enter Book Title : ";
        std::cin >> checkTitle;
        std::cout << "\n";

        for(ptr = head1; ptr != nullptr; ptr = ptr->link)
        {
            if(ptr->data->getTitle() == checkTitle)
            {
                holdCode = ptr->data->getCode();
                if(ptr->data->getAvailable() == 0) throw "Sorry. This book is all rented out."; //throw statement for exception handling #1 if book is a ChildrenBook
            }}
        for(ptr = head2; ptr != nullptr; ptr = ptr->link)
        {
            if(ptr->data->getTitle() == checkTitle)
            {
                holdCode = ptr->data->getCode();
                if(ptr->data->getAvailable() == 0) throw "Sorry. This book is all rented out."; //throw statement for exception handling #1 if book is a ComputerBook
            }}
        for(ptr = head3; ptr != nullptr; ptr = ptr->link)
        {
            if(ptr->data->getTitle() == checkTitle)
            {
                holdCode = ptr->data->getCode();
                if(ptr->data->getAvailable() == 0) throw "Sorry. This book is all rented out."; //throw statement for exception handling #1 if book is a Novel
            }}

        if(checkId >= 1 && checkId <= 100) //User is a Teacher******
        {
            d = new Teacher;
            for(ptr2 = head4; ptr2 != nullptr; ptr2 = ptr2->link2)
            {
                if(ptr2->data2->getId() == checkId)
                {
                    try //exception handling #2 for teachers. if teacher is at max amount of rented books (three).
                    {
                        std::cout << "You are " << ptr2->data2->getName() << ". "
                             << "You rented " << ptr2->data2->getCount() << " book.\n";

                        if(ptr2->data2->getCount() == 3) throw "max"; //Teacher at limit of rented books

                        std::cout << "Do you want to rent '" << checkTitle << "' (y/n)? ";
                        std::cin >> answer;

                        if (answer == 'y') //take book from library and add it to user's rented
                        {
                            //adding book to teacher's list
                            if(ptr2->data2->getCount() == 0)
                            {
                                ptr2->data2->setCount(one);
                                ptr2->data2->setTeacherCode0(holdCode);
                            }
                            else if(ptr2->data2->getCount() == 1)
                            {
                                ptr2->data2->setCount(two);
                                ptr2->data2->setTeacherCode1(holdCode);
                            }
                            else if(ptr2->data2->getCount() == 2)
                            {
                                ptr2->data2->setCount(three);
                                ptr2->data2->setTeacherCode1(holdCode);
                            }

//decreasing the book's availability and increasing the number of books rented
                            for(ptr = head1; ptr != nullptr; ptr = ptr->link)
                            {
                                if(ptr->data->getTitle() == checkTitle)
                                {
                                    ptr->data->setAvailable(ptr->data->getAvailable() - 1);
                                    ptr->data->setRented(ptr->data->getRented() + 1);
                                }}
                            for(ptr = head2; ptr != nullptr; ptr = ptr->link)
                            {
                                if(ptr->data->getTitle() == checkTitle)
                                {
                                    ptr->data->setAvailable(ptr->data->getAvailable() - 1);
                                    ptr->data->setRented(ptr->data->getRented() + 1);
                                }}
                            for(ptr = head3; ptr != nullptr; ptr = ptr->link)
                            {
                                if(ptr->data->getTitle() == checkTitle)
                                {
                                    ptr->data->setAvailable(ptr->data->getAvailable() - 1);
                                    ptr->data->setRented(ptr->data->getRented() + 1);
                                }}
                            std::cout << "***** Rent succeed. Check your info!\n";
                        }
                    }
                    catch(const char* rent) //catch statement for exception handling #2 for teacher
                    {
                        std::cout << "You already have " << rent << " books rented.\n";
                    }}}}
        else if(checkId >= 101 && checkId <= 300) //User is a Student******
        {
            e = new Student;
            for(ptr2 = head5; ptr2 != nullptr; ptr2 = ptr2->link2)
            {
                if(ptr2->data2->getId() == checkId)
                {
                    try //try state for exception handling #2 for student. if the student is already at max amount of rented books (two)
                    {
                        std::cout << "You are " << ptr2->data2->getName() << ". "
                             << "You rented " << ptr2->data2->getCount() << " book.\n";

                        if(ptr2->data2->getCount() == 2) throw "max"; //Student at limit of rented books

                        std::cout << "Do you want to rent '" << checkTitle << "' (y/n)? ";
                        std::cin >> answer;

                        if (answer == 'y') //take book from library and add it to user's rented
                        {
                            if(ptr2->data2->getCount() == 0)
                            {
                                ptr2->data2->setCount(one);
                                ptr2->data2->setStudentCode0(holdCode);
                            }
                            else if(ptr2->data2->getCount() == 1)
                            {
                                ptr2->data2->setCount(two);
                                ptr2->data2->setStudentCode1(holdCode);
                            }
                            //decreasing the book's availability and increasing the number of books rented
                            for(ptr = head1; ptr != nullptr; ptr = ptr->link)
                            {
                                if(ptr->data->getTitle() == checkTitle)
                                {
                                    ptr->data->setAvailable(ptr->data->getAvailable() - 1);
                                    ptr->data->setRented(ptr->data->getRented() + 1);
                                }
                            }
                            for(ptr = head2; ptr != nullptr; ptr = ptr->link)
                            {
                                if(ptr->data->getTitle() == checkTitle)
                                {
                                    ptr->data->setAvailable(ptr->data->getAvailable() - 1);
                                    ptr->data->setRented(ptr->data->getRented() + 1);
                                }
                            }
                            for(ptr = head3; ptr != nullptr; ptr = ptr->link)
                            {
                                if(ptr->data->getTitle() == checkTitle)
                                {
                                    ptr->data->setAvailable(ptr->data->getAvailable() - 1);
                                    ptr->data->setRented(ptr->data->getRented() + 1);
                                }
                            }
                            std::cout << "***** Rent succeed. Check your info!" << std::endl;
                        }}
                    catch(const char* rent) //catch statement for exception handling #2 for student
                    {
                        std::cout << "You already have " << rent << " books rented.\n";
                    }}}}}
    catch(const char* book) //catch statement for exception handling #1
    {
        std::cout << book << " You will be be taken to menu...\n";
    }

    std::cout << std::endl;
} //END OF MENUTWO


void menuThree(NodePtr head1, NodePtr head2, NodePtr head3, NodePtr2 head4, NodePtr2 head5) //menuThree returns book from User. removing book from User's info and adding book to book's info
{
    int checkId, checkBookCode, zero = 0, one = 1, two = 2, three = 3, holdCode = 0;
    char answer;
    std::string bookTitle;

    NodePtr ptr = nullptr;
    NodePtr2 ptr2 = nullptr;

    Person *d = nullptr, *e = nullptr;

//User Interface to gather User ID and book code
    std::cout << "\nEnter your id    : ";
    std::cin >> checkId;
    std::cout << "Enter the book code to return : ";
    std:: cin >> checkBookCode;
    std::cout << "\n";

//for-loops to gather title of inputted book by determining position of checkBookCode
    for(ptr = head1; ptr != nullptr; ptr = ptr->link)
    {
        if(ptr->data->getCode() == checkBookCode)
        {
            bookTitle = ptr->data->getTitle();
        }
    }
    for(ptr = head2; ptr != nullptr; ptr = ptr->link)
    {
        if(ptr->data->getCode() == checkBookCode)
        {
            bookTitle = ptr->data->getTitle();
        }
    }
    for(ptr = head3; ptr != nullptr; ptr = ptr->link)
    {
        if(ptr->data->getCode() == checkBookCode)
        {
            bookTitle = ptr->data->getTitle();
        }
    }

    try //Exception handling for when 'id' does NOT return book
    {
        std::cout << "Do you want to return '" << bookTitle << "' (y/n)? ";
        std::cin >> answer;

        if(answer == 'n') throw "Book will not be returned."; //throw statement for exception handling

        if(checkId >= 1 && checkId <= 100) //User 'id' is a Teacher
        {
            d = new Teacher;
            for(ptr2 = head4; ptr2 != nullptr; ptr2 = ptr2->link2)
            {
                if(ptr2->data2->getId() == checkId)
                {
                    if (answer == 'y') //take book from Teacher and add it to Library
                    {
                        //removing book from teacher's list
                        if(ptr2->data2->getCount() == 0) { }
                        else if(ptr2->data2->getCount() == 1)
                        {
                            ptr2->data2->setCount(zero);
                            ptr2->data2->setTeacherCode0(holdCode);
                        }
                        else if(ptr2->data2->getCount() == 2)
                        {
                            ptr2->data2->setCount(one);
                            ptr2->data2->setTeacherCode1(holdCode);
                        }
                        else if(ptr2->data2->getCount() == 3)
                        {
                            ptr2->data2->setCount(two);
                            ptr2->data2->setTeacherCode2(holdCode);
                        }

                        //increasing the book's availability and decreasing the number of books rented
                        for(ptr = head1; ptr != nullptr; ptr = ptr->link)
                        {
                            if(ptr->data->getCode() == checkBookCode)
                            {
                                ptr->data->setAvailable(ptr->data->getAvailable() + 1);
                                ptr->data->setRented(ptr->data->getRented() - 1);
                            }
                        }
                        for(ptr = head2; ptr != nullptr; ptr = ptr->link)
                        {
                            if(ptr->data->getCode() == checkBookCode)
                            {
                                ptr->data->setAvailable(ptr->data->getAvailable() + 1);
                                ptr->data->setRented(ptr->data->getRented() - 1);
                            }
                        }
                        for(ptr = head3; ptr != nullptr; ptr = ptr->link)
                        {
                            if(ptr->data->getCode() == checkBookCode)
                            {
                                ptr->data->setAvailable(ptr->data->getAvailable() + 1);
                                ptr->data->setRented(ptr->data->getRented() - 1);
                            }
                        }
                        std::cout << "***** Return success. Check your info!" << std::endl;
                    }}}}
        else if(checkId >= 101 && checkId <= 300) //User 'id' is a Student
        {
            e = new Student;
            for(ptr2 = head5; ptr2 != nullptr; ptr2 = ptr2->link2)
            {
                if(ptr2->data2->getId() == checkId)
                {
                    if (answer == 'y') //take book from Student and add it to Library
                    {
                        //removing book from student's list
                        if(ptr2->data2->getCount() == 0) { }
                        else if(ptr2->data2->getCount() == 1)
                        {
                            ptr2->data2->setCount(zero);
                            ptr2->data2->setStudentCode0(holdCode);
                        }
                        else if(ptr2->data2->getCount() == 2)
                        {
                            ptr2->data2->setCount(one);
                            ptr2->data2->setStudentCode1(holdCode);
                        }

                        //increasing the book's availability and decreasing the number of books rented
                        for(ptr = head1; ptr != nullptr; ptr = ptr->link)
                        {
                            if(ptr->data->getCode() == checkBookCode)
                            {
                                ptr->data->setAvailable(ptr->data->getAvailable() + 1);
                                ptr->data->setRented(ptr->data->getRented() - 1);
                            }
                        }
                        for(ptr = head2; ptr != nullptr; ptr = ptr->link)
                        {
                            if(ptr->data->getCode() == checkBookCode)
                            {
                                ptr->data->setAvailable(ptr->data->getAvailable() + 1);
                                ptr->data->setRented(ptr->data->getRented() - 1);
                            }
                        }
                        for(ptr = head3; ptr != nullptr; ptr = ptr->link)
                        {
                            if(ptr->data->getCode() == checkBookCode)
                            {
                                ptr->data->setAvailable(ptr->data->getAvailable() + 1);
                                ptr->data->setRented(ptr->data->getRented() - 1);
                            }
                        }
                        std::cout << "***** Return success. Check your info!" << std::endl;
                    }}}}}
    catch(const char* e) //catch statement for Exception handling. outputs message for user.
    {
        std::cout << e << "Returning to menu...\n";
    }

} //END OF MENUTHREE

void menuFour(NodePtr head1, NodePtr head2, NodePtr head3, NodePtr2 head4, NodePtr2 head5) //menuFour: shows User their information
{
    int checkId; //holds ID inputted by User
    std::string checkName; //holds Name inputted by User

    NodePtr ptr = nullptr;
    NodePtr2 ptr2 = nullptr;

//User Interface to gather User id and User name
    std::cout << "\nEnter your id : ";
    std::cin >> checkId;
    std::cout << "Enter your name : ";
    std::cin >> checkName;
    std:: cout << "\n";

    if(checkId >= 1 && checkId <= 100) //User is a Teacher. Output their particular Book information
    {
        for(ptr2 = head4; ptr2 != nullptr; ptr2 = ptr2->link2)
        {
            if(ptr2->data2->getId() == checkId && ptr2->data2->getName() == checkName)
            {
                int rented;
                int bookCode1, bookCode2, bookCode3; //BookCodes hold the codes of the books each Teacher has rented

                rented = ptr2->data2->getCount();
                std::cout << "You rented " << rented << " books." << std::endl;

                if(ptr2->data2->getCount() == 0) { }
                else if(ptr2->data2->getCount() == 1)
                {
                    bookCode1 = ptr2->data2->getTeacherCode0();
                }
                else if(ptr2->data2->getCount() == 2)
                {
                    bookCode1 = ptr2->data2->getTeacherCode0();
                    bookCode2 = ptr2->data2->getTeacherCode1();
                }
                else if(ptr2->data2->getCount() == 3)
                {
                    bookCode1 = ptr2->data2->getTeacherCode0();
                    bookCode2 = ptr2->data2->getTeacherCode1();
                    bookCode3 = ptr2->data2->getTeacherCode2();
                }

                for(ptr = head1; ptr != nullptr; ptr = ptr->link) //Outputs for 'ChildrenBook' linked list
                {
                    if(ptr->data->getCode() == bookCode1)
                    {
                        std::cout << "* " << ptr->data->getTitle() << "(" << bookCode1 << ") - age " << ptr->data->getAge() << std::endl;
                    }
                    if(ptr->data->getCode() == bookCode2)
                    {
                        std::cout << "* " << ptr->data->getTitle() << "(" << bookCode2 << ") - age " << ptr->data->getAge() << std::endl;
                    }
                    if(ptr->data->getCode() == bookCode3)
                    {
                        std::cout << "* " << ptr->data->getTitle() << "(" << bookCode3 << ") - age " << ptr->data->getAge() << std::endl;
                    }
                }
                for(ptr = head2; ptr != nullptr; ptr = ptr->link) //Outputs for 'ComputerBook' linked list
                {
                    if(ptr->data->getCode() == bookCode1)
                    {
                        std:: cout << "* " << ptr->data->getTitle() << "(" << bookCode1 << ") - publisher " << ptr->data->getPublisher() << std::endl;
                    }
                    if(ptr->data->getCode() == bookCode2)
                    {
                        std::cout << "* " << ptr->data->getTitle() << "(" << bookCode2 << ") - publisher " << ptr->data->getPublisher() << std::endl;
                    }
                    if(ptr->data->getCode() == bookCode3)
                    {
                        std::cout << "* " << ptr->data->getTitle() << "(" << bookCode3 << ") - publisher " << ptr->data->getPublisher() << std::endl;
                    }
                }
                for(ptr = head3; ptr != nullptr; ptr = ptr->link) //Outputs for 'Novel' linked list
                {
                    if(ptr->data->getCode() == bookCode1)
                    {
                        std::cout << "* " << ptr->data->getTitle() << "(" << bookCode1 << ") - publish date " << ptr->data->getpublish_date() << std::endl;
                    }
                    if(ptr->data->getCode() == bookCode2)
                    {
                        std::cout << "* " << ptr->data->getTitle() << "(" << bookCode2 << ") - publish date " << ptr->data->getpublish_date() << std::endl;
                    }
                    if(ptr->data->getCode() == bookCode3)
                    {
                        std::cout << "* " << ptr->data->getTitle() << "(" << bookCode3 << ") - publish date " << ptr->data->getpublish_date() << std::endl;
                    }}}}}
    else if(checkId >= 101 && checkId <= 300) //User is a Student. Ouput their particular book information
    {
        for(ptr2 = head5; ptr2 != nullptr; ptr2 = ptr2->link2)
        {
            if(ptr2->data2->getId() == checkId && ptr2->data2->getName() == checkName)
            {
                int rented, bookCode1, bookCode2;

                rented = ptr2->data2->getCount();
                std::cout << "You rented " << rented << " books." << std::endl;

                if(ptr2->data2->getCount() == 0) { }
                else if(ptr2->data2->getCount() == 1)
                {
                    bookCode1 = ptr2->data2->getStudentCode0();
                }
                else if(ptr2->data2->getCount() == 2)
                {
                    bookCode1 = ptr2->data2->getStudentCode0();
                    bookCode2 = ptr2->data2->getStudentCode1();
                }

                for(ptr = head1; ptr != nullptr; ptr = ptr->link) //Outputs for 'ChildrenBook' linked list
                {
                    if(ptr->data->getCode() == bookCode1)
                    {
                        std::cout << "* " << ptr->data->getTitle() << "(" << bookCode1 << ") - age " << ptr->data->getAge() << std::endl;
                    }
                    if(ptr->data->getCode() == bookCode2)
                    {
                        std::cout << "* " << ptr->data->getTitle() << "(" << bookCode2 << ") - age " << ptr->data->getAge() << std::endl;
                    }
                }
                for(ptr = head2; ptr != nullptr; ptr = ptr->link) //Outputs for 'ComputerBook' linked list
                {
                    if(ptr->data->getCode() == bookCode1)
                    {
                        std::cout << "* " << ptr->data->getTitle() << "(" << bookCode1 << ") - publisher " << ptr->data->getPublisher() << std::endl;
                    }
                    if(ptr->data->getCode() == bookCode2)
                    {
                        std::cout << "* " << ptr->data->getTitle() << "(" << bookCode2 << ") - publisher " << ptr->data->getPublisher() << std::endl;
                    }
                }
                for(ptr = head3; ptr != nullptr; ptr = ptr->link) //Outputs for 'Novel' linked list
                {
                    if(ptr->data->getCode() == bookCode1)
                    {
                        std::cout << "* " << ptr->data->getTitle() << "(" << bookCode1 << ") - publish date " << ptr->data->getpublish_date() << std::endl;
                    }
                    if(ptr->data->getCode() == bookCode2)
                    {
                        std::cout << "* " << ptr->data->getTitle() << "(" << bookCode2 << ") - publish date " << ptr->data->getpublish_date() << std::endl;
                    }}}}}
    std::cout << std::endl;
    std::cout << std::endl;
} //END OF MENU FOUR



#endif //CS003AFINALPROJECT_THEMENUS_H
