// Problem: Binary Search (recursive)
// Given a sorted array and a target, return the index of the target,
// or -1 if it is not present.
// Approach: Compare the target with the middle element.
//           - Equal: found, return mid.
//           - Target is bigger: search the right half (mid + 1 .. end).
//           - Target is smaller: search the left half (st .. mid - 1).
//           If st > end, the range is empty and the target is not present.
//           Each call halves the search range.
// Time: O(log n)
// Space: O(log n) for the recursion call stack
//        (the iterative version needs only O(1))
// Brute force: linear search, O(n)

#include<iostream>
#include<vector>
using namespace std;

int recBinarySearch(vector<int>& arr, int tar, int st, int end) {
    if (st <= end) {
        int mid = st + (end - st)/2;

        if (tar > arr[mid]) {
            return recBinarySearch(arr, tar, mid + 1, end);
        } else if (tar < arr [mid]) {
            return recBinarySearch(arr, tar, st, mid-1);
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12};
    int tar1 = 0;

    cout << recBinarySearch(arr1, tar1, 0, (int)arr1.size() - 1) << endl;
}