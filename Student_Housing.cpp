
#include "Student_Housing.h"


Student_Housing::Student_Housing(vector<Building> &S_Buildings,
                                 vector<Employee> &S_Employees) :
        Buildings{S_Buildings}, Employees{S_Employees} {

    // cout<<"Constructor de initializare Camin Studentesc\n";
}

Student_Housing::Student_Housing(const Student_Housing &other) :
        Buildings{other.Buildings}, Employees{other.Employees} {
    //cout<<"Constructor de copiere Camin Studentesc\n";
}

Student_Housing &Student_Housing::operator=(const Student_Housing &element) {
    //cout<<"Operator de copiere Camin Studentesc\n";

    Buildings = element.Buildings;
    Employees = element.Employees;
    return *this;
}

ostream &operator<<(ostream &out, const Student_Housing &S) {
    out << "Camin Studentesc:\n";
    out << "Number of Buildings: " << S.Buildings.size() << "\n";
    out << "Number of Employees: " << S.Employees.size() << "\n";
    out << "-----------------------\n";
    out << "-------Buildings-------\n";

    for (const auto &element: S.Buildings) {
        out << element << "------------------------\n";
    }

    out << "-------Employees-------\n";
    for (const auto &element: S.Employees) {
        out << (element);
    }

    return out;
}

Student_Housing::~Student_Housing() {//cout<<"Destructor Camin Studentesc";
}

void Student_Housing::free_rooms(const string &r_type) {

    for (auto &element: this->Buildings) {
        element.free_rooms(r_type);
    }
}


float Student_Housing::profit_per_month() {
    float profit = 0;
    for (auto &element: this->Buildings) profit += element.earnings();
    for (auto &element: this->Employees) profit -= element.getSalary();

    cout << "Students Housing's profit per month is: " << profit << "\n";
    return profit;
}

void Student_Housing::update_prices(const string &type, float new_price) {

    for (auto &element: this->Buildings)
        element.update_price(type, new_price);

}

void Student_Housing::update_salary(const string &full_name, float addition) {

    for (auto &element: this->Employees) {
        if (!full_name.compare(element.getName()))
            element.salary_raise(addition);
    }

}

