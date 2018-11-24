//
//  Problem2.cpp
//  Quiz2
//
//  Created by Stewart Dulaney on 11/23/18.
//  Copyright © 2018 Stewart Dulaney. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

// Precondition: exp >= 0
int recursivePow(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    return base * recursivePow(base, exp - 1);
}

int main() {
    
    cout << "2^0 = " << recursivePow(2, 0) << endl;
    cout << "2^1 = " << recursivePow(2, 1) << endl;
    cout << "2^2 = " << recursivePow(2, 2) << endl;
    cout << "2^3 = " << recursivePow(2, 3) << endl;
    cout << "2^4 = " << recursivePow(2, 4) << endl;
    cout << "2^5 = " << recursivePow(2, 5) << endl;
    cout << "2^6 = " << recursivePow(2, 6) << endl;
    cout << "2^7 = " << recursivePow(2, 7) << endl;
    cout << "2^8 = " << recursivePow(2, 8) << endl;
    cout << "2^9 = " << recursivePow(2, 9) << endl;
    cout << "2^10 = " << recursivePow(2, 10) << endl;
    
    return 0;
}
