// Stewart Dulaney
// 9/26/2018
// CS 20A Section 4110
// SID: 1545566
// Project 1

#include <iostream>
#include "globals.h"
#include "stats.h"

Stats::Stats() {
    // Allocate space for 2D array
    m_stats = new char*[MAX_ROWS];
    for (char i = 0; i < MAX_ROWS; i++) {
        m_stats[i] = new char[MAX_COLS];
    }
    // Initialize 2D array
    for (char i = 0; i < MAX_ROWS; i++) {
        for (char j = 0; j < MAX_COLS; j++) {
            m_stats[i][j] = DEAD;
        }
    }
}

Stats::~Stats() {
    for (char i = 0; i < MAX_ROWS; i++) {
        delete[] m_stats[i];
    }
    delete[] m_stats;
}

void Stats::display() const {
    for (char i = 0; i < MAX_ROWS; i++) {
        for (char j = 0; j < MAX_COLS; j++) {
                std::cout << m_stats[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Stats::record(int r, int c, int val) {
    int currentValue;
    // If the cell contains '.', set currentValue to '0'. Otherwise, use the value the cell
    // contains ('1' through '9').
    (m_stats[r][c] == DEAD) ? (currentValue = 48) : (currentValue = static_cast<int>(m_stats[r][c]));
    // If the sum of val and currentValue is less than or equal to '9'
    if ((currentValue + val) <= 57) {
        m_stats[r][c] = static_cast<char>(currentValue + val);
        return true;
    }
    return false;
}
