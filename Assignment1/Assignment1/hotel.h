// Stewart Dulaney
// 9/19/2018
// CS 20A Section 4110
// SID: 1545566
// Assignment 1
// Problem 13
#ifndef hotel_h
#define hotel_h

const char RESERVED = 'R';
const char OCCUPIED = 'O';
const char EMPTY = 'E';
const int FLOORS = 20;
const int ROOMSPERFLOOR = 50;

class Hotel {
public:
    Hotel();
    bool reserve(int roomNum);
    bool cancel(int roomNum);
    bool checkIn(int roomNum);
    bool checkOut(int roomNum);
    int numEmpty(int floor) const;  
    char getRoomStatus(int roomNum) const;
private:
    char m_rooms[FLOORS][ROOMSPERFLOOR];
};

#endif /* hotel_h */
