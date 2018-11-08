#include<iostream>
#include<string>
using namespace std;

// DEFINE YOUR TEST
#define TEST3

#ifdef TEST1
//        What single specific paricular one-thing is being tested?:
//        What is expected?:
//        What happens?:
#include"list.h"
int main() {
    
    List<int> l;
    
    l.addToRear(3);
    l.addToFront(-1);
    l.addToFront(9000);
    l.addToFront(2);
    l.printItems();
    l.deleteRear();
    l.printItems();
    
    l.deleteItem(2);
    l.printItems();
    return 0;
}

#elif defined(TEST2)
//        What single specific paricular one-thing is being tested?:
//        What is expected?:
//        What happens?:
#include"stack.h"
#include"queue.h"

int main() {
    
    Stack<std::string> stack;
    Queue<std::string> queue;
    
    stack.push("Feynman");
    stack.push("Turing");
    stack.push("Einstein");
    stack.push("Bohr");
    stack.push("Sanchez");
    
    stack.printStack();
    
    queue.push(stack.peek());
    stack.pop();
    
    queue.push(stack.peek());
    stack.pop();
    
    queue.push(stack.peek());
    stack.pop();
    
    queue.push(stack.peek());
    stack.pop();
    
    queue.pop();
    queue.pop();
    
    queue.printQueue();
    
    
    return 0;
}

#elif defined(TEST3) //Test the maze in lecture slides without backtracking
//        What single specific paricular one-thing is being tested?:
//        What is expected?:
//        What happens?:
#include"game.h"

int main() {
    
    bool havePlayerBackTack = false; //Toggle player backtracking
    
    int frame_time_delay = 500;        //Effects game speed, shorter delay
    //less time between frames, faster
    //simulation when automating.
    
    bool clearScreen = true;        //Clear the console prior to drawing
    //the next iteration of the game.
    //If you wish to debug by printing
    //to the console you may want to disable.
    int num_sharks = 0;
    
    //Setup game
    Game g("maze_lecture.txt", num_sharks, frame_time_delay, clearScreen, havePlayerBackTack);
    
    //Exectute game loop
    g.play();
    
    return 0;
}
#elif defined(TEST4) //Test a custom maze without backtracking
//        What single specific paricular one-thing is being tested?:
//        What is expected?:
//        What happens?:
#include"game.h"
int main() {
    bool havePlayerBackTack = false; //Toggle player backtracking
    
    int frame_time_delay = 500;        //Effects game speed, shorter delay
    //less time between frames, faster
    //simulation when automating.
    bool clearScreen = true;        //Clear the console prior to drawing
    //the next iteration of the game.
    //If you wish to debug by printing
    //to the console you may want to disable.
    int num_sharks =3;
    
    //Setup game
    Game g("maze.txt", num_sharks, frame_time_delay, clearScreen, havePlayerBackTack);
    
    //Exectute game loop
    g.play();
    
    return 0;
}
#elif defined(TEST5) //Test lecture slide maze with backtracking
//        What single specific paricular one-thing is being tested?:
//        What is expected?:
//        What happens?:
#include"game.h"
int main() {
    bool havePlayerBackTack = true; //Toggle player backtracking
    
    int frame_time_delay = 500;        //Effects game speed, shorter delay
    //less time between frames, faster
    //simulation when automating.
    
    bool clearScreen = true;        //Clear the console prior to drawing
    //the next iteration of the game.
    //If you wish to debug by printing
    //to the console you may want to disable.
    int num_sharks = 3;
    
    //Setup game
    Game g("maze_lecture.txt", num_sharks, frame_time_delay, clearScreen, havePlayerBackTack);
    
    //Exectute game loop
    g.play();
    
    return 0;
}
#else
int main() {
    cout << "Hello World!" << endl;
    return 0;
}
#endif
