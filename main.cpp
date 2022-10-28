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
    float price;

public:
    Room(int r_number, const string &r_type, const string &r_good, const string &r_free) : room_number{r_number},
                                                                                           room_type{r_type},
                                                                                           good_for_accommodation{
                                                                                                   r_good},
                                                                                           free{r_free} {

        if (this->room_type == "single") this->price = 390;
        if (this->room_type == "double") this->price = 220 * 2;
        if (this->room_type == "triple") this->price = 160 * 3;
        //cout<<"Constructor de initializare Room"<<room_number<<"\n";//<<this->room_number<<" "<<this->room_type<<" "<<this->good_for_accommodation<<" "<<this->free<<"\n";
    }

    Room(const Room &element) : room_number{element.room_number}, room_type{element.room_type},
                                good_for_accommodation{element.good_for_accommodation}, free{element.free},
                                price{element.price} {

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
            << room.good_for_accommodation << " |free: " << room.free << "|price: " << room.price << "\n";
        return out;
    }

    ~Room() {//cout<<"Destructor Room"<<room_number<<"\n";
    }

    int is_free(const string &type) {
        if (this->free == "yes" && this->room_type == type)
            return this->room_number;
        else
            return 0;
    }

    float room_price() {
        if (this->free == "no") return this->price;

        return 0;

    }

    void update_price(const string &type, float new_price) {
        if (this->room_type == type)
            this->price = new_price;
    }

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

    void free_rooms(const string &type) {
        int count = 0;
        cout << this->name << ":";
        for (auto &element: this->rooms) {
            int x = element.is_free(type);
            if (x != 0) { cout << " Room  " << x << " is free\n", count++; }

        }

        if (count == 0) cout << " no free rooms\n";
    }

    float earnings() {
        float sum = 0;
        for (auto &element: this->rooms) {
            sum += element.room_price();
        }
        cout << "Building " << this->name << " earnings: " << sum << "\n";
        return sum;
    }

    void update_price(const string &type, float new_price) {

        for (auto &element: this->rooms)
            element.update_price(type, new_price);
    }


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

    void salary_raise(const float &addition) {
        this->salary += addition, cout << "Salary update !! " << this->full_name << "'s salary is now " << this->salary
                                       << " $\n";
    }

    float getSalary() const {
        return salary;
    }
};

class Student_Housing {

    int number_of_buildings;
    int number_of_employees;
    vector<Building> Buildings;
    vector<Employee *> Employees;
public:
    Student_Housing(int S_number_of_buildings, int S_number_of_employees, vector<Building> &S_Buildings,
                    vector<Employee *> &S_Employees) :
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
            out << (*element);
        }

        return out;
    }

    ~Student_Housing() {//cout<<"Destructor Camin Studentesc";
    }

    void free_rooms(const string &r_type) {

        for (auto &element: this->Buildings) {
            element.free_rooms(r_type);
        }
    }


///       $$ PRICES PER PERSON $$
///       SINGLE room-type : 390 $
///       DOUBLE room-type : 220 $ -> 440 per room
///       TRIPLE room-type : 160 $ -> 480 per room


    void profit_per_month() {
        float profit = 0;
        for (auto &element: this->Buildings) profit += element.earnings();
        for (auto &element: this->Employees) profit -= element->getSalary();

        cout << "Students Housing's profit per month is: " << profit << "\n";
    }

    void update_prices(const string &type, float new_price) {

        for (auto &element: this->Buildings)
            element.update_price(type, new_price);

    }

};

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

    vector<Employee *> employees = {&e1, &e2};

    Student_Housing S1((int) buildings.size(), (int) employees.size(), buildings, employees);

    /// FREE ROOMS CHECKER single/double/triple
    S1.free_rooms("triple");

    e1.salary_raise(300);
    e2.salary_raise(100);

    S1.profit_per_month(); /// PROFIT CALCULATOR

    S1.update_prices("triple", 500);
    S1.update_prices("single", 410);

    cout << "*******************************************************\n";

    cout << S1;

    //S1.profit_per_month();


    return 0;
}
