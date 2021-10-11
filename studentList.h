//  Name Emile LEPETIT
//  Class (CECS 282-01)
//  Project Name (Prog 3 – Structs and Pointers)
//  Due Date (10/11/2021)
//  I certify that this program is my own original work. I did not copy any part of this program from
//  any other source. I further certify that I typed each and every line of code in this program.


#ifndef PROG3_STUDENTLIST_H
#define PROG3_STUDENTLIST_H

#include "myDate.h"
#include <iomanip>
#include <cstring>

struct Student {
    char* name;
    int SID;
    char grade;
    myDate birthDay;
    string homeTown;
};

class studentList {
    public:
        studentList() = default;
        ~studentList() = default;
        void populate();
        void display() const;
        void sortByName();
        void sortBySid();
        void sortByGrade();
        void sortByHomeTown();
        void sortByBirthday();
        static void swap(Student **studentA, Student **studentB);

    private:
        Student *_students[10]{};
        void sortBy(bool (*sorter)(Student **, int));
        int randomNbr(int min, int max);

};


#endif //PROG3_STUDENTLIST_H
