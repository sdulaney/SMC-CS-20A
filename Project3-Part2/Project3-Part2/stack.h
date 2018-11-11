#ifndef STACK_H
#define STACK_H
#include"list.h"

// Stack ADT using linked list as primary data structure.
//
template<typename Type>
class Stack {
public:
    
    Stack();
    
    // Basic stack operations
    void    push(Type item);
    void    pop();
    Type    peek() const;
    
    // Check to see if there is anything on the stack
    bool    isEmpty() const;
    
    // Use to see what is in the stack for debugging
    void    printStack() const;
    
#ifndef MAKE_MEMBERS_PUBLIC
private:
#endif
    
    List<Type> m_list;
};

// Stack Implementation
//

// 1. Stack() Default constrcutor:
//        Call the defualt constructor for its List.
//        Already implemented.
template<typename Type>
Stack<Type>::Stack():m_list() {}

// 2. push():
//        Add item to the stack in a manor appropriate for
//        Stack behavoir.
//
template<typename Type>
void Stack<Type>::push(Type item) {
    m_list.addToFront(item);
}

// 3. pop():
//        Remove the item on the "top" of the stack.
//
template<typename Type>
void Stack<Type>::pop() {
    m_list.deleteFront();
}

// 4. isEmpty():
//        return true if there are no items in the stack
//        otherwise return false.
//
template<typename Type>
bool Stack<Type>::isEmpty() const {
    /* TODO */
    return false;
}

// 5. peek():
//        Look at the "top" of the stack without changing the
//        Stack itself.
//
template<typename Type>
Type Stack<Type>::peek() const {
    /* TODO */
    Type dumbyVariableSoCodeCompiles_DontActuallyUseThis;
    return dumbyVariableSoCodeCompiles_DontActuallyUseThis;
}

// 6. printStack()
//        Print to console the elements of the stack.
//        Used for debugging.
//
template<typename Type>
void Stack<Type>::printStack() const {
    m_list.printItems();
}
#endif//STACK_H
