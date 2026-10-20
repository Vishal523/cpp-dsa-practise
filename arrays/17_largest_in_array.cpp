// Find the largest element in the array
// Approach : 
// Time : 

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