#include"Studentinfo.h"
#include<iostream>
#include<assert.h>
using std::cout;
using std::endl;

// Choose which test to compile
#define TEST9

#ifdef TEST0

#include"list.h"

// Sample Usage
int main() {
    
    cout << StudentInfo::name() << endl;
    cout << StudentInfo::id() << endl;
    
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

#elif defined TEST3

//#define MAKE_MEMBERS_PUBLIC
#include"list.h"
#include <string>
using std::string;

// Test printItems
int main() {
    // Case 1: Linked list is empty
    List<int> l;
    l.printItems();         // Front Rear
    
    // Case 2: Linked list is not empty
    List<string> l2; //List of strings
    l2.addToFront("Ruby");
    l2.addToFront("Shell");
    l2.addToFront("Cash");
    l2.printItems();         // Front Cash Shell Ruby Rear
    
    return 0;
}

#elif defined TEST4

#define MAKE_MEMBERS_PUBLIC
#include"list.h"

// Test addToRear
int main() {
    
    List<int> l; //List of integers
    
    // Case 1: Linked list is empty
    l.addToRear(10);
    assert(l.head != nullptr);
    assert(l.tail != nullptr);
    assert(l.head == l.tail);
    assert(l.size == 1);
    assert(l.head->item == 10);
    assert(l.head->next == nullptr);
    
    // Case 2: Linked list is not empty
    l.addToRear(31);
    assert(l.head != nullptr);
    assert(l.tail != nullptr);
    assert(l.head != l.tail);
    assert(l.size == 2);
    assert(l.head->item == 10);
    assert(l.head->next == l.tail);
    assert(l.tail->item == 31);
    assert(l.tail->next == nullptr);
    l.addToRear(18);
    assert(l.size == 3);
    assert(l.head->item == 10);
    assert(l.head->next->item == 31);
    assert(l.tail->item == 18);
    
    return 0;
}

#elif defined TEST5

//#define MAKE_MEMBERS_PUBLIC
#define DEBUGMEMORY
#include"debugmem.h"
#include"list.h"

// Test destructor
int main() {
    
    List<int>* l = new List<int>; //List of integers
    l->addToRear(11);
    l->addToRear(2);
    l->addToRear(18);
    
    GETMEMORYREPORT();
    cout << endl;
    
    delete l;
    
    GETMEMORYREPORT();
    cout << endl;
    
    return 0;
}

#elif defined TEST6

#define MAKE_MEMBERS_PUBLIC
#include"list.h"

// Test addItem
int main() {
    
    // Case 1: index < 0
    List<int> l; //List of integers
    l.addToRear(11);
    l.addToRear(2);
    l.addToRear(20);
    l.addToRear(18);
    l.addItem(-1, 7);
    assert(l.head->item == 7);
    assert(l.head->next->item == 11);
    assert(l.head->next->next->item == 2);
    assert(l.head->next->next->next->item == 20);
    assert(l.head->next->next->next->next == l.tail);
    assert(l.tail->item == 18);
    assert(l.size == 5);
    
    // Case 2: index == 0
    List<int> l2; //List of integers
    l2.addToRear(11);
    l2.addToRear(2);
    l2.addToRear(20);
    l2.addToRear(18);
    l2.addItem(0, 7);
    assert(l2.head->item == 7);
    assert(l2.head->next->item == 11);
    assert(l2.head->next->next->item == 2);
    assert(l2.head->next->next->next->item == 20);
    assert(l2.head->next->next->next->next == l2.tail);
    assert(l2.tail->item == 18);
    assert(l2.size == 5);
    
    // Case 3: index == (size - 1)
    List<int> l3; //List of integers
    l3.addToRear(11);
    l3.addToRear(2);
    l3.addToRear(20);
    l3.addToRear(18);
    l3.addItem(3, 7);
    assert(l3.head->item == 11);
    assert(l3.head->next->item == 2);
    assert(l3.head->next->next->item == 20);
    assert(l3.head->next->next->next->item == 18);
    assert(l3.head->next->next->next->next == l3.tail);
    assert(l3.tail->item == 7);
    assert(l3.size == 5);
    
    // Case 4: index > (size - 1)
    List<int> l4; //List of integers
    l4.addToRear(11);
    l4.addToRear(2);
    l4.addToRear(20);
    l4.addToRear(18);
    l4.addItem(4, 7);
    assert(l4.head->item == 11);
    assert(l4.head->next->item == 2);
    assert(l4.head->next->next->item == 20);
    assert(l4.head->next->next->next->item == 18);
    assert(l4.head->next->next->next->next == l4.tail);
    assert(l4.tail->item == 7);
    assert(l4.size == 5);
    
    // Case 5: all other cases
    List<int> l5; //List of integers
    l5.addToRear(11);
    l5.addToRear(2);
    l5.addToRear(20);
    l5.addToRear(18);
    l5.addItem(2, 7);
    assert(l5.head->item == 11);
    assert(l5.head->next->item == 2);
    assert(l5.head->next->next->item == 7);
    assert(l5.head->next->next->next->item == 20);
    assert(l5.head->next->next->next->next == l5.tail);
    assert(l5.tail->item == 18);
    assert(l5.size == 5);
    
    return 0;
}

#elif defined TEST7

//#define MAKE_MEMBERS_PUBLIC
#include"list.h"

// Test getItem
int main() {
    
    List<int> l; //List of integers
    l.addToRear(11);
    l.addToRear(2);
    l.addToRear(20);
    l.addToRear(18);
    assert(l.getItem(0) == 11);
    assert(l.getItem(1) == 2);
    assert(l.getItem(2) == 20);
    assert(l.getItem(3) == 18);
    
    return 0;
}

#elif defined TEST8

//#define MAKE_MEMBERS_PUBLIC
#include"list.h"

// Test findItem
int main() {
    
    List<int> l; //List of integers
    l.addToRear(11);
    l.addToRear(2);
    l.addToRear(20);
    l.addToRear(18);
    
    // Case 1: item is in list
    assert(l.findItem(20) == 2);
    
    // Case 2: item is not in list
    assert(l.findItem(27) == -1);
    
    // Case 3: list is empty
    List<int> l2; //List of integers
    assert(l2.findItem(27) == -1);
    
    return 0;
}

#elif defined TEST9

#define MAKE_MEMBERS_PUBLIC
#define DEBUGMEMORY
#include"debugmem.h"
#include"list.h"

// Test deleteFront
int main() {
    
    // Case 1: Linked list is empty
    List<int> l; //List of integers
    assert(l.deleteFront() == false);
    assert(l.size == 0);
    
    // Case 2: Linked list has one item
    List<int> l2; //List of integers
    l2.addToRear(11);
    
    GETMEMORYREPORT();
    cout << endl;
    
    assert(l2.deleteFront() == true);
    assert(l2.head == nullptr);
    assert(l2.size == 0);
    
    GETMEMORYREPORT();
    cout << endl;
    
    // Case 2: Linked list has more than one item
    List<int> l3; //List of integers
    l3.addToRear(11);
    l3.addToRear(2);
    l3.addToRear(20);
    l3.addToRear(18);
    
    GETMEMORYREPORT();
    cout << endl;
    
    assert(l3.deleteFront() == true);
    assert(l3.head->item == 2);
    assert(l3.head->next->item == 20);
    assert(l3.head->next->next == l3.tail);
    assert(l3.tail->item == 18);
    assert(l3.size == 3);
    
    GETMEMORYREPORT();
    cout << endl;
    
    return 0;
}

#else

#include"list.h"

int main() {
    
    return 0;
}

#endif
