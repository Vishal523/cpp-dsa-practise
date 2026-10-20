// Find the smallest element in the array
// Approach : Single pass, keep the smallest value seen so far 
// Time : O(n)   Space : O(1)

#include <iostream>
using namespace std;

int main() {
    int num [] = {87, 15, 34, 1, 5, 98};
    int size = 6;

    int smallest = INT_MAX;

    for(int i=0; i<size; i++) {
        if (num[i] < smallest) {
            smallest = num [i];
        }
    }

    cout << " smallest = " << smallest << endl;
    return 0;
}
