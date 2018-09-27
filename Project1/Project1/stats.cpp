// Stewart Dulaney
// 9/22/2018
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
            // If the cell contains '.', use the insertion operator (<<) overloaded for char
            if (m_stats[i][j] == DEAD) {
                std::cout << m_stats[i][j];
            }
            // If the cell contains '1' through '9', use the insertion operator (<<) overloaded for int
            else {
                std::cout << static_cast<int>(m_stats[i][j]);
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Stats::record(int r, int c, int val) {
    int currentValue;
    (m_stats[r][c] == DEAD) ? (currentValue = 0) : (currentValue = static_cast<int>(m_stats[r][c]));
    if ((currentValue + val) <= 9) {
        m_stats[r][c] = static_cast<char>(currentValue + val);
        return true;
    }
    return false;
}
