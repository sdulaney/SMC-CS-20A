// Stewart Dulaney
// 9/19/2018
// CS 20A Section 4110
// SID: 1545566
// Assignment 1
// Problem 12
#include <iostream>
#include <string>

int foo(int a, int b);                      // First
char foo(std::string a, int b);             // Second
std::string foo(int b, std::string &a);     // Third
 
int main() {
    
    int last_sid = 6;   // Last digit of your SID
    std::string letters("ggfiorkcboneat !!!ws adtarojot");
    std::string output("");
    int numbers[] = {0,8,3,7,4,6,9,1,2,5};
    
    for (int i = 0; i < 10; i++) {
        int j = numbers[i];
        numbers[i] = foo(last_sid, i);
        std::string s = foo(j, letters);
        output += foo(s, numbers[i]);
        
        // check part c)
        if (i == 1) {
            std::cout << "At the end of the second iteration, the string letters contains \"" << letters << "\"." << std::endl;
        }
    }
    // check part d)
    std::cout << "At the end of the program, the numbers array looks like ";
    for (int i = 0; i < 10; i++) {
        std::cout << numbers[i];
    }
    std::cout << ".\n";
    
    // check part f)
    std::cout << output;
    
    return 0;
}

int foo(int a, int b) {                     // First
    int c = a + b;
    while (c >= 3)
        c -= 3;
    return c;
}

char foo(std::string a, int b) {            // Second
    return a[b];
}

std::string foo(int b, std::string &a) {    // Third
    std::string sub = a.substr(3 * b, 3);
    a.replace(3 * b, 3, "...");
    return sub;
}
