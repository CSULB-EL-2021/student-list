//  Name Emile LEPETIT
//  Class (CECS 282-01)
//  Project Name (Prog 2 – myDate)
//  Due Date (09/27/2021)
//  I certify that this program is my own original work. I did not copy any part of this program from
//  any other source. I further certify that I typed each and every line of code in this program.

#include "myDate.h"

int Greg2Julian(int month, int day, int year) {
    int I = year;
    int J = month;
    int K = day;

    return K-32075+1461*(I+4800+(J-14)/12)/4+367*(J-2-(J-14)/12*12)/12-3*((I+4900+(J-14)/12)/100)/4;
}

void Julian2Greg(int JD, int & month, int & day, int & year) {
    int L, N, I, J, K;

    L = JD+68569;
    N = 4*L/146097;
    L = L-(146097*N+3)/4;
    I = 4000*(L+1)/1461001;
    L = L-1461*I/4+31;
    J = 80*L/2447;
    K = L-2447*J/80;
    L = J/11;
    J = J+2-12*L;
    I = 100*(N-49)+I+L;

    year = I;
    month = J;
    day = K;
}

myDate::myDate(): _month(5), _day(11), _year(1959)
{}

myDate::myDate(int M, int D, int Y): _month(M), _day(D), _year(Y)
{
    if (!isValidDate()) {
        _month = 5;
        _day = 11;
        _year = 1959;
    }
}

bool myDate::isValidDate() const
{
    int mm, dd, yy;
    int tmp = Greg2Julian(_month, _day, _year);

    Julian2Greg(tmp, mm, dd, yy);

    return !(mm != _month || dd != _day || yy != _year);
}


int myDate::getMonth() const
{
    return _month;
}

int myDate::getDay() const
{
    return _day;
}

int myDate::getYear() const
{
    return _year;
}

std::string myDate::dayName() const
{
    int julian = Greg2Julian(_month, _day, _year);

    const std::string days[] = {
        "Monday", "Tuesday", "Wednesday", "Thursday",
        "Friday", "Saturday", "Sunday"
    };

    return days[julian % 7];
}

std::string myDate::monthName() const
{
    const std::string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    return months[_month - 1];
}

void myDate::display() const
{
    // May 11, 1959
    cout << monthName() << " " << _day << ", " << _year;
}

void myDate::increaseDate(int N)
{
    int julian = Greg2Julian(_month, _day, _year);
    Julian2Greg(julian + N, _month, _day, _year);
}

void myDate::decreaseDate(int N)
{
    int julian = Greg2Julian(_month, _day, _year);
    Julian2Greg(julian - N, _month, _day, _year);
}

int myDate::daysBetween(myDate D)
{
    int sDate = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());
    int eDate = Greg2Julian(_month, _day, _year);
    return sDate - eDate;
}

int myDate::dayOfYear()
{
    int sDate = Greg2Julian(1, 1, _year);
    int eDate = Greg2Julian(_month, _day, _year);
    return eDate - sDate + 1;
}

std::string myDate::c_str() const
{
    return monthName() + " " + to_string(getDay()) + ", " + to_string(getYear());
}
