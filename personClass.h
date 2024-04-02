// Created by Malena Lodi
#ifndef CS003AFINALPROJECT_PERSONCLASS_H
#define CS003AFINALPROJECT_PERSONCLASS_H
#include<iostream> //include libraries
#include "sortLinkedLists.h" //include files
#include "bookClass.h"

/* **********Parent Class: Person Childen Classes: Student, and Teacher********** */
class Person
{
private:
    int id; //id: the id of a given person
    std::string name; //name: the name of a given person
    int count; //count: the number of books rented by a given person
public:
    Person() {}
    Person(int personId, std::string personName, int personCount) : id(personId), name(personName), count(personCount) {}

    //Setters for 'Person' Class
    void setId(int personId) {id = personId;}
    void setName(std::string personName) {name = personName;}
    void setCount(int personCount) {count = personCount;}
    //Getters for 'Person' class
    int getId() {return id;}
    std::string getName() {return name;}
    int getCount() {return count;}

    //abstract setters for 'Teacher', and 'Student'.
    virtual void setTeacherCode0(int tc1) {std::cout << "blank";}
    virtual void setTeacherCode1(int tc2) {std::cout << "blank";}
    virtual void setTeacherCode2(int tc3) {std::cout << "blank";}
    virtual void setTeacherCode(int tcode[]) {std::cout << "blank";}

    virtual void setStudentCode0(int sc1) {std::cout << "blank";}
    virtual void setStudentCode1(int sc2) {std::cout << "blank";}

    //abstract getters for 'Teacher', and 'Student'.
    virtual int getTeacherCode0() {return 0;}
    virtual int getTeacherCode1() {return 0;}
    virtual int getTeacherCode2() {return 0;}

    virtual int getStudentCode0() {return 0;}
    virtual int getStudentCode1() {return 0;}
};
class Teacher : public Person //child class to 'Person'
{
private:
    int code[3]; //code: an array for the codes of the books in the possession of the teacher
public:
    Teacher() {}
    Teacher(int teacherArray[], int personId, std::string personName, int personCount) : Person(personId, personName, personCount)
    {
        for (int i=0; i<3; i++) { code[i] = teacherArray[i];}
    }

    //Setters for 'Teacher' Class
    void setTeacherCode0(int code0) {code[0] = code0;}
    void setTeacherCode1(int code1) {code[1] = code1;}
    void setTeacherCode2(int code2) {code[2] = code2;}
    void setTeacherCode(int tcode[]) { for (int i=0; i<3; i++) { code[i] = tcode[i];} }
    //Getters for 'Teacher' Class
    int getTeacherCode0() {return code[0];}
    int getTeacherCode1() {return code[1];}
    int getTeacherCode2() {return code[2];}


    //abstract setters for 'Student'.
    virtual void setStudentCode0(int sc1) {std::cout << "blank";}
    virtual void setStudentCode1(int sc2) {std::cout << "blank";}
    //abstract getters for 'Student'.
    virtual int getStudentCode0() {return 0;}
    virtual int getStudentCode1() {return 0;}
};
class Student : public Person //child class to 'Person'
{
private:
    int code[2]; //code: an array for the codes of the books in the possession of the student
public:
    Student() {}
    Student(int studentArray[], int personId, std::string personName, int personCount) :
            Person(personId, personName, personCount)
    {
        for(int i = 0; i < 2; i++) { code[i] = studentArray[i];}
    }
    //Setters for 'Student' class
    void setStudentCode0(int code0) {code[0] = code0;}
    void setStudentCode1(int code1) {code[1] = code1;}
    void setStudentCode(int scode[]) {for (int i=0; i<3; i++) {code[i] = scode[i];}}
    //Getters for 'Student' Class
    int getStudentCode0() {return code[0];}
    int getStudentCode1() {return code[1];}


    //abstract setters for 'Teacher'.
    virtual void setTeacherCode0(int tc1) {std::cout << "blank";}
    virtual void setTeacherCode1(int tc2) {std::cout << "blank";}
    virtual void setTeacherCode3(int tc3) {std::cout << "blank";}
    virtual void setTeacherCode(int tcode) {std::cout << "blank";}
    //abstract getters for 'Teacher'.
    virtual int getTeacherCode0() {return 0;}
    virtual int getTeacherCode1() {return 0;}
    virtual int getTeacherCode2() {return 0;}
};

#endif //CS003AFINALPROJECT_PERSONCLASS_H
