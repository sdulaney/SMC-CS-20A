#include"tests.h"
#include"bst.h"
#include<list>
#include<vector>
#include<set>
#include<unordered_set>
#include <random>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <locale>


using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::set;
using std::unordered_set;


//Class to handle timing
class Timer {
public:
    void start() { ref_start = highc.now(); }
    void stop() { duration = std::chrono::duration_cast<std::chrono::nanoseconds>(highc.now() - ref_start).count(); }
    void report() { cout << "\tTime: " << duration << " ns" << endl; }
    void report(int size) { cout << "\tTime/element: " << duration / size << " ns/element" << endl; }
    long long getDuration() { return duration; }
private:
    std::chrono::high_resolution_clock highc;
    std::chrono::high_resolution_clock::time_point ref_start;
    long long duration;
};


void test_insert(int test_size) {
    
    // Create an array for to insert into data structures
    vector<int> input_vector;
    
    for (int i = 0; i < test_size; i++) {
        input_vector.push_back(i);
    }
    
    //Shuffle the elements randomly
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(input_vector.begin(), input_vector.end(), g);
    
    Timer timer;
    
    // Data structures
    // List<int> list;
    // SortedLinkeList slist;
    BinarySearchTree bst1, bst2;
    
    set<int> stltreeset1;
    unordered_set<int> stlhashset1, stlhashset2;
    stlhashset1.reserve(1);
    stlhashset2.reserve(10 * test_size); // Low Load factor
    
    list<int> stlList1, stlList2;
    vector<int> stlvec1, stlvec2;
    
    cout << endl << "-------------- Testing Insert " << test_size << " ---------------" << endl;
    
    { // Test Insertions
        
        //Start timing
        //
        cout << endl << "Testing bst insertions random: " << endl;
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            bst1.insert(input_vector[i]);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        cout << endl << "Testing bst insertions in order: " << endl;
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            bst2.insert(i);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        cout << endl << "Testing stl linked list insertions back: " << endl;
        //Start timing
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            stlList1.push_back(input_vector[i]);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        cout << endl << "Testing stl linked list insertions front: " << endl;
        //Start timing
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            stlList2.push_front(input_vector[i]);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        
        cout << endl << "Testing stl vector insertions back: " << endl;
        //Start timing
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            stlvec1.push_back(input_vector[i]);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        cout << endl << "Testing stl vector insertions front: " << endl;
        //Start timing
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            stlvec2.insert(stlvec2.begin(), input_vector[i]);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        
        cout << endl << "Testing stl tree based set insertions: " << endl;
        //Start timing
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            stltreeset1.insert(input_vector[i]);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        cout << endl << "Testing stl hash based set insertions (high load factor): " << endl;
        //Start timing
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            stlhashset1.insert(input_vector[i]);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        cout << endl << "Testing stl hash based set insertions (low load factor): " << endl;
        //Start timing
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            stlhashset2.insert(input_vector[i]);
        
        // End timing
        timer.stop();
        timer.report(test_size);
    }
}
void test_search(int test_size) {
    // Create an array for to insert into data structures
    vector<int> input_vector;
    for (int i = 0; i < test_size; i++) {
        input_vector.push_back(i);
    }
    //Shuffle the elements randomly
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(input_vector.begin(), input_vector.end(), g);
    
    Timer timer;
    
    // Data structures
    // List<int> list;
    // SortedLinkeList slist;
    BinarySearchTree bst1, bst2;
    set<int> stltreeset1;
    unordered_set<int> stlhashset1, stlhashset2;
    stlhashset1.reserve(1);
    stlhashset2.reserve(10 * test_size); // Low Load factor
    
    list<int> stlList1;
    vector<int> v1;
    
    //Populate for searching
    for (int i = 0; i < input_vector.size(); i++) {
        bst1.insert(input_vector[i]);
        stlList1.push_back(input_vector[i]);
        v1.push_back(input_vector[i]);
        stltreeset1.insert(input_vector[i]);
        stlhashset1.insert(input_vector[i]);
        stlhashset2.insert(input_vector[i]);
        bst2.insert(i);
    }
    
    cout << endl << "-------------- Testing Search " << test_size << " ---------------" << endl;
    
    { // Test Search
        
        //Start timing
        //
        cout << endl << "Testing bst search randomly inserted: " << endl;
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            bst1.search(input_vector[i]);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        cout << endl << "Testing bst search inserted in order: " << endl;
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            bst2.search(input_vector[i]);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        cout << endl << "Testing stl linked list searching using algorithm find: " << endl;
        //Start timing
        for (int i = 0; i < input_vector.size(); i++)
            std::find(stlList1.begin(), stlList1.end(), i);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        cout << endl << "Testing stl linked list searching using iterator/compare: " << endl;
        //Start timing
        
        for (int i = 0; i < input_vector.size(); i++)
            for (list<int>::iterator it = stlList1.begin(); it != stlList1.end(); it++)
                if (*it == input_vector[i])
                    break;
        
        
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        
        cout << endl << "Testing stl vector searching using algorithm find:" << endl;
        //Start timing
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            std::find(v1.begin(), v1.end(), i);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        
        cout << endl << "Testing stl vector sorting first then binary search:" << endl;
        //Start timing
        timer.start();
        
        std::sort(v1.begin(), v1.end());
        for (int i = 0; i < input_vector.size(); i++)
            std::binary_search(v1.begin(), v1.end(), i);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        
        cout << endl << "Testing stl tree based set search: " << endl;
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            stltreeset1.find(input_vector[i]);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        cout << endl << "Testing stl hash based set search (high load factor): " << endl;
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            stlhashset1.find(input_vector[i]);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        cout << endl << "Testing stl hash based set search (low load factor): " << endl;
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            stlhashset2.find(input_vector[i]);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
    }
    
}
void test_delete(int test_size) {
    // Create an array for to insert into data structures
    vector<int> input_vector;
    for (int i = 0; i < test_size; i++) {
        input_vector.push_back(i);
    }
    //Shuffle the elements randomly
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(input_vector.begin(), input_vector.end(), g);
    
    Timer timer;
    
    // Data structures
    // List<int> list;
    // SortedLinkeList slist;
    BinarySearchTree bst;
    set<int> stltreeset1;
    unordered_set<int> stlhashset1;
    
    list<int> stlList1;
    vector<int> v1;
    
    //Populate for searching
    for (int i = 0; i < input_vector.size(); i++) {
        bst.insert(input_vector[i]);
        stlList1.push_back(input_vector[i]);
        v1.push_back(input_vector[i]);
        stltreeset1.insert(input_vector[i]);
        stlhashset1.insert(input_vector[i]);
    }
    
    cout << endl << "-------------- Testing Delete " << test_size << " ---------------" << endl;
    
    { // Test Search
        
        //Start timing
        //
        cout << endl << "Testing bst delete: " << endl;
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            bst.remove(input_vector[i]);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        cout << endl << "Testing stl linked list delete: " << endl;
        //Start timing
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            stlList1.erase(std::find(stlList1.begin(), stlList1.end(), i));
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        
        cout << endl << "Testing stl vector delete:" << endl;
        //Start timing
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            v1.erase(std::find(v1.begin(), v1.end(), i));
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        
        
        cout << endl << "Testing stl tree based set delete: " << endl;
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            stltreeset1.erase(input_vector[i]);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
        cout << endl << "Testing stl hash based set delete: " << endl;
        timer.start();
        
        for (int i = 0; i < input_vector.size(); i++)
            stlhashset1.erase(input_vector[i]);
        
        // End timing
        timer.stop();
        timer.report(test_size);
        
    }
    
}
