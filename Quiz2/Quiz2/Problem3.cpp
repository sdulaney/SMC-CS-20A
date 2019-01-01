//
//  Problem3.cpp
//  Quiz2
//
//  Created by Stewart Dulaney on 11/23/18.
//  Copyright © 2018 Stewart Dulaney. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

// Precondition: n >= 0
int powerThree(int n) {
    if (n == 0) {
        return 1;
    }
    int x = powerThree(n - 1);
    return x + x + x;
}

int main() {
    
    cout << "3^0 = " << powerThree(0) << endl;
    cout << "3^1 = " << powerThree(1) << endl;
    cout << "3^2 = " << powerThree(2) << endl;
    cout << "3^3 = " << powerThree(3) << endl;
    cout << "3^4 = " << powerThree(4) << endl;
    cout << "3^5 = " << powerThree(5) << endl;
    cout << "3^6 = " << powerThree(6) << endl;
    cout << "3^7 = " << powerThree(7) << endl;
    cout << "3^8 = " << powerThree(8) << endl;
    cout << "3^9 = " << powerThree(9) << endl;
    cout << "3^10 = " << powerThree(10) << endl;
    
    
    return 0;
}
