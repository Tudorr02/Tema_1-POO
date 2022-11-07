//
// Created by ilieo on 28.10.2022.
//

#include "Building.h"


Building::Building(int b_floors, int b_kitchens, bool b_has_an_elvator, vector<Room> &b_rooms, const string &b_name) :
        floors{b_floors}, kitchens{b_kitchens}, has_an_elevator{b_has_an_elvator}, rooms{b_rooms}, name{b_name} {

    //out<<"Constr de initializare Building\n";

}

Building::Building(const Building &other) :
        floors{other.floors}, kitchens{other.kitchens}, has_an_elevator{other.has_an_elevator}, rooms{other.rooms},
        name{other.name} {
    //cout<<"Constructor de copiere Building\n";
}

Building &Building::operator=(const Building &other) {
    floors = other.floors;
    kitchens = other.kitchens;
    has_an_elevator = other.has_an_elevator;
    rooms = other.rooms;
    name = other.name;
    //cout<<"Op de copiere Building\n";
    return *this;
}

ostream &operator<<(ostream &out, const Building &B) {
    out << "NAME: " << B.name << "\n";
    out << "Floors:" << B.floors << "\n";
    out << "Kitchens:" << B.kitchens << "\nHas an elevator:" << B.has_an_elevator << "\n";

    out << "---Rooms\n";
    for (const auto &element: B.rooms) {
        out << element << " ";
    }
    //out<<"\n";
    return out;
}

Building::~Building() {//cout<<"Destructor Building\n";
}

void Building::free_rooms(const string &type) {
    int count = 0;
    cout << this->name << ":";
    for (auto &element: this->rooms) {
        int x = element.is_free(type);
        if (x != 0) { cout << " Room  " << x << " is free\n", count++; }

    }

    if (count == 0) cout << " no free rooms\n";
}

float Building::earnings() {
    float sum = 0;
    for (auto &element: this->rooms) {
        sum += element.room_price();
    }
    cout << "Building " << this->name << " earnings: " << sum << "\n";
    return sum;
}

void Building::update_price(const string &type, float new_price) {

    for (auto &element: this->rooms)
        element.update_price(type, new_price);
}


