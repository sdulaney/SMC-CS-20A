#include<iostream>
using namespace std;

class Node {
public:
    int  value;
    Node* next;
    Node* prev;
};

void swap(int& a, int& b) {
    int t = a;      a = b;       b = t;
}

//Print the nodes in the linked list starting with node
void display(Node* node) {
    Node *disp = node;
    while (disp != nullptr)
    {
        cout << " " << disp->value;
        disp = disp->next;
    }
    cout << endl;
}

//Non object oriented addToFront, we need to pass in the address to the first
//Node and then add a new Node before it.  We then return the address to the new
//first node, which will be assigned back to the the head pointer in the calling
//function (main)
Node* addToFront(Node* node, int x) {
    // If the list is empty
    if (node == nullptr) {
        node = new Node;
        node->value = x;
        node->next = nullptr;
        node->prev = nullptr;
    }
    else {
        Node *n = new Node;
        n->value = x;
        n->next = node;
        n->prev = nullptr;
        
        node->prev = n;
        node = n;
    }
    return node;
}


Node* partition(Node *low, Node *high) {
    
    return nullptr;
}

int main() {
    //Create an empty list
    Node* head = nullptr;
    
    //Add one node to the empty list
    head = addToFront(head, 56);
    
    //Reconcile the tail, only one node at this point
    //so both the head and tail point to the same Node
    Node* tail = head;
    
    //Now any further additions to the front will not
    //require any changes to the tail.
    head = addToFront(head, 47);
    head = addToFront(head, 35);
    head = addToFront(head, 12);
    head = addToFront(head, 4);
    head = addToFront(head, 40);
    head = addToFront(head, 52);
    head = addToFront(head, 99);
    head = addToFront(head, 13);
    head = addToFront(head, 77);
    head = addToFront(head, 1);
    head = addToFront(head, 30);
    
    //List identical to initial array-values in slides
    cout << "Element In The Linked List Are : ";
    display(head);
    
    Node* pivot = partition(head, tail);
    
    if (pivot!=nullptr) cout <<"Pivot: "<< pivot->value << endl; // 30
    
    cout << "Element In The Linked List Are : ";
    display(head); //4 1 12 13 30 52 40 99 77 35 47 56
    
}
