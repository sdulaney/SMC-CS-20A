// Stewart Dulaney
// 9/26/2018
// CS 20A Section 4110
// SID: 1545566
// Project 1

#include <iostream>
#include "globals.h"
#include "world.h"
#include "life.h"

///////////////////////////////////////////////////////////////////////////
// World Implemention
///////////////////////////////////////////////////////////////////////////

World::World() :
m_toggle(true)
{
    m_world = new char*[MAX_ROWS];
    m_otherWorld = new char*[MAX_ROWS];
    for (char i = 0; i < MAX_ROWS; i++) {
        m_world[i] = new char[MAX_COLS];
        m_otherWorld[i] = new char[MAX_COLS];
    }
    
    for (char i = 0; i < MAX_ROWS; i++) {
        for (char j = 0; j < MAX_COLS; j++) {
            m_world[i][j] = DEAD;
        }
    }
    
}

World::~World() {
    for (char i = 0; i < MAX_ROWS; i++) {
        delete[] m_world[i];
        delete[] m_otherWorld[i];
    }
    delete[] m_world;
    delete[] m_otherWorld;
    
}

void World::print() const {
    clearScreen();
    if (m_toggle) {
        for (char i = 0; i < MAX_ROWS; i++) {
            for (char j = 0; j < MAX_COLS; j++) {
                std::cout << m_world[i][j];
            }
            std::cout << std::endl;
        }
    }
    else {
        for (char i = 0; i < MAX_ROWS; i++) {
            for (char j = 0; j < MAX_COLS; j++) {
                std::cout << m_otherWorld[i][j];
            }
            std::cout << std::endl;
        }
    }
    for (char i = 0; i < MAX_COLS; i++) {
        std::cout << '=';
    }
    std::cout << std::endl;
}

bool World::hasWorldChanged() const {
    
    for (char i = 0; i < MAX_ROWS; i++) {
        for (char j = 0; j < MAX_COLS; j++) {
            
            if (m_otherWorld[i][j] != m_world[i][j]) {
                return true;
            }
            
        }
    }
    return false;
}

Stats& World::stats() {
    return m_stats;
}

void World::update() {
    if (m_toggle) {
        for (char i = 0; i < MAX_ROWS; i++) {
            for (char j = 0; j < MAX_COLS; j++) {
                m_otherWorld[i][j] =
                _getState(m_world[i][j], i, j, m_toggle);
                // If the cell is ALIVE in the next state (m_otherWorld) and is DEAD
                // in the current state (m_world), then record a birth.
                if ((m_otherWorld[i][j] == ALIVE) && (m_world[i][j] == DEAD)) {
                    (stats()).record(i, j, 1);
                }
            }
        }
        m_toggle = !m_toggle;
    }
    else {
        for (char i = 0; i < MAX_ROWS; i++) {
            for (char j = 0; j < MAX_COLS; j++) {
                m_world[i][j] =
                _getState(m_otherWorld[i][j], i, j, m_toggle);
                // If the cell is ALIVE in the next state (m_world) and is DEAD
                // in the current state (m_otherWorld), then record a birth.
                if ((m_world[i][j] == ALIVE) && (m_otherWorld[i][j] == DEAD)) {
                    (stats()).record(i, j, 1);
                }
            }
        }
        m_toggle = !m_toggle;
    }
}

char World::_getState(char state, char row, char col, bool toggle) {
    int yCoord = row;
    int xCoord = col;
    char neighbors = 0;
    if (toggle) {
        for (char i = yCoord - 1; i <= yCoord + 1; i++) {
            for (char j = xCoord - 1; j <= xCoord + 1; j++) {
                if (i == yCoord && j == xCoord) {
                    continue;
                }
                if (i > -1 && i < MAX_ROWS && j > -1 && j < MAX_COLS) {
                    if (m_world[i][j] == ALIVE) {
                        neighbors++;
                    }
                }
            }
        }
    }
    else {
        for (char i = yCoord - 1; i <= yCoord + 1; i++) {
            for (char j = xCoord - 1; j <= xCoord + 1; j++) {
                if (i == yCoord && j == xCoord) {
                    continue;
                }
                if (i > -1 && i < MAX_ROWS && j > -1 && j < MAX_COLS) {
                    if (m_otherWorld[i][j] == ALIVE) {
                        neighbors++;
                    }
                }
            }
        }
    }
    if (state == ALIVE) {
        return (neighbors > 1 && neighbors < 4) ? ALIVE : DEAD;
    }
    else {
        return (neighbors == 3) ? ALIVE : DEAD;
    }
}

bool World::addLife(Life *life) {
    
    if (life == nullptr) {
        std::cout << "Cannot add nullptr life" << std::endl;
        return false;
    }
    
    // Should check life extents with world bounds.
    
    for (char i = life->getRow(); i - life->getRow() < life->getHeight(); i++) {
        for (char j = life->getCol(); j - life->getCol() < life->getWidth(); j++) {
            if (i < MAX_ROWS && j < MAX_COLS) {
                m_world[i][j] =
                life->getFromFigure(i - life->getRow(), j - life->getCol());
            }
        }
    }
    return true;
}
