// Stewart Dulaney
// 9/19/2018
// CS 20A Section 4110
// SID: 1545566
// Assignment 1
// Problem 13
#include <iostream>
#include "hotel.h"

int main() {
    
    Hotel h1;
    // Print the number of empty rooms on each floor
    for (int i = 0; i < FLOORS; i++) {
        std::cout << "Empty rooms on Floor " << i << ": " << h1.numEmpty(i) << std::endl;
    }
    // Reserve room 425
    std::cout << "Room 425 status: " << h1.getRoomStatus(425) << std::endl;
    std::cout << "Reservation successful: " << h1.reserve(425) << std::endl;
    std::cout << "Room 425 status: " << h1.getRoomStatus(425) << std::endl;
    // Try to reserve room 425 when already reserved
    std::cout << "Reservation successful: " << h1.reserve(425) << std::endl;
    // Cancel room 425
    std::cout << "Cancellation successful: " << h1.cancel(425) << std::endl;
    std::cout << "Room 425 status: " << h1.getRoomStatus(425) << std::endl;
    // Try to cancel room 425 when already cancelled
    std::cout << "Cancellation successful: " << h1.cancel(425) << std::endl;
    // Try to check in to room 425 without a reservation
    std::cout << "Check in successful: " << h1.checkIn(425) << std::endl;
    // Re-reserve room 425
    h1.reserve(425);
    // Check in to room 425
    std::cout << "Check in successful: " << h1.checkIn(425) << std::endl;
    std::cout << "Room 425 status: " << h1.getRoomStatus(425) << std::endl;
    // Check out of room 425
    std::cout << "Check out successful: " << h1.checkOut(425) << std::endl;
    std::cout << "Room 425 status: " << h1.getRoomStatus(425) << std::endl;
    // Try to check out of room 425 when already empty
    std::cout << "Check out successful: " << h1.checkOut(425) << std::endl;
    
    return 0;
}
