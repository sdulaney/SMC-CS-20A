#include <iostream>
#include <string>
#include <assert.h>
#define DEBUGMEMORY
#include"debugmem.h"
using std::cout;
using std::endl;
using std::string;

struct Node {
    int val;
    Node* next;
};

// Problem 1
bool isPalindrome(string s) {
    if (s.length() <= 1) {
        return true;
    }
    if (s[0] == s[s.length() - 1]) {
        if (s.length() == 2) {
            return true;
        }
        else {
            return isPalindrome(s.string::substr(1, s.length() - 2));
        }
    }
    else {
        return false;
    }
}

// Problem 2
// Precondition: b is a nonnegative integer
int mystery1(int a, int b) {
    if (b == 0) return 1;
    if (b % 2 == 0) return mystery1(a*a, b / 2);
    return mystery1(a*a, b / 2) * a;
}

// Problem 3
// Precondition: a and b are nonnegative integers
int mystery2(int a, int b) {
    if (b == 0) return 0;
    if (b % 2 == 0) return mystery2(a + a, b / 2);
    return mystery2(a + a, b / 2) + a;
}

// Problem 4
void printReverse(int arr[], int size) {
    if (size == 0) {
        return;
    }
    if (size == 1) {
        cout << arr[0] << " ";
        return;
    }
    printReverse(arr + size/2, size - size/2);
    printReverse(arr, size/2);
}

// Problem 5
// Precondition: n > 0
int sumOfDigits(int n) {
    if (n < 10) {
        return n;
    }
    else {
        return sumOfDigits(n / 10) + (n % 10);
    }
}

// Problem 6
void deleteList(Node* head) {
    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    deleteList(head);
}

// Problem 7
Node* inPlaceMerge(Node* list1, Node* list2) {
    if ((list1 == nullptr) && (list2 == nullptr)) {
        return nullptr;
    }
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }
    Node* head;
    if (list1->val <= list2->val) {
        head = list1;
        head->next = inPlaceMerge(list1->next, list2);
    }
    else {
        head = list2;
        head->next = inPlaceMerge(list1, list2->next);
    }
    return head;
}

void printItems(Node* head) {
    cout << "Front ";
    Node* p = head;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << "Rear\n";
}

int main() {
    
    cout << "Test Problem 1: isPalindrome" << endl;
    cout << "isPalindrome(\"bob\"): " << isPalindrome("bob") << endl;
    cout << "isPalindrome(\"step on no pets\"): " << isPalindrome("step on no pets") << endl;
    cout << "isPalindrome(\"redivider\"): " << isPalindrome("redivider") << endl;
    cout << "isPalindrome(\"deified\"): " << isPalindrome("deified") << endl;
    cout << "isPalindrome(\"madam\"): " << isPalindrome("madam") << endl;
    
    cout << endl << "Test Problem 2: mystery1" << endl;
    cout << "mystery1(2, 0): " << mystery1(2, 0) << endl;
    cout << "mystery1(2, 1): " << mystery1(2, 1) << endl;
    cout << "mystery1(2, 2): " << mystery1(2, 2) << endl;
    cout << "mystery1(2, 3): " << mystery1(2, 3) << endl;
    cout << "mystery1(-2, 0): " << mystery1(-2, 0) << endl;
    cout << "mystery1(-2, 1): " << mystery1(-2, 1) << endl;
    cout << "mystery1(-2, 2): " << mystery1(-2, 2) << endl;
    cout << "mystery1(-2, 3): " << mystery1(-2, 3) << endl;
    
    cout << endl << "Test Problem 3: mystery2" << endl;
    cout << "mystery2(3, 0): " << mystery2(3, 0) << endl;
    cout << "mystery2(3, 1): " << mystery2(3, 1) << endl;
    cout << "mystery2(3, 2): " << mystery2(3, 2) << endl;
    cout << "mystery2(3, 3): " << mystery2(3, 3) << endl;
    cout << "mystery2(3, 4): " << mystery2(3, 4) << endl;
    cout << "mystery2(3, 5): " << mystery2(3, 5) << endl;
    
    cout << endl << "Test Problem 4: printReverse" << endl;
    int arr1[] = {1, 4, 3, 6};
    cout << "printReverse(arr1, 4): " << endl;
    printReverse(arr1, 4);
    cout << endl;
    int arr2[] = {2, 6, 8, 32, 1};
    cout << "printReverse(arr2, 5): " << endl;
    printReverse(arr2, 5);
    cout << endl;
    
    cout << endl << "Test Problem 5: sumOfDigits" << endl;
    assert(sumOfDigits(9) == 9);
    assert(sumOfDigits(1234) == 10);
    assert(sumOfDigits(9876) == 30);
    assert(sumOfDigits(10294) == 16);
    
    cout << endl << "Test Problem 6: deleteList" << endl;
    Node* head = new Node;
    head->val = 1;
    head->next = new Node;
    head->next->val = 2;
    head->next->next = new Node;
    head->next->next->val = 3;
    head->next->next->next = new Node;
    head->next->next->next->val = 4;
    head->next->next->next->next = nullptr;
    GETMEMORYREPORT();
    cout << endl;
    deleteList(head);
    GETMEMORYREPORT();
    cout << endl;
    
    cout << endl << "Test Problem 7: inPlaceMerge" << endl;
    Node* list1 = new Node;
    list1->val = 1;
    list1->next = new Node;
    list1->next->val = 4;
    list1->next->next = new Node;
    list1->next->next->val = 6;
    list1->next->next->next = new Node;
    list1->next->next->next->val = 8;
    list1->next->next->next->next = nullptr;
    cout << "list1: ";
    printItems(list1);
    Node* list2 = new Node;
    list2->val = 3;
    list2->next = new Node;
    list2->next->val = 9;
    list2->next->next = new Node;
    list2->next->next->val = 10;
    list2->next->next->next = nullptr;
    cout << "list2: ";
    printItems(list2);
    Node* newList = inPlaceMerge(list1, list2);
    printItems(newList);
    
    
    return 0;
}
