// Stewart Dulaney
// 9/26/2018
// CS 20A Section 4110
// SID: 1545566
// Project 1

#ifndef game_h
#define game_h

class Life;
class World;

class Game {
public:
    // Constructor/destructor
    Game(Life **life, int numLife);
    ~Game();
    
    // Mutators
    void play();
private:
    World * m_world;
    int m_steps;
    bool m_automate;
};

#endif /* game_h */
