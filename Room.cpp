//
// Created by ilieo on 28.10.2022.
//

#include "Room.h"


Room::Room(int r_number, const string &r_type, const string &r_good, const string &r_free) : room_number{r_number},
                                                                                             room_type{r_type},
                                                                                             good_for_accommodation{
                                                                                                     r_good},
                                                                                             free{r_free} {

    if (this->room_type == "single") this->price = 390;
    if (this->room_type == "double") this->price = 220 * 2;
    if (this->room_type == "triple") this->price = 160 * 3;
    //cout<<"Constructor de initializare Room"<<room_number<<"\n";//<<this->room_number<<" "<<this->room_type<<" "<<this->good_for_accommodation<<" "<<this->free<<"\n";
}

Room::Room(const Room &element) : room_number{element.room_number}, room_type{element.room_type},
                                  good_for_accommodation{element.good_for_accommodation}, free{element.free},
                                  price{element.price} {

    //cout<<"Constructor de copiere Room"<<element.room_number<<"\n";
}

Room &Room::operator=(const Room &other) {

    //cout<<"Operator de copiere Room "<<other.room_number<<"\n";
    room_number = other.room_number;
    room_type = other.room_type;
    good_for_accommodation = other.good_for_accommodation;
    free = other.free;
    price = other.price;
    return *this;
}

ostream &operator<<(std::ostream &out, const Room &room) {
    out << "Room " << room.room_number << " |type: " << room.room_type << " |good_for_accomodation: "
        << room.good_for_accommodation << " |free: " << room.free << "|price: " << room.price << "\n";
    return out;
}

Room::~Room() {/*cout<<"Destructor Room"<<room_number<<"\n";*/}


int Room::is_free(const string &type) {
    if (this->free == "yes" && this->room_type == type)
        return this->room_number;
    else
        return 0;
}

float Room::room_price() {
    if (this->free == "no") return this->price;

    return 0;

}

void Room::update_price(const string &type, float new_price) {
    if (this->room_type == type)
        this->price = new_price;
}


