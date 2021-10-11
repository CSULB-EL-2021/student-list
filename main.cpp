//  Name Emile LEPETIT
//  Class (CECS 282-01)
//  Project Name (Prog 3 – Structs and Pointers)
//  Due Date (10/11/2021)
//  I certify that this program is my own original work. I did not copy any part of this program from
//  any other source. I further certify that I typed each and every line of code in this program.


#include "studentList.h"

int prompt() {
    char input = 0;

    std::cout << "Menu:" << std::endl;
    std::cout << "1) Display list sorted by Name" << std::endl;
    std::cout << "2) Display list sorted by Student ID" << std::endl;
    std::cout << "3) Display list sorted by Grade" << std::endl;
    std::cout << "4) Display list sorted by Birthday" << std::endl;
    std::cout << "5) Display list sorted by Home Town" << std::endl;
    std::cout << "6) Exit" << std::endl << std::endl;

    std::cout << "Your choice: ";
    std::cin >> input;

    return input - '0';
}

int main()
{
    int input;
    bool run = true;
    auto studentsList = new studentList();

    studentsList->populate();
    while (run) {
        input = prompt();
        switch (input) {
            case 1:
                studentsList->sortByName();
                studentsList->display();
                break;
            case 2:
                studentsList->sortBySid();
                studentsList->display();
                break;
            case 3:
                studentsList->sortByGrade();
                studentsList->display();
                break;
            case 4:
                studentsList->sortByBirthday();
                studentsList->display();
                break;
            case 5:
                studentsList->sortByHomeTown();
                studentsList->display();
                break;
            case 6:
                run = false;
                break;
            default:
               std::cout << "Try another number" << endl;
               break;
        }
        std::cout << endl;
    }

    return 0;
}
