
#include "Employee.h"


Employee::Employee(unsigned int e_age, float e_salary, const string &e_full_name, const string &e_job_position) :
        age(e_age), salary(e_salary), full_name(e_full_name), job_position(e_job_position) {
    //cout<<"Constructor de initializare Angajat: "<<this->full_name<<"\n";
}

Employee::Employee(const Employee &other) :
        age{other.age}, salary{other.salary}, full_name{other.full_name}, job_position{other.job_position} {
    //cout<<"Constructor de copiere Angajat: "<<other.full_name<<"\n";
}

Employee &Employee::operator=(const Employee &element) {
    //cout<<"Operator de copiere Angajat: "<<element.full_name;
    age = element.age;
    salary = element.salary;
    full_name = element.full_name;
    job_position = element.job_position;
    return *this;
}

ostream &operator<<(ostream &out, const Employee &e) {
    out << "Full Name: " << e.full_name << "\n";
    out << "Age: " << e.age << "\n";
    out << "Salary: " << e.salary << " $\n";
    out << "Job position: " << e.job_position << "\n-------------\n";
    return out;
}

Employee::~Employee() {/*cout<<"Destructor Angajat: "<<this->full_name<<"\n";*/}


void Employee::salary_raise(const float &addition) {

    this->salary += addition;
    cout << "Salary update !! " << this->full_name << "'s salary is now " << this->salary << " $\n";

}

float Employee::getSalary() const {
    return salary;
}

string Employee::getName() const {
    return full_name;
}

