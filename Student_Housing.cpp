//
// Created by ilieo on 28.10.2022.
//

#include "Student_Housing.h"


Student_Housing::Student_Housing(int S_number_of_buildings, int S_number_of_employees, vector<Building> &S_Buildings,
                                 vector<Employee *> &S_Employees) :
        number_of_buildings{S_number_of_buildings}, number_of_employees{S_number_of_employees},
        Buildings{S_Buildings}, Employees{S_Employees} {

    // cout<<"Constructor de initializare Camin Studentesc\n";
}

Student_Housing::Student_Housing(const Student_Housing &other) :
        number_of_buildings{other.number_of_buildings}, number_of_employees{other.number_of_employees},
        Buildings{other.Buildings}, Employees{other.Employees} {
    //cout<<"Constructor de copiere Camin Studentesc\n";
}

Student_Housing &Student_Housing::operator=(const Student_Housing &element) {
    //cout<<"Operator de copiere Camin Studentesc\n";
    number_of_buildings = element.number_of_buildings;
    number_of_employees = element.number_of_employees;
    Buildings = element.Buildings;
    Employees = element.Employees;
    return *this;
}

ostream &operator<<(ostream &out, const Student_Housing &S) {
    out << "Camin Studentesc:\n";
    out << "Number of Buildings: " << S.number_of_buildings << "\n";
    out << "Number of Employees: " << S.number_of_employees << "\n";
    out << "-----------------------\n";
    out << "-------Buildings-------\n";

    for (const auto &element: S.Buildings) {
        out << element << "------------------------\n";
    }

    out << "-------Employees-------\n";
    for (const auto *element: S.Employees) {
        out << (*element);
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


///       $$ PRICES PER PERSON $$
///       SINGLE room-type : 390 $
///       DOUBLE room-type : 220 $ -> 440 per room
///       TRIPLE room-type : 160 $ -> 480 per room


void Student_Housing::profit_per_month() {
    float profit = 0;
    for (auto &element: this->Buildings) profit += element.earnings();
    for (auto &element: this->Employees) profit -= element->getSalary();

    cout << "Students Housing's profit per month is: " << profit << "\n";
}

void Student_Housing::update_prices(const string &type, float new_price) {

    for (auto &element: this->Buildings)
        element.update_price(type, new_price);

}

