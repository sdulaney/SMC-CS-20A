/* WordList header file
 *
 *    This file contains the class definition for the WordList.
 *
 *    Do not make any changes to this file.
 *
 *    Do not submit this file
 *
 *    Topics: Multilevel Arrays, Pointers, Dynamic Allocation, Classes
 *
 */
#ifndef WORDLIST_H
#define WORDLIST_H


/* Globally defined constants
 */
const int MAX_WORD_SIZE = 20;


/* Word List ADT
 *
 */
class WordList {
    
public:
    WordList(const int max_words);
    WordList(const WordList &other);
    ~WordList();
    
    int        printList() const;
    
    char*    getAt(const int index) const;
    
    int        getCount() const;
    
    int        addWord(const char word[]);
    
    int        removeWord(const char word[]);
    
    int        appendLists(const WordList* src_list);
    
    int        findWord(const char word[]) const;
    
    int        sortList();
    
    WordList& operator=(const WordList &other);
    
#ifndef MAKE_MEMBERS_PUBLIC
    // If this macro is defined prior to including this header file
    // it will ignore the private access specifier, and the member
    // variables will be follow the above public specifier.
private:
#endif
    
    unsigned int m_count;        // Number of words currently in list
    unsigned int m_max_words;    // The total size of the list.
    char**         m_list;        // The list storing the words
    
};





// Do not worry about any of these preprocessor directives.
#ifdef _MSC_VER  //  Microsoft Visual C++

#define _CRT_SECURE_NO_DEPRECATE

#else  // not Microsoft Visual C++, so assume UNIX interface

#endif


#endif
