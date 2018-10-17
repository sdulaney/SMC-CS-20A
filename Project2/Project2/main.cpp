/* Project 2 main
*
*	Do not submit this file
*
*/

#include<iostream>
#include<cstring>
#include<assert.h>
using std::cout;
using std::endl;

using std::strcat;
using std::strcmp;
using std::strcpy;
using std::strlen;



/* Main functions
*
*	you may make any changes you want to main to test your functions.
*	We will be using our own to grade.
*
*	I'm using preprocessor directives to layout different mains to test
*	various functions.  I have 6 example tests.  You can add or replace, 
*	these are here just to illustrate the technique. Cleaner than 
*	commenting/uncommenting blocks of code.
*
*/

// Choose which test to compile
#define TEST5 //TEST1 TEST2 TEST3 TEST4



#ifdef TEST0 

// Uncomment this to make the WordList member variables public
//#define MAKE_MEMBERS_PUBLIC
#include"wordlist.h"

int main() {

	WordList *wordlist = new WordList(5);

	cout << "Hello World" << endl;

	return 0;
}

#elif defined TEST1  //Test constructor 


//#define MAKE_MEMBERS_PUBLIC
#include"wordlist.h"

int main() {

	WordList *wordlist = new WordList(5);

	// Assuming we made our member variables public:
	cout << "Count: " << wordlist->m_count << endl; // Expect 0

	cout << "Capacity: " << wordlist->m_max_words << endl; // Expect 5


	return 0;
} 
#elif defined TEST2 


//#define MAKE_MEMBERS_PUBLIC
#include"wordlist.h"

// Same as above but using asserts instead of cout
//
// asserts are a way to check conditions, they will gracefully crash
// the program if the condition is not met.  
//
// This assumes you know what the end state after the function call
// should be.  Effective programmers have in mind test cases prior to 
// implmentation.  You should know what the end state should be after
// any function call.
int main() {
	WordList *wordlist = new WordList(5);

	// Assuming we made our member variables public:
	// If we failed to set our member variables correctly 
	// These assertions will fail
	assert(wordlist->m_count == 0);
	assert(wordlist->m_max_words == 5);
	

	return 0;
}
#elif defined TEST3


//#define MAKE_MEMBERS_PUBLIC
#include"wordlist.h"

// Test addWord: Both Constructor and addWord must be
// implmented prior to running this code, otherwise
// it will crash.
int main() {
	WordList *wordlist = new WordList(5);
	wordlist->addWord("harry");
	wordlist->addWord("ron");
	wordlist->addWord("hermione");

	// Assuming we made our member variables public:
	cout  << wordlist->m_list[0][2] << endl; // Expect 'r'

	cout  << wordlist->m_list[1] << endl; // Expect "ron"

	return 0;
}

#elif defined TEST4

//#define MAKE_MEMBERS_PUBLIC
#include"wordlist.h"

// Test addWord: same as TEST3 but with asserts. Both Constructor and addWord 
// must be implmented prior to running this code, otherwise it will crash.
int main() {

	WordList *wordlist = new WordList(4);
	wordlist->addWord("harry");
	wordlist->addWord("ron");
	wordlist->addWord("hermione");
	
	// Assuming we made our member variables public:
	assert(wordlist->m_list[0][2] == 'r' ); // Individual character, can use == 

	assert(strcmp(wordlist->m_list[1], "ron") == 0); // cstring, must use strcmp
    
    assert(wordlist->addWord("neville") == 0);
    assert(wordlist->addWord("") == -1);            // "" is a const char array containing a single \0 character
    assert(wordlist->addWord("draco") == 1);        // addWord needed to resize
    WordList *wordlist2 = new WordList(0);
    assert(wordlist->addWord("dobby") == 1);        // addWord needed to resize, but m_list was nullptr
	
	return 0;
}

#elif defined TEST5

//#define MAKE_MEMBERS_PUBLIC
#include"wordlist.h"

// Test findWord. Both Constructor and addWord must be implmented prior to running
// this code, otherwise it will crash.
int main() {
    WordList *wordlist = new WordList(4);
    wordlist->addWord("Where");
    wordlist->addWord("Is");
    wordlist->addWord("Waldo");
    
    assert(wordlist->findWord("waldo") == -1);
    assert(wordlist->findWord("Where") == 0);
    assert(wordlist->findWord("Is") == 1);
    assert(wordlist->findWord("Waldo") == 2);
    
    WordList *wordlist2 = new WordList(0);
    assert(wordlist2->findWord("testing") == -1);      // m_list is nullptr
    
    return 0;
}

#elif defined TEST6

//#define MAKE_MEMBERS_PUBLIC
#include"wordlist.h"

// Test appendLists. Both Constructor and addWord must be implmented prior to running
// this code, otherwise it will crash.
int main() {
    WordList *wordlist = new WordList(4);
    wordlist->addWord("Where");
    wordlist->addWord("Is");
    wordlist->addWord("Waldo");
    
    WordList *wordlist2 = new WordList(0);
    assert(wordlist->appendLists(wordlist2) == -1);     // wordlist2 is empty
    WordList *wordlist3 = nullptr;
    assert(wordlist->appendLists(wordlist3) == -1);     // wordlist3 is nullptr
    WordList *wordlist4 = new WordList(5);
    wordlist4->addWord("Apple");
    wordlist4->addWord("Banana");
    wordlist4->addWord("Carrot");
    wordlist4->addWord("Donut");
    wordlist4->addWord("Egg");
    assert(wordlist->appendLists(wordlist4) == 5);      // dynamically allocates enough space to append 5 words
    assert(wordlist2->appendLists(wordlist4) == -2);    // dynamically allocates enough space to append 5 words, but m_list was nullptr for wordlist2
    
    return 0;
}

#elif defined TEST7

//#define MAKE_MEMBERS_PUBLIC
#include"wordlist.h"

// Test getAt. Both Constructor and addWord must be implmented prior to running
// this code, otherwise it will crash.
int main() {
    WordList *wordlist = new WordList(4);
    wordlist->addWord("Where");
    wordlist->addWord("Is");
    wordlist->addWord("Waldo");
    
    assert(wordList->getAt(-1) == nullptr);             // index is out of bounds
    assert(wordList->getAt(4) == nullptr);              // index is out of bounds
    assert(strcmp(wordList->getAt(0), "Where") == 0);
    assert(strcmp(wordList->getAt(1), "Is") == 0);
    assert(strcmp(wordList->getAt(2), "Waldo") == 0);
    
    return 0;
}


#else


//#define MAKE_MEMBERS_PUBLIC
#include"wordlist.h"

// Test: printList(): Constructor, addWord, printList must be implmented prior to 
// running this code, otherwise it will crash.
int main() {

	WordList *wordlist = new WordList(5);
	wordlist->addWord("harry");
	wordlist->addWord("ron");
	wordlist->addWord("hermione");

	assert(wordlist->printList() == 3);             // returns the number of words printed
    WordList *wordlist2 = new WordList(0);
    assert(wordlist2->printList() == -1);           // returns -1 because m_list is equal to nullptr

	return 0;
}

#endif
