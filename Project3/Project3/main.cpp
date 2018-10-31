#include"Studentinfo.h"
#include<iostream>
#include<assert.h>

// Choose which test to compile
#define TEST1

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

#else

#include"list.h"

int main() {
    
    return 0;
}

#endif
