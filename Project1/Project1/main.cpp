// Stewart Dulaney
// 9/26/2018
// CS 20A Section 4110
// SID: 1545566
// Project 1

#include "life.h"
#include "glider.h"
#include "blinker.h"
#include "game.h"

///////////////////////////////////////////////////////////////////////////
// Main
///////////////////////////////////////////////////////////////////////////

int main() {
    
    Life **population = new Life*[2];
    
    //population[0] = new Blinker(4, 5); //blinker alone
    //int numLife = 1;
    
    //population[0] = new Glider(0,0); //glider alone
    //int numLife = 1;
    
    
    population[0] = new Glider(0, 0); // Blinker and Glider
    population[1] = new Blinker(4, 5);
    int numLife = 2;
    
    // Create the game
    Game g(population, numLife);
    
    // Run the game
    g.play();
    
    // Clean up
    delete population[0];
    delete population[1];
    delete[] population;
    
}
