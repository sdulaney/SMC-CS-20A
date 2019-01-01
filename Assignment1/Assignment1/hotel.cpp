// Stewart Dulaney
// 9/19/2018
// CS 20A Section 4110
// SID: 1545566
// Assignment 1
// Problem 13
#include <iostream>
#include "hotel.h"

Hotel::Hotel() {
    // TODO: Set all the rooms in the Hotel to be EMPTY
    for (int i = 0; i < FLOORS; i++) {
        for (int j = 0; j < ROOMSPERFLOOR; j++) {
            m_rooms[i][j] = EMPTY;
        }
    }
}

bool Hotel::reserve(int roomNum) {
    // TODO: If the room is EMPTY, set it to RESERVED, and return true.
    // In all other cases, do not change anything and return false.
    if (m_rooms[roomNum / 100][roomNum % 100] == EMPTY) {
        m_rooms[roomNum / 100][roomNum % 100] = RESERVED;
        return true;
    }
    return false;
}

bool Hotel::cancel(int roomNum) {
    // TODO: If the room is RESERVED, set it to EMPTY, and return true.
    // In all other cases, do not change anything and return false.
    if (m_rooms[roomNum / 100][roomNum % 100] == RESERVED) {
        m_rooms[roomNum / 100][roomNum % 100] = EMPTY;
        return true;
    }
    return false;
}

bool Hotel::checkIn(int roomNum) {
    // TODO: If the room is RESERVED, set it to OCCUPIED, and return true.
    // In all other cases, do not change anything and return false.
    if (m_rooms[roomNum / 100][roomNum % 100] == RESERVED) {
        m_rooms[roomNum / 100][roomNum % 100] = OCCUPIED;
        return true;
    }
    return false;
}

bool Hotel::checkOut(int roomNum) {
    // TODO: If the room is OCCUPIED, set it to EMPTY, and return true.
    // In all other cases, do not change anything and return false.
    if (m_rooms[roomNum / 100][roomNum % 100] == OCCUPIED) {
        m_rooms[roomNum / 100][roomNum % 100] = EMPTY;
        return true;
    }
    return false;
}

int Hotel::numEmpty(int floor) const {
    // TODO: Return the number of empty rooms on the floor.
    // Return -1 if floor is invalid.
    if ((floor < 0) || (floor > FLOORS)) {
        return -1;
    }
    int count = 0;
    for (int i = 0; i < ROOMSPERFLOOR; i++) {
        if (m_rooms[floor][i] == EMPTY) {
            count++;
        }
    }
    return count;
}

char Hotel::getRoomStatus(int roomNum) const {
    return m_rooms[roomNum / 100][roomNum % 100];
}
