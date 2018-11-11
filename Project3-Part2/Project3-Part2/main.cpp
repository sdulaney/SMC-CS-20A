#include<iostream>
#include<string>
#include <assert.h>
using namespace std;

// DEFINE YOUR TEST
#define TEST13

#ifdef TEST1
//        What single specific particular one-thing is being tested?:
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
//        What single specific particular one-thing is being tested?:
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
//        What single specific particular one-thing is being tested?:
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
//        What single specific particular one-thing is being tested?:
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
//        What single specific particular one-thing is being tested?:
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

#elif defined(TEST6) // Test Queue::push(Type item)
//        What single specific particular one-thing is being tested?:
//        What is expected?:
//        What happens?:
#define MAKE_MEMBERS_PUBLIC
#include"queue.h"
int main() {
    
    Queue<std::string> queue;
    queue.push("Feynman");
    queue.push("Turing");
    queue.push("Einstein");
    assert(queue.m_list.head->item == "Feynman");
    assert(queue.m_list.head->next->item == "Turing");
    assert(queue.m_list.head->next->next->item == "Einstein");
    assert(queue.m_list.tail->item == "Einstein");
    assert(queue.m_list.size == 3);
    
    return 0;
}

#elif defined(TEST7) // Test Queue::pop()
//        What single specific particular one-thing is being tested?:
//        What is expected?:
//        What happens?:
#define MAKE_MEMBERS_PUBLIC
#include"queue.h"
int main() {
    
    Queue<std::string> queue;
    queue.push("Feynman");
    queue.push("Turing");
    queue.push("Einstein");
    queue.pop();
    assert(queue.m_list.head->item == "Turing");
    assert(queue.m_list.head->next->item == "Einstein");
    assert(queue.m_list.tail->item == "Einstein");
    assert(queue.m_list.size == 2);
    queue.pop();
    assert(queue.m_list.head->item == "Einstein");
    assert(queue.m_list.tail->item == "Einstein");
    assert(queue.m_list.size == 1);
    queue.pop();
    assert(queue.m_list.head == nullptr);
    assert(queue.m_list.tail == nullptr);
    assert(queue.m_list.size == 0);
    
    return 0;
}

#elif defined(TEST8) // Test Queue::printQueue()
//        What single specific particular one-thing is being tested?:
//        What is expected?:
//        What happens?:
//#define MAKE_MEMBERS_PUBLIC
#include"queue.h"
int main() {
    
    Queue<std::string> queue;
    queue.push("Feynman");
    queue.push("Turing");
    queue.push("Einstein");
    queue.printQueue();         // expect Front Feynman Turing Einstein Rear
    
    return 0;
}

#elif defined(TEST9) // Test Queue::peek()
//        What single specific particular one-thing is being tested?:
//        What is expected?:
//        What happens?:
#define MAKE_MEMBERS_PUBLIC
#include"queue.h"
int main() {
    
    Queue<std::string> queue;
    queue.push("Feynman");
    queue.push("Turing");
    queue.push("Einstein");
    assert(queue.peek() == "Feynman");
    assert(queue.m_list.size == 3);
    queue.pop();
    assert(queue.peek() == "Turing");
    queue.pop();
    assert(queue.peek() == "Einstein");
    // Note: As in List<Type>::getFront(), do not have to worry about case when
    // linked list is empty
    
    return 0;
}

#elif defined(TEST10) // Test Queue::isEmpty()
//        What single specific particular one-thing is being tested?:
//        What is expected?:
//        What happens?:
//#define MAKE_MEMBERS_PUBLIC
#include"queue.h"
int main() {
    
    Queue<std::string> queue;
    assert(queue.isEmpty() == true);
    queue.push("Feynman");
    assert(queue.isEmpty() == false);
    
    return 0;
}

#elif defined(TEST11) // Test Stack::push(Type item)
//        What single specific particular one-thing is being tested?:
//        What is expected?:
//        What happens?:
#define MAKE_MEMBERS_PUBLIC
#include"stack.h"
int main() {
    
    Stack<std::string> stack;
    stack.push("Feynman");
    stack.push("Turing");
    stack.push("Einstein");
    assert(stack.m_list.head->item == "Einstein");
    assert(stack.m_list.head->next->item == "Turing");
    assert(stack.m_list.head->next->next->item == "Feynman");
    assert(stack.m_list.tail->item == "Feynman");
    assert(stack.m_list.size == 3);
    
    return 0;
}

#elif defined(TEST12) // Test Stack::pop()
//        What single specific particular one-thing is being tested?:
//        What is expected?:
//        What happens?:
#define MAKE_MEMBERS_PUBLIC
#include"stack.h"
int main() {
    
    Stack<std::string> stack;
    stack.push("Feynman");
    stack.push("Turing");
    stack.push("Einstein");
    stack.pop();
    assert(stack.m_list.head->item == "Turing");
    assert(stack.m_list.head->next->item == "Feynman");
    assert(stack.m_list.tail->item == "Feynman");
    assert(stack.m_list.size == 2);
    stack.pop();
    assert(stack.m_list.head->item == "Feynman");
    assert(stack.m_list.tail->item == "Feynman");
    assert(stack.m_list.size == 1);
    stack.pop();
    assert(stack.m_list.head == nullptr);
    assert(stack.m_list.tail == nullptr);
    assert(stack.m_list.size == 0);
    
    return 0;
}

#elif defined(TEST13) // Test Stack::printStack()
//        What single specific particular one-thing is being tested?:
//        What is expected?:
//        What happens?:
//#define MAKE_MEMBERS_PUBLIC
#include"stack.h"
int main() {
    
    Stack<std::string> stack;
    stack.push("Feynman");
    stack.push("Turing");
    stack.push("Einstein");
    stack.printStack();             // expect Front Einstein Turing Feynman Rear
    
    return 0;
}

#else
int main() {
    cout << "Hello World!" << endl;
    return 0;
}
#endif
