// Stewart Dulaney
// 9/26/2018
// CS 20A Section 4110
// SID: 1545566
// Project 1

#include "globals.h"
#include "blinker.h"

///////////////////////////////////////////////////////////////////////////
// Blinker Implemention
///////////////////////////////////////////////////////////////////////////

Blinker::Blinker(int r, int c) {
    
    m_col = c;
    m_row = r;
    m_height = BLINKER_HEIGHT;
    m_width = BLINKER_WIDTH;
    
    //Allocate space for figure
    m_figure = new char*[BLINKER_HEIGHT];
    for (int i = 0; i < BLINKER_HEIGHT; i++) {
        m_figure[i] = new char[BLINKER_WIDTH];
    }
    
    //Initialize figure
    for (int i = 0; i < BLINKER_HEIGHT; i++) {
        for (int j = 0; j < BLINKER_WIDTH; j++) {
            m_figure[i][j] = ALIVE;
        }
    }
}

Blinker::~Blinker() {
    for (int i = 0; i < BLINKER_HEIGHT; i++) {
        delete[] m_figure[i];
    }
    delete[] m_figure;
}
