#include"shark.h"
#include"aquarium.h"
#include"player.h"
#include"utils.h"
Shark::Shark(Aquarium* aquarium, Point p, std::string name, char sprite):
Actor(aquarium, p, name, sprite){
}
void Shark::update() {
    
    // Pick a random direction
    int dir = randInt(0, 3);
    // Get a copy of sharks current position
    Point p  = getPosition();
    
    int rows = getAquarium()->rows();
    int cols = getAquarium()->cols();
    int x    = p.getX();
    int y    = p.getY();
    
    // Check to see if desired direction is inbounds.
    // Accounting for the Walls and one space to allow
    // movement in that direction. Update the x,y
    // coordinates or do nothing
    switch (dir) {
        case 0:  if (y <= 2)      return; else y--; break;
        case 1:  if (y >= rows-3) return; else y++; break;
        case 2:  if (x <= 2)      return; else x--; break;
        case 3:  if (x >= cols-3) return; else x++; break;
        default: return;
    }
    
    // Check to see if new position is an open cell
    p.set(x, y);
    if (!getAquarium()->isCellOpen(p))
        return;
    
    setPosition(p);
}

void Shark::say() {
    switch (getInteract()) {
        case Interact::ATTACK:
            std::cout << getName() << ": OM NOM!";
            break;
        case Interact::ALONE:
            std::cout << getName() << ": I'm hungry";
            break;
        case Interact::GREET:
            std::cout << getName() << ": Hey Buddy";
            break;
        default:
            std::cout << getName() << ":A - hee - ahee ha - hee!";
    }
}
