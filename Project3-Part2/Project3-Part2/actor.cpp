#include"actor.h"
#include"point.h"
#include"aquarium.h"
#include<string>
Actor::Actor(Aquarium* aquarium, Point p, std::string name, char sprite)
:m_aquarium(aquarium), m_curr(p),m_name(name),
m_sprite(sprite), m_state(State::LOOKING), m_interact(Interact::ALONE) {
}
Actor::~Actor() {}
void Actor::setPosition(Point p) {
    m_curr = p;
}
Point Actor::getPosition() const {
    return m_curr;
}
void Actor::setState(State s) {
    m_state = s;
}
State  Actor::getState() const {
    return m_state;
}
char Actor::draw() const {
    
    return m_sprite;
}
Aquarium* Actor::getAquarium() const {
    return m_aquarium;
}
std::string Actor::getName() {
    return m_name;
}

void Actor::setInteract(Interact i) {
    m_interact = i;
}
Interact Actor::getInteract() const {
    return m_interact;
}
