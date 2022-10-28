
#ifndef OOP_BUILDING_H
#define OOP_BUILDING_H

#include "Room.h"

class Building {
    int floors;
    int kitchens;
    bool has_an_elevator;    /// yes/no
    vector<Room> rooms;
    string name;

public:

    Building(int b_floors, int b_kitchens, bool b_has_an_elvator, vector<Room> &b_rooms, const string &b_name);

    Building(const Building &other);

    Building &operator=(const Building &element);

    friend ostream &operator<<(ostream &out, const Building &B);

    ~Building();

    void free_rooms(const string &type);

    float earnings();

    void update_price(const string &type, float new_price);

};

#endif //OOP_BUILDING_H
