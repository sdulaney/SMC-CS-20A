// Stewart Dulaney
// 9/22/2018
// CS 20A Section 4110
// SID: 1545566
// Project 1

#include <iostream>
#include <string>
#include "globals.h"
#include "game.h"
#include "world.h"

///////////////////////////////////////////////////////////////////////////
// Game Implemention
///////////////////////////////////////////////////////////////////////////

Game::Game(Life **life, int numLife) {
    
    m_steps = 0;
    m_automate = false;
    m_world = new World();
    
    if (life != nullptr) {
        for (int i = 0; i < numLife; i++) {
            if (life[i] != nullptr) {
                bool success = m_world->addLife(life[i]);
                if (!success) {
                    std::cout << "Failed to add life to the world" << std::endl;
                }
            }
            
        }
    }
    
}
Game::~Game() {
    
    delete m_world;
}

void Game::play()
{
    
    while (true)
    {
        m_world->print();
        
        
        if (!m_world->hasWorldChanged()) {
            std::cout << "The world has not changed, ending game." << std::endl;
            return;
        }
        else {
            
            if (!m_automate) {
                std::cout << "command (<space> to step, <s> to see stats, <a> to automate, <q> to quit): ";
                
                std::string action;
                getline(std::cin, action);
                
                switch (action[0])
                {
                        
                    default:
                        std::cout << '\a' << std::endl;  // beep
                        continue;
                    case 'q':
                        std::cout << "Quitting Game." << std::endl;
                        return;
                    case 's':
                        (m_world->stats()).display();
                        std::cout << "Press enter to continue.";
                        std::cin.ignore(10000, '\n');
                        continue;
                    case ' ':
                        
                        break;
                    case 'a':
                        m_automate = true;
                        break;
                        
                }
            }
            else {
                if (m_steps >= MAX_STEPS) {
                    std::cout << "Reached max steps, quitting." << std::endl;
                    return;
                }
                delay(500);
            }
            m_steps++;
        }
        m_world->update();
        
    }
    
}
