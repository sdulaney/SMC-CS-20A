/* WordList source file
*
*
*	This file will contain the function definitions you will implement.
*	The function signitures may NOT be changed.  You may create your own
*	helper functions and include them in this file.
*
*	In addition to the specific instructions for each function, no function
*	should cause any memory leaks or alias m_list in any way that would result
*	in undefined behavior. 
*
*	Topics: Multilevel Arrays, Pointers, Dynamic Allocation, Classes
*
*/


// Don't not include any other libraries
#include"wordlist.h"
#include<iostream>
#include<cstring>


using std::cout;
using std::endl;

using std::strcat;
using std::strcmp;
using std::strcpy;
using std::strlen;


/* Function: Wordlist Constructor
*
*	Constructs an empty Wordlist that is allocated enough space to store 
*	max_words many words.  If max_words is less than 1, set m_list to nullptr
*	and the other member variables should be made consitent with this state.  
*/
WordList::WordList(const int max_words) {
    m_count = 0;
    if (max_words < 1) {
        m_max_words = 0;
        m_list = nullptr;
    }
    else {
        m_max_words = max_words;
        m_list = new char*[m_max_words];
        for (int i = 0; i < m_max_words; i++) {
            m_list[i] = new char[20];
        }
    }
}


/* Function: Wordlist Copy Constructor
*
*	Constructs a Wordlist that is a copy of an existing WordList
*/
WordList::WordList(const WordList &other) {
    m_count = other.m_count;
    m_max_words = other.m_max_words;
    if (m_max_words < 1) {
        m_list = nullptr;
    }
    else {
        m_list = new char*[m_max_words];
        for (int i = 0; i < m_max_words; i++) {
            m_list[i] = new char[20];
        }
        for (int i = 0; i < m_count; i++) {
            // Assumes words will be no more than 19 characters in length (+1 for the null character)
            strcpy(m_list[i], other.m_list[i]);
        }
    }
}


/* Function: Wordlist Destructor
*
*	Cleans up WordList's dynamically allocated memory.
*/
WordList::~WordList() {
    for (int i = 0; i < m_max_words; i++) {
        delete [] m_list[i];
    }
    delete [] m_list;
}

/* Function: printList
*
*	Prints all the words in WordList in a single line with spaces between each
*	word, then followed by a newline after the last word. Returns the number 
*	of words printed.  If m_list is nullptr there is nothing to print, return -1. 
*/
int	WordList::printList() const {
    if (m_list == nullptr) {
        return -1;
    }
    int count = 0;
    for (int i = 0; i < m_count; i++) {
        cout << m_list[i];
        count++;
        if (i == (m_count - 1)) {
            break;
        }
        cout << " ";
    }
    cout << endl;
    return count;
}



/* Function: getAt
*
*	Returns the word at the index position in the WordList.
*	return nullptr if the index is out of bounds.
*/
char* WordList::getAt(const int index) const {
    if ((index < 0) || (index >= m_count)) {
        return nullptr;
    }
    return m_list[index];
}


/* Function: getCount
*
*	Returns the number of words currently stored in WordList.
*/
int	WordList::getCount() const {
    return m_count;
}


/* Function: addWord
*
*	Adds the word into WordList (words have no spaces).  If WordList does not have
*	enough space to add word, addWord will resize with just enough space to allow for 
*	the addition of word. If addWord needed to resize then return 1, otherwise if there 
*	already enough space to add word without resizing, return 0. If word is empty  
*	do nothing return -1. If m_list was nullptr, everything above still holds true except
*	return -2.  
*/
int	WordList::addWord(const char word[]) {
    int result = 0;
    if (word[0] == '\0') {
        return -1;
    }
    if (m_count == m_max_words) {
        if (m_list == nullptr) {
            result = -2;
        }
        else {
            result = 1;
        }
        int temp_max_words = m_max_words + 1;
        char** temp = new char*[temp_max_words];
        for (int i = 0; i < temp_max_words; i++) {
            temp[i] = new char[20];
        }
        for (int i = 0; i < m_count; i++) {
            // Assumes words will be no more than 19 characters in length (+1 for the null character)
            strcpy(temp[i], m_list[i]);
        }
        for (int i = 0; i < m_max_words; i++) {
            delete [] m_list[i];
        }
        delete [] m_list;
        m_list = temp;
        m_max_words = temp_max_words;
    }
    // Assumes words will be no more than 19 characters in length (+1 for the null character)
    strcpy(m_list[m_count], word);
    m_count++;
    return result;
}


