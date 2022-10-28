
#ifndef OOP_ROOM_H
#define OOP_ROOM_H

#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::ostream;

class Room {

    int room_number;
    string room_type;                /// single , double, triple , premium
    string good_for_accommodation;   /// yes, no /// good conditions/ needs repairs
    string free;                     /// yes, no
    float price;

public:

    Room(int r_number, const string &r_type, const string &r_good, const string &r_free);

    Room(const Room &element);

    Room &operator=(const Room &other);

    friend ostream &operator<<(std::ostream &out, const Room &room);

    ~Room();

    int is_free(const string &type);

    float room_price();

    void update_price(const string &type, float new_price);

};


#endif //OOP_ROOM_H
