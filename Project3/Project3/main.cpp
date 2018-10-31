#include"Studentinfo.h"
#include<iostream>
#include<assert.h>

// Choose which test to compile
#define TEST2

#ifdef TEST0

#include"list.h"

// Sample Usage
int main() {
    
    std::cout << StudentInfo::name() << std::endl;
    std::cout << StudentInfo::id() << std::endl;
    
    List<int> l; //List of integers
    
    l.addToRear(3);
    l.addToFront(-1);
    l.addToFront(9000);
    l.addToFront(2);
    l.printItems();
    l.deleteRear();
    l.printItems();
    
    return 0;
}

#elif defined TEST1

#define MAKE_MEMBERS_PUBLIC
#include"list.h"

// Test default constructor
int main() {
    
    List<int> l; //List of integers
    assert(l.head == nullptr);
    assert(l.tail == nullptr);
    assert(l.size == 0);
    
    return 0;
}

#elif defined TEST2

#define MAKE_MEMBERS_PUBLIC
#include"list.h"

// Test addToFront
int main() {
    
    List<int> l; //List of integers
    
    // Case 1: Linked list is empty
    l.addToFront(10);
    assert(l.head != nullptr);
    assert(l.tail != nullptr);
    assert(l.head == l.tail);
    assert(l.size == 1);
    assert(l.head->item == 10);
    assert(l.head->next == nullptr);
    
    // Case 2: Linked list is not empty
    l.addToFront(31);
    assert(l.head != nullptr);
    assert(l.tail != nullptr);
    assert(l.head != l.tail);
    assert(l.size == 2);
    assert(l.head->item == 31);
    assert(l.head->next == l.tail);
    assert(l.tail->item == 10);
    assert(l.tail->next == nullptr);
    l.addToFront(18);
    assert(l.size == 3);
    assert(l.head->item == 18);
    assert(l.head->next->item == 31);
    assert(l.tail->item == 10);
    
    return 0;
}

#else

#include"list.h"

int main() {
    
    return 0;
}

#endif
