// Reverse an Array
// Approach : 2 pointer method
// Time : O(n). Space O(1)

#include <iostream>
using namespace std;

void reverseArray(int arr[], int size ){
    int start = 0; int end = size - 1;

    while (start < end ) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    reverseArray( arr, size );

    for (int i=0;i<size;i++) {
            cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}