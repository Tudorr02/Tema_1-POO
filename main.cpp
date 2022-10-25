#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::ostream;

class Room {

    int room_number;
    string room_type;              /// single , double, triple , premium
    string good_for_accommodation;   /// yes, no /// good conditions/ needs repairs
    string free;                     /// yes, no

public:
    Room(int r_number, const string &r_type, const string &r_good, const string &r_free) : room_number{r_number},
                                                                                           room_type{r_type},
                                                                                           good_for_accommodation{
                                                                                                   r_good},
                                                                                           free{r_free} {

        //cout<<"Constructor de initializare Room"<<room_number<<"\n";//<<this->room_number<<" "<<this->room_type<<" "<<this->good_for_accommodation<<" "<<this->free<<"\n";
    }

    Room(const Room &element) : room_number{element.room_number}, room_type{element.room_type},
                                good_for_accommodation{element.good_for_accommodation}, free{element.free} {

        //cout<<"Constructor de copiere Room"<<element.room_number<<"\n";
    }

    Room &operator=(const Room &other) {

        //cout<<"Operator de copiere Room "<<other.room_number<<"\n";
        room_number = other.room_number;
        room_type = other.room_type;
        good_for_accommodation = other.good_for_accommodation;
        free = other.free;
        return *this;
    }

    friend ostream &operator<<(std::ostream &out, const Room &room) {
        out << "Room " << room.room_number << " |type: " << room.room_type << " |good_for_accomodation: "
            << room.good_for_accommodation << " |free: " << room.free << "\n";
        return out;
    }

    ~Room() {//cout<<"Destructor Room"<<room_number<<"\n";
    }

    Room() = default;

};

class Building {
    int floors;
    int kitchens;
    bool has_an_elevator;    /// yes/no
    vector<Room> rooms;
    string name;

public:
    Building(int b_floors, int b_kitchens, bool b_has_an_elvator, vector<Room> &b_rooms, const string &b_name) :
            floors{b_floors}, kitchens{b_kitchens}, has_an_elevator{b_has_an_elvator}, rooms{b_rooms}, name{b_name} {

        //out<<"Constr de initializare Building\n";

    }

    Building(const Building &other) :
            floors{other.floors}, kitchens{other.kitchens}, has_an_elevator{other.has_an_elevator}, rooms{other.rooms},
            name{other.name} {
        //cout<<"Constructor de copiere Building\n";
    }

    Building &operator=(const Building &element) {
        floors = element.floors;
        kitchens = element.kitchens;
        has_an_elevator = element.has_an_elevator;
        rooms = element.rooms;
        name = element.name;
        //cout<<"Op de copiere Building\n";
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Building &B) {
        out << "NAME: " << B.name << "\n";
        out << "Floors:" << B.floors << "\n";
        out << "Kitchens:" << B.kitchens << "\nHas an elevator:" << B.has_an_elevator << "\n";

        out << "---Rooms\n";
        for (const auto &element: B.rooms) {
            out << element << " ";
        }
        //out<<"\n";
        return out;
    };

    ~Building() {//cout<<"Destructor Building\n";
    }

    Building() = default;

};

class Employee {
    unsigned int age;
    float salary;  /// DOLLAR
    string full_name;
    string job_position;

public:

    Employee(unsigned int e_age, float e_salary, const string &e_full_name, const string &e_job_position) :
            age(e_age), salary(e_salary), full_name(e_full_name), job_position(e_job_position) {
        //cout<<"Constructor de initializare Angajat: "<<this->full_name<<"\n";
    }

    Employee(const Employee &other) :
            age{other.age}, salary{other.salary}, full_name{other.full_name}, job_position{other.job_position} {
        //cout<<"Constructor de copiere Angajat: "<<other.full_name<<"\n";
    }

    Employee &operator=(const Employee &element) {
        //cout<<"Operator de copiere Angajat: "<<element.full_name;
        age = element.age;
        salary = element.salary;
        full_name = element.full_name;
        job_position = element.job_position;
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Employee &e) {
        out << "Full Name: " << e.full_name << "\n";
        out << "Age: " << e.age << "\n";
        out << "Salary: " << e.salary << " $\n";
        out << "Job position: " << e.job_position << "\n-------------\n";
        return out;
    }

    ~Employee() {//cout<<"Destructor Angajat: "<<this->full_name<<"\n";
    }

    Employee() = default;

};

class Student_Housing {

    int number_of_buildings;
    int number_of_employees;
    vector<Building> Buildings;
    vector<Employee> Employees;
public:
    Student_Housing(int S_number_of_buildings, int S_number_of_employees, vector<Building> &S_Buildings,
                    vector<Employee> &S_Employees) :
            number_of_buildings{S_number_of_buildings}, number_of_employees{S_number_of_employees},
            Buildings{S_Buildings}, Employees{S_Employees} {

        // cout<<"Constructor de initializare Camin Studentesc\n";
    }

    Student_Housing(const Student_Housing &other) :
            number_of_buildings{other.number_of_buildings}, number_of_employees{other.number_of_employees},
            Buildings{other.Buildings}, Employees{other.Employees} {
        //cout<<"Constructor de copiere Camin Studentesc\n";
    }

    Student_Housing &operator=(const Student_Housing &element) {
        //cout<<"Operator de copiere Camin Studentesc\n";
        number_of_buildings = element.number_of_buildings;
        number_of_employees = element.number_of_employees;
        Buildings = element.Buildings;
        Employees = element.Employees;
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Student_Housing &S) {
        out << "Camin Studentesc:\n";
        out << "Number of Buildings: " << S.number_of_buildings << "\n";
        out << "Number of Employees: " << S.number_of_employees << "\n";
        out << "-----------------------\n";
        out << "-------Buildings-------\n";

        for (const auto &element: S.Buildings) {
            out << element << "------------------------\n";
        }

        out << "-------Employees-------\n";
        for (const auto &element: S.Employees) {
            out << element;
        }

        return out;
    }

    ~Student_Housing() {//cout<<"Destructor Camin Studentesc";
    }

    Student_Housing() = default;


};

int main() {

    Room R_456(456, "single", "yes", "no");
    Room R_333(333, "double", "no", "yes");
    Room R_111(111, "triple", "no", "no");
    Room R_121(121, "triple", "yes", "yes");
    Room R_131(131, "triple", "yes", "no");
    Room R_199(199, "single", "no", "no");
    Room R_205(205, "double", "yes", "yes");

    vector<Room> rooms_M1;
    vector<Room> rooms_M2;

    rooms_M1.push_back(R_456);
    rooms_M1.push_back(R_333);
    rooms_M1.push_back(R_111);
    rooms_M1.push_back(R_121);
    rooms_M1.push_back(R_131);

    rooms_M2.push_back(R_199);
    rooms_M2.push_back(R_205);

    Building M1(4, 4, true, rooms_M1, "M1");
    Building M2(3, 3, false, rooms_M2, "M2");

    vector<Building> buildings;
    buildings.push_back(M1);
    buildings.push_back(M2);

    ///----EMPLOYEES
    Employee e1(25, 370, "MARIAN", "gardian");
    Employee e2(33, 890, "Andrei", "administrator");

    vector<Employee> employees;

    employees.push_back(e1);
    employees.push_back(e2);

    Student_Housing S1(1, 1, buildings, employees);

    cout << S1;


    return 0;
}
