#ifndef WORLD_H
#define WORLD_H
#include"list.h"
#include"point.h"
#include<string>

const int MAX_ACTORS = 50;
class Player;
class Actor;

class Aquarium {
public:
    
    // Constructor: create the aquarium from file.
    // file must not have any white space after last
    // col and must have one newline after last row.
    // Creates the player, sets the starting and end
    // points
    Aquarium(std::string filename);
    ~Aquarium();
    
    int        rows() const;    // Get the size of the aqarium
    int        cols() const;
    
    int        numOpenCells() const;
    bool    isCellOpen(Point p) const;
    
    Point   getEndPoint() const;
    
    Player*    player() const;    // Get the player from the Aquarium
    int        addSharks();
    void    setPlayerBackTracking(bool toggle);
    
    void    update();        // Update the aquarium by one step
    void    interact();        // Update the Actors' interactions
    void    draw() const;    // Draw the aquarium with actors
    
private:
    
    List<Point> m_openCells;    // Store all the cells actors can move to
    
    int        m_rows;                // Extents of the Aquarium
    int        m_cols;
    
    Point    m_start;            // Start of the maze
    Point    m_end;                // End point of the maze
    
    char**    m_aquarium;            // Aqaurium template created from file
    char**    m_renderedAquarium;    // Copy of aquarium with actors drawn
    
    Player*    m_player;            // Dynamically allocated player
    
    Actor*    m_actors[MAX_ACTORS]; // Polymorphic array of actors
    // The player is always the 0th element
    int        m_nActors;
};

#endif//WORLD_H
