// Stewart Dulaney
// 9/26/2018
// CS 20A Section 4110
// SID: 1545566
// Project 1

#ifndef globals_h
#define globals_h

///////////////////////////////////////////////////////////////////////////
// Global constants
///////////////////////////////////////////////////////////////////////////

const int MAX_ROWS = 11;
const int MAX_COLS = 11;

const int BLINKER_HEIGHT = 3;
const int BLINKER_WIDTH = 1;

const int GLIDER_SIZE = 3;

const int MAX_STEPS = 50;

const char ALIVE = 'X';
const char DEAD = '.';

///////////////////////////////////////////////////////////////////////////
//  Utility function declarations
///////////////////////////////////////////////////////////////////////////

void clearScreen();
void delay(int ms);

#endif /* globals_h */
