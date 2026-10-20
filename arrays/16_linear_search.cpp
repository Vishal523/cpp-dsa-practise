// Linear Search
// Aproach : Sequential Search ( Check elements one by one from start to end )
// Time : O(n)  Space : O(1)

#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for(int i=0; i<size; i++){
        if ( arr[i] == target ){
            return i;
        }
    }
    return -1;     // If target not found
}

int main(){
    int arr[] = {1, 67, 34, 13, 98, 56};
    int size = 6;
    int target = 34;

    cout << linearSearch ( arr, size, target ) << endl;
    return 0;
}