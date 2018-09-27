// Stewart Dulaney
// 9/26/2018
// CS 20A Section 4110
// SID: 1545566
// Project 1

#include "globals.h"
#include "glider.h"

///////////////////////////////////////////////////////////////////////////
// Glider Implemention
///////////////////////////////////////////////////////////////////////////

Glider::Glider(int r, int c) {
    m_col = c;
    m_row = r;
    m_height = GLIDER_SIZE;
    m_width = GLIDER_SIZE;
    
    // Allocate space for figure
    m_figure = new char*[GLIDER_SIZE];
    for (int i = 0; i < GLIDER_SIZE; i++) {
        m_figure[i] = new char[GLIDER_SIZE];
    }
    
    // Initialize figure
    for (int i = 0; i < GLIDER_SIZE; i++) {
        for (int j = 0; j < GLIDER_SIZE; j++) {
            m_figure[i][j] = DEAD;
        }
    }
    m_figure[0][1] = ALIVE;
    m_figure[1][2] = ALIVE;
    m_figure[2][0] = ALIVE;
    m_figure[2][1] = ALIVE;
    m_figure[2][2] = ALIVE;
}

Glider::~Glider() {
    for (int i = 0; i < GLIDER_SIZE; i++) {
        delete[] m_figure[i];
    }
    delete[] m_figure;
}
