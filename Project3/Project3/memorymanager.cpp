#include"memorymanager.h"
#include<string>
#include<iostream>
#include<new>
using std::cout;
using std::endl;

class AllocationList {
public:
    
    AllocationList() { head = nullptr; }
    ~AllocationList() {
        Node *p = head;
        while (p != nullptr) {
            Node *n = p->next;
            free( p);
            p = n;
        }
        head = nullptr;
    }
    void printItems() const {
        
        Node* p = head;
        while (p != nullptr) {
            cout << p->addr << " " << p->func << " " << p->line << endl;
            p = p->next;
        }
    }
    
    void    add(void* item, char const* file, char const* func, int line) {
        Node* p = allocateInitNode(item, file, func, line);
        p->next = head;
        head = p;
    }
    bool    deleteItem(void* item) {
        if (head == nullptr) return false;
        if (head->addr == item) {
            Node* killMe = head;
            head = killMe->next;
            free(killMe);
            return true;
        }
        Node *p = head;
        while (p != nullptr) {
            if (p->next != nullptr && p->next->addr == item)
                break;
            
            p = p->next;
        }
        if (p == nullptr) return false;
        
        Node* killMe = p->next;
        p->next = killMe->next;
        free(killMe);
        return true;
    }
    
private:
    struct Node {
        void* addr;
        char const* file;
        char const* func;
        int line;
        
        Node* next;
    };
    
    Node * allocateInitNode(void* addr, char const* file, char const* func, int line, Node* next = nullptr) {
        Node* node = (Node*)std::malloc(sizeof(Node));
        node->addr = addr;
        node->file = file;
        node->func = func;
        node->line = line;
        node->next = next;
        return node;
    }
    
    Node* head;
    
};
//Global :( debugging memory map
AllocationList g_allocList;

void memoryReport() {
    g_allocList.printItems();
}

void* alloc(std::size_t sz, char const* file, char const*  func, int line) {
    void* ptr = std::malloc(sz);
    g_allocList.add(ptr, file, func, line);
    return ptr;
}

void* operator new(std::size_t sz, char const* file, char const*  func, int line) {
    return alloc(sz, file, func, line);
}

void* operator new [](std::size_t sz, char const* file, char const*  func, int line) {
    return alloc(sz, file, func, line);
}

void operator delete(void* ptr) noexcept {
    g_allocList.deleteItem(ptr);
    std::free(ptr);
}
void operator delete [](void* ptr) noexcept {
    g_allocList.deleteItem(ptr);
    std::free(ptr);
}
