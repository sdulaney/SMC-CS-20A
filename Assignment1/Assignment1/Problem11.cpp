// Stewart Dulaney
// 9/19/2018
// CS 20A Section 4110
// SID: 1545566
// Assignment 1
// Problem 11
#include <iostream>

void compareCstrings(const char str1[], const char str2[], int &count);

int main() {
    
    int count = 0;
    compareCstrings("tacocat", "TACOCAT", count);   // should set count to 0
    std::cout << count << std::endl;
    compareCstrings("Harry", "Malfoy", count);      // should set count to 1
    std::cout << count << std::endl;
    compareCstrings("SMC","SBCC", count);           // should set count to 2
    std::cout << count << std::endl;
    
    return 0;
}

void compareCstrings(const char str1[], const char str2[], int &count) {
    count = 0;
    int index = 0;
    while ((str1[index] != '\0') && (str2[index] != '\0')) {
        if (str1[index] == str2[index])
            count++;
        index++;
    }
}
