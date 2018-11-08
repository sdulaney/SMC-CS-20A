#ifndef ACTOR_H
#define ACTOR_H
#include"point.h"
#include<string>

// An Actor can have certain States that describe
// What they are doing
enum class State { LOOKING, STUCK, BACKTRACK, FREEDOM };

// Interactions between Actors
enum class Interact { GREET, ATTACK, ALONE };

class Aquarium;

class Actor {
public:
    
    Actor(Aquarium* aquarium, Point p, std::string, char sprite);
    virtual ~Actor();
    // Pure virtual functions: Actor is an ABC
    // Derived classes must implement
    virtual    void    update() = 0;
    virtual    void    say() = 0;
    
    // Maybe overriden in derived class
    // Otherwise just returns the char
    // representing the Actor
    virtual    char    draw() const;
    
    // Setters and Getters for common attributes
    std::string        getName();
    
    void            setPosition(Point p);
    Point            getPosition() const;
    
    void            setState(State s);
    State            getState() const;
    
    void            setInteract(Interact i);
    Interact        getInteract() const;
    
    Aquarium*        getAquarium() const;
    
private:
    Point        m_curr;        //Current position
    
    State        m_state;
    Interact    m_interact;
    
    char        m_sprite;
    Aquarium*    m_aquarium; //Pointer to the aquarium
    //Actor does not allocate
    //Just points to it.
    std::string m_name;
};

#endif//ACTOR_H
