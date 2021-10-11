//  Name Emile LEPETIT
//  Class (CECS 282-01)
//  Project Name (Prog 2 – myDate)
//  Due Date (09/27/2021)
//  I certify that this program is my own original work. I did not copy any part of this program from
//  any other source. I further certify that I typed each and every line of code in this program.

#ifndef MYDATE_MYDATE_H
#define MYDATE_MYDATE_H

#include <string>
#include <iostream>

using namespace std;

int Greg2Julian(int month, int day, int year);
void Julian2Greg(int JD, int & month, int & day, int & year);

class myDate {
    public:
        myDate();
        myDate(int M, int D, int Y);
        ~myDate() = default;

        void display() const;

        void increaseDate(int N);
        void decreaseDate(int N);
        int daysBetween(myDate D);

        int getMonth() const;
        int getDay() const;
        int getYear() const;

        int dayOfYear();

        std::string dayName() const;
        std::string monthName() const;

        std::string c_str() const;

    private:
        int _month;
        int _day;
        int _year;
        bool isValidDate() const;

};


#endif //MYDATE_MYDATE_H
