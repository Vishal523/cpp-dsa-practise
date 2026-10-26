
// Problem: Find the Duplicate Number (LeetCode 287)
//          Array of n+1 integers, each in range [1, n]. Exactly one number repeats
//          (it can repeat more than twice). Find it without modifying the array
//          and using only O(1) extra space.
// Approach: Floyd's cycle detection (tortoise and hare).
//           Treat the array as a linked list where index i points to arr[i].
//           Since values are in [1, n], index 0 is never pointed to, so the walk
//           starting at arr[0] must enter a cycle. The duplicate is the cycle entry.
//           Phase 1: slow moves 1 step, fast moves 2 steps, until they meet in the cycle.
//           Phase 2: reset slow to the start, move both 1 step, they meet at the duplicate.
// Time: O(n), Space: O(1)
// Brute force: sort and check neighbours, O(n log n). Or hash set, O(n) time but O(n) space.

#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& arr) {
    int slow = arr[0], fast = arr[0];
    
    do {
        slow = arr[slow];       //+1
        fast = arr[arr[fast]];  //+2
    } while (slow != fast);

    slow = arr[0];

    while (slow != fast) {
        slow = arr[slow];       //+1
        fast = arr[fast];       //+1
    }

    return slow;
}

int main() {
    vector<int> arr = {1, 3, 4, 2, 2};
    cout << findDuplicate(arr) << endl;     // prints 2
    vector<int> arr2 = {3, 1, 3, 4, 2};
    cout << findDuplicate(arr2) << endl; 
    vector<int> arr2 = {5, 3, 6, 9, 0};
    cout << findDuplicate(arr2) << endl;    // prints 3
    return 0;
}
