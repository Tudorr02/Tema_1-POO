
#ifndef OOP_STUDENT_HOUSING_H
#define OOP_STUDENT_HOUSING_H

#include "Building.h"
#include "Employee.h"

class Student_Housing {

    vector<Building> Buildings;
    vector<Employee> Employees;
public:
    Student_Housing(vector<Building> &S_Buildings,
                    vector<Employee> &S_Employees);

    Student_Housing(const Student_Housing &other);

    Student_Housing &operator=(const Student_Housing &element);

    friend ostream &operator<<(ostream &out, const Student_Housing &S);

    ~Student_Housing();

    void free_rooms(const string &r_type);

    float profit_per_month();

    void update_prices(const string &type, float new_price);

    void update_salary(const string &full_name, float addition);
};

#endif //OOP_STUDENT_HOUSING_H
