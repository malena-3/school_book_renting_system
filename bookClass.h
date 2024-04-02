#ifndef CS003AFINALPROJECT_BOOKCLASS_H
#define CS003AFINALPROJECT_BOOKCLASS_H
#include<string> //include libraries
#include "sortLinkedLists.h" //include files
#include "personClass.h"

/* **********Parent class: Book Children Classes: ChildrenBook, ComputerBook, Novel********** */
class Book
{
private:
    int code; //code: the code of a given book
    std::string title; //title: the title of a given book
    int available; //available: the availability of a given book
    int rented; //rented: the amount of particular books that have been rented out
public:
    Book() {}
    Book(int bookC, std::string bookT, int bookA, int bookR) : code(bookC), title(bookT), available(bookA), rented(bookR) {}

    //Setters for 'Book' class
    void setCode(int bookC) {code = bookC;}
    void setTitle(std::string bookT) {title = bookT;}
    void setAvailable(int bookA) {available = bookA;}
    void setRented(int bookR) {rented = bookR;}

    //Getters for 'Book' class
    int getCode() {return code;}
    std::string getTitle() {return title;}
    int getAvailable() {return available;}
    int getRented() {return rented;}

    //abstract setters for 'ChildrenBook', 'ComputerBook', and 'Novel'.
    virtual void setAge(int bA) = 0;
    virtual void setPublisher(std::string bP) = 0;
    virtual void setpublish_date(int bPD) = 0;

    //abstract getters for 'ChildrenBook', 'ComputerBook', and 'Novel'.
    virtual int getAge() = 0;
    virtual std::string getPublisher() = 0;
    virtual int getpublish_date() = 0;
};

class ChildrenBook : public Book //child class to 'Book'
{
private:
    int age; //age: the age of a given book, in the 'ChildrenBook' category
public:
    ChildrenBook() {}
    ChildrenBook(int chilbookA, int bookC, std::string bookT, int bookA, int bookR) :
            age(chilbookA), Book(bookC, bookT, bookA, bookR) {}

    //Setters for 'ChildrenBook' class
    void setAge(int chilbookA) {age = chilbookA;}
    //getters for 'ChildrenBook' class
    int getAge() {return age;}

    //abstract setters for 'ComputerBook', and 'Novel'.
    virtual void setPublisher(std::string bP) {std::cout << "blank";}
    virtual void setpublish_date(int bPD) {std::cout << "blank";}
    //abstract getters for 'ComputerBook', and 'Novel'.
    virtual std::string getPublisher() {return 0;}
    virtual int getpublish_date() {return 0;}
};
class ComputerBook : public Book //child class to 'Book'
{
private:
    std::string publisher; //publisher: the publisher of a given book, in the 'ComputerBook' category
public:
    ComputerBook() {}
    ComputerBook(std::string compbookP, int bookC, std::string bookT, int bookA, int bookR) :
            publisher(compbookP), Book(bookC, bookT, bookA, bookR) {}

    //Setters for 'ComputerBook' class
    void setPublisher(std::string compbookP) {publisher = compbookP;}
    //Getters for 'ComputerBook' class
    std::string getPublisher() {return publisher;}

    //abstract setters for 'ChildrenBook', and 'Novel'.
    virtual void setAge(int bA) {std::cout << "blank";}
    virtual void setpublish_date(int bPD) {std::cout << "blank";}
    //abstract getters for 'ChildrenBook', and 'Novel'.
    virtual int getAge() {return 0;}
    virtual int getpublish_date() {return 0;}

};
class Novel : public Book //child class to 'Book'
{
private:
    int publish_date; //publish_date: the publish date of a given book, in the 'Novel' category
public:
    Novel() {}
    Novel(int novelPubD, int bookC, std::string bookT, int bookA, int bookR) :
            publish_date(novelPubD), Book(bookC, bookT, bookA, bookR) {}

    //Setters for 'Novel' class
    void setpublish_date(int novelPubD) {publish_date = novelPubD;}
    //Getters for 'Novel' class
    int getpublish_date() {return publish_date;}

    //abstract setters for 'ChildrenBook', and 'ComputerBook'.
    virtual void setAge(int bA) {std::cout << "blank";}
    virtual void setPublisher(std::string bP) {std::cout << "blank";}
    //abstract getters for 'ChildrenBook', and 'ComputerBook'.
    virtual int getAge() {return 0;}
    virtual std::string getPublisher() {return 0;}
};

#endif //CS003AFINALPROJECT_BOOKCLASS_H
