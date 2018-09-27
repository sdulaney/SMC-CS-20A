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
    Stats();
    ~Stats();
    
    // Accessors or Getters
    void display() const;
    
    // Mutators or Setters
    
    // Postcondition: Updates the 2D array m_stats at row r and column c
    // by increasing that cell by val. Returns true if the update is successful.
    // Returns false when the cell already contains the maximum value of 9 or
    // when adding val would result in a sum greater than 9, and nothing is updated
    // in m_stats.
    bool record(int r, int c, int val);
    
private:
    // TODO: You will need to determine what structure is appropriate
    char **m_stats;
};

#endif /* stats_h */