/* Function: removeWord
*
*
*	If m_list is nullptr, returns -1.  Otherwise, searches for every
*	occurrence of word[], and removes that word of the list, returns
*	the number of words removed.
*/
int	WordList::removeWord(const char word[]) {
    int result = -1;
    if (m_list == nullptr) {
        return result;
    }
    else {
        result = 0;     // zero words removed
    }
    while (findWord(word) != -1) {
        int index = findWord(word);
        for (int i = index; i < m_count - 1; i++) {
            // Assumes words will be no more than 19 characters in length (+1 for the null character)
            strcpy(m_list[i], m_list[i + 1]);
        }
        m_count--;
        result++;
    }
    return result;
}


/* Function: appendList
*
*
*	Appends the contents of src_list to the WordList.  If WordList does 
*	not have enough space appendList should dynamically allocate enough space
*	to append the contents of src_list to WordList, returns number of words 
*	appended.  If src_list is nullptr or empty appendList does nothing and 
*	returns -1. If this WordList::m_list is nullptr everything above still 
*	holds but returns -2.
*/
int	WordList::appendLists(const WordList* src_list) {
    int result = -1;
    if ((src_list == nullptr) || (src_list->getCount() == 0)) {
        return result;
    }
    if ((m_count + src_list->getCount()) > m_max_words) {
        if (m_list == nullptr) {
            result = -2;
        }
        else {
            result = src_list->getCount();
        }
        int temp_max_words = m_count + src_list->getCount();
        char** temp = new char*[temp_max_words];
        for (int i = 0; i < temp_max_words; i++) {
            temp[i] = new char[20];
        }
        for (int i = 0; i < m_count; i++) {
            // Assumes words will be no more than 19 characters in length (+1 for the null character)
            strcpy(temp[i], m_list[i]);
        }
        for (int i = 0; i < m_max_words; i++) {
            delete [] m_list[i];
        }
        delete [] m_list;
        m_list = temp;
        m_max_words = temp_max_words;
    }
    for (int i = 0; i < src_list->getCount(); i++) {
        // Assumes words will be no more than 19 characters in length (+1 for the null character)
        strcpy(m_list[m_count], src_list->getAt(i));
        m_count++;
    }
    return result;
}


/* Function: findWord
*
*	Finds the first occurrence of the word in the WordList
*	returns the position of that word in the list.  Otherwise, 
*	if the word is not in the WordList or if m_list is nullptr
*	return -1. 
*/
int WordList::findWord(const char word[]) const {
    if (m_list == nullptr) {
        return -1;
    }
    for (int i = 0; i < m_count; i++) {
        if (strcmp(m_list[i], word) == 0) {
            return i;
        }
    }
    return -1;
}


/* Function: sortList
*
*	If m_list is nullptr return -1.  If there is only one word
*	in the list return 1.  Otherwise, sortList sorts the
*	words in WordList in ascending order.  Returns 0 on
*	success.
*/
int	WordList::sortList() {
    if (m_list == nullptr) {
        return -1;
    }
    if (m_count == 1) {
        return 1;
    }
    // Use Bubble Sort algorithm
    for (int i = m_count - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (strcmp(m_list[j], m_list[j + 1]) > 0) {
                // Swap the words
                char temp[20];
                strcpy(temp, m_list[j + 1]);
                strcpy(m_list[j + 1], m_list[j]);
                strcpy(m_list[j], temp);
            }
        }
    }
    return 0;
}


/* Function: Assignment Operator
*
*	Overload the assignment operator for WordList.  Makes a deep 
*	copy from src_list to this WordList.  
*/
WordList& WordList::operator=(const WordList &src_list) {
    if (this == &src_list) {
        return *this;
    }
    for (int i = 0; i < m_max_words; i++) {
        delete [] m_list[i];
    }
    delete [] m_list;
    m_count = src_list.m_count;
    m_max_words = src_list.m_max_words;
    
    if (src_list.m_list == nullptr) {
        m_list = nullptr;
    }
    else {
        m_list = new char*[m_max_words];
        for (int i = 0; i < m_max_words; i++) {
            m_list[i] = new char[20];
        }
        for (int i = 0; i < m_count; i++) {
            // Assumes words will be no more than 19 characters in length (+1 for the null character)
            strcpy(m_list[i], src_list.m_list[i]);
        }
    }
    return *this;
}
