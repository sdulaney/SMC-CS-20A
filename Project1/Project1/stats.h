// Stewart Dulaney
// 9/22/2018
// CS 20A Section 4110
// SID: 1545566
// Project 1

#ifndef stats_h
#define stats_h

class Stats {
public:
    // Constructor/destructor
    
    // Initializes the member variables to reflect that there are no births yet.
    Stats();
    // Cleans up the Stats object.
    ~Stats();
    
    // Accessors or Getters
    
    // Prints the stats grid to the console.
    void display() const;
    
    // Mutators or Setters
    
    // Postcondition: Updates the m_stats grid at row r and column c
    // by increasing that cell by val. Returns true if the update is successful.
    // Returns false when the cell already contains the maximum value of '9' or
    // when adding val would result in a sum greater than '9', and nothing is updated
    // in m_stats.
    bool record(int r, int c, int val);
    
private:
    // The stats grid tracks the number of times a cell has been birthed, '.' indicates
    // no change, '1' through '9' indicated the number of times it has been birthed
    // (corresponding to 1 through 9, capping at 9). We are not keeping track of deaths.
    char **m_stats;
};

#endif /* stats_h */
