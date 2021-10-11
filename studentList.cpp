//  Name Emile LEPETIT
//  Class (CECS 282-01)
//  Project Name (Prog 3 – Structs and Pointers)
//  Due Date (10/11/2021)
//  I certify that this program is my own original work. I did not copy any part of this program from
//  any other source. I further certify that I typed each and every line of code in this program.


#include "studentList.h"

void studentList::populate()
{
    // I'm french so French name & French cities :)
    string names[] = {"Emile", "Paul", "Arthur", "Valentin", "Adelaide", "Lucy", "Pierre", "Guillaume", "Rose", "Heloise"};
    char grades[] = { 'A','C','B','D','A','F','D','B','F', 'C'};
    string cities[] = {"Paris", "Nantes", "Bordeaux", "Lille", "Lyon", "Marseille", "Nice", "Ile de re", "Saint-Tropez", "Strasbourg"};

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        _students[i] = new Student;
        _students[i]->name = strdup(names[i].c_str());
        _students[i]->SID = randomNbr(100, 999);
        _students[i]->grade = grades[i];
        _students[i]->birthDay = myDate(randomNbr(1, 12), randomNbr(1, 31), randomNbr(2000, 2024));
        _students[i]->homeTown = cities[i];
    }
}

void studentList::display() const
{
    cout << setw(12) << left <<  "Name" << setw(15) << left << "Student ID" << setw(11) << left << "Grade" << setw(20) << left << "Birthday" << setw(25) << left << "Home Town" << endl;
    for (auto _student : _students) {
        cout << setw(12) << left << _student->name << setw(15) << left << _student->SID << setw(11) << left << _student->grade << setw(20) << left << _student->birthDay.c_str() << setw(25) << left << _student->homeTown << endl;
    }
}

void studentList::swap(Student **studentA, Student **studentB)
{
    Student *tmp;
    tmp = *studentB;
    *studentB = *studentA;
    *studentA = tmp;
}

void studentList::sortBy(bool (*sorter)(Student **, int))
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 9 - i; j++)
            if (sorter(_students, j)) studentList::swap(&_students[j], &_students[j + 1]);;
}

void studentList::sortByName()
{
    this->sortBy(
       [](Student **students, int k) {
           return strcmp(students[k]->name, students[k + 1]->name) > 0;
       }
    );
}

void studentList::sortBySid()
{
    this->sortBy(
        [](Student **students, int k) {
            return students[k]->SID > students[k + 1]->SID;
        }
    );
}

void studentList::sortByGrade()
{
    this->sortBy(
        [](Student **students, int k) {
            return students[k]->grade > students[k + 1]->grade;
        }
    );
}

void studentList::sortByBirthday()
{
    this->sortBy(
        [](Student **students, int k) {
            auto bDay1 = students[k]->birthDay;
            auto bDay2 = students[k + 1]->birthDay;
            int jul_1 = Greg2Julian(bDay1.getMonth(), bDay1.getDay(), bDay1.getYear());
            int jul_2 = Greg2Julian(bDay2.getMonth(), bDay2.getDay(), bDay2.getYear());

            return jul_1 > jul_2;
        }
    );
}

void studentList::sortByHomeTown()
{
    this->sortBy(
        [](Student **students, int k) {
            return students[k]->homeTown.compare(students[k + 1]->homeTown) > 0;
        }
    );
}

int studentList::randomNbr(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

