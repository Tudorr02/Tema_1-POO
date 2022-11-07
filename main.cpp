#include <iostream>
#include <vector>
#include "Room.h"
#include "Building.h"
#include "Employee.h"
#include "Student_Housing.h"


int main() {

    ///M1 rooms

    Room R_456(456, "single", "yes", "yes");
    Room R_333(333, "single", "no", "no");
    Room R_111(111, "triple", "no", "no");
    Room R_121(121, "triple", "yes", "no");
    Room R_131(131, "triple", "yes", "yes");
    Room R_366(366, "triple", "yes", "yes");

    ///M2 rooms
    Room R_199(199, "single", "no", "no");
    Room R_205(205, "double", "yes", "yes");


    vector<Room> rooms_M1 = {R_456, R_333, R_111, R_121, R_131, R_366};
    vector<Room> rooms_M2 = {R_199, R_205};

    Building M1(4, 4, true, rooms_M1, "M1");
    Building M2(3, 3, false, rooms_M2, "M2");

    vector<Building> buildings = {M1, M2};

    ///----EMPLOYEES
    Employee e1(25, 370, "MARIAN", "guardian");
    Employee e2(33, 290, "Andrei", "administrator");

    vector<Employee> employees = {e1, e2};

    Student_Housing S1(buildings, employees);

    /// FREE ROOMS CHECKER single/double/triple
    S1.free_rooms("triple");

//    e1.salary_raise(300);
//    e2.salary_raise(100);

    S1.profit_per_month(); /// PROFIT CALCULATOR

    S1.update_prices("triple", 500);
    S1.update_prices("single", 410);

    cout << "*******************************************************\n";

    cout << S1;

    //S1.profit_per_month();

    S1.update_salary("MARIAN", 380);
    cout << S1;


    return 0;
}
