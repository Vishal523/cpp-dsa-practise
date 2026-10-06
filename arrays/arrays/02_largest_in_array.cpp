// Find the largest element in the array
// Approach : Single pass, keep the largest value seen so far
// Time : O(n)  Space: O(1)

#include <iostream>
using namespace std;

int main() {
    int num [] = {12, 35, 90, 92, 45};
    int size = 5;
    int largest = INT_MIN;

    for(int i=0; i<size; i++){
        if (num[i]>largest)
            largest = num[i];
    }

    cout << "Largest element = " << largest << endl;
    return 0;
}