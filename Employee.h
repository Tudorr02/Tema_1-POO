
#ifndef OOP_EMPLOYEE_H
#define OOP_EMPLOYEE_H

#include <iostream>

using std::string;
using std::ostream;
using std::cout;

class Employee {
    unsigned int age;
    float salary;  /// DOLLAR
    string full_name;
    string job_position;

public:

    Employee(unsigned int e_age, float e_salary, const string &e_full_name, const string &e_job_position);

    Employee(const Employee &other);

    Employee &operator=(const Employee &element);

    friend ostream &operator<<(ostream &out, const Employee &e);

    ~Employee();

    void salary_raise(float &addition);

    float getSalary() const;

    string getName() const;

};


#endif //OOP_EMPLOYEE_H
