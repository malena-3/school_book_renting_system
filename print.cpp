// Created by Malena Lodi
#include "print.h" //include files

void removeUnderscore(std::string s) //removeUnderScore: removes all occuring underscores of a string and outputs the result
{
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < 'A' || s[i] > 'Z' && s[i] < 'a'
            || s[i] > 'z') {
            s[i] = ' '; //replace underscores with blank space
        }
    }
    std::cout << s;
}
//***All outputs of book lists are for menufive***
void printChildrenBookList(NodePtr head1) //printChildrenBookList: prints the linked list of 'ChildrenBook' for menufive
{
    std::cout << "================================================================\n";
    std::cout << "                     Children Books\n";
    std::cout << "================================================================\n";
    std::cout << " code                  title             age  available  rented\n";
    std::cout << "----------------------------------------------------------------\n";

    NodePtr ptr1 = nullptr;
    for (ptr1 = head1; ptr1 != nullptr; ptr1 = ptr1->link)
    {
        std::string title = ptr1->data->getTitle();
        std::cout << ptr1->data->getCode() << std::setw(35);
        removeUnderscore(title);
        std::cout << std::setw(4) << ptr1->data->getAge() << std::setw(9) << ptr1->data->getAvailable() << std::setw(8) << ptr1->data->getRented() << std::endl;
    }
}
void printComputerBookList(NodePtr head2) //printComputerBookList: prints the linked list of 'ComputerBook' for menufive
{
    std::cout << "==================================================================================\n";
    std::cout << "                            Computer Books\n";
    std::cout << "==================================================================================\n";
    std::cout << " code                     title                   publisher     available  rented\n";
    std::cout << "----------------------------------------------------------------------------------\n";

    NodePtr ptr2 = nullptr;
    for (ptr2 = head2; ptr2 != nullptr; ptr2 = ptr2->link)
    {
        std::string title = ptr2->data->getTitle();
        std::cout << ptr2->data->getCode() << std::setw(35);
        removeUnderscore(title);
        std::cout << std::setw(23) << ptr2->data->getPublisher() << std::setw(8)
                  << ptr2->data->getAvailable() << std::setw(8) << ptr2->data->getRented() << std::endl;
    }
}
void printNovelBookList(NodePtr head3) //printNovelBookList: prints the linked list of 'Novel' for menufive
{
    std::cout << "==================================================================================\n";
    std:: cout << "                            Novel Books\n";
    std::cout << "==================================================================================\n";
    std::cout << " code                     title                publish_date     available  rented\n";
    std::cout << "----------------------------------------------------------------------------------\n";
    NodePtr ptr3 = nullptr;
    for (ptr3 = head3; ptr3 != nullptr; ptr3 = ptr3->link)
    {
        std::string title = ptr3->data->getTitle();
        std::cout << ptr3->data->getCode() << std::setw(30);
        removeUnderscore(title);
        std::cout << std::setw(21) << ptr3->data->getpublish_date() << std::setw(14)
                  << ptr3->data->getAvailable() << std::setw(10) << ptr3->data->getRented() << std::endl;
    }
}