
#ifndef OOP_STUDENT_HOUSING_H
#define OOP_STUDENT_HOUSING_H

#include "Building.h"
#include "Employee.h"

class Student_Housing {

    int number_of_buildings;
    int number_of_employees;
    vector<Building> Buildings;
    vector<Employee *> Employees;
public:
    Student_Housing(int S_number_of_buildings, int S_number_of_employees, vector<Building> &S_Buildings,
                    vector<Employee *> &S_Employees);

    Student_Housing(const Student_Housing &other);

    Student_Housing &operator=(const Student_Housing &element);

    friend ostream &operator<<(ostream &out, const Student_Housing &S);

    ~Student_Housing();

    void free_rooms(const string &r_type);


///       $$ PRICES PER PERSON $$
///       SINGLE room-type : 390 $
///       DOUBLE room-type : 220 $ -> 440 per room
///       TRIPLE room-type : 160 $ -> 480 per room


    void profit_per_month();

    void update_prices(const string &type, float new_price);
};

#endif //OOP_STUDENT_HOUSING_H
