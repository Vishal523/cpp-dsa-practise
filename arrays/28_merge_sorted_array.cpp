// Problem: Merge Sorted Array (LeetCode 88)
// Given two integer arrays A and B sorted in non-decreasing order, and two
// integers m and n representing the number of valid elements in A and B,
// merge B into A as one sorted array in-place. A has a total length of m + n,
// with the last n elements set to 0 to accommodate B.
// Example: A =, m = 3, B =, n = 3 -> [1,2,2,3,5,6]
//
// Approach: Three-pointer merge from the back.
//   1. Initialize three pointers at the ends: `i = m - 1` (last valid element
//      in A), `j = n - 1` (last element in B), and `idx = m + n - 1` (end of A).
//   2. While both `i >= 0` and `j >= 0`, compare `A[i]` and `B[j]`. Place the
//      larger value at `A[idx]` and decrement `idx` along with the pointer
//      that provided the value.
//   3. If any elements remain in `B` (`j >= 0`), copy them into the front of `A`.
//      (No cleanup loop is needed for `A`, as its remaining elements are already
//      in their sorted positions.)
//
// Time: O(m + n), each element in A and B is processed once
// Space: O(1), merges in-place inside vector A without extra memory
// Alternative: Copy B into the trailing zeros of A and call `std::sort()`,
//   which is O((m + n) log(m + n)) time and O(1) extra space.

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& A, int m, vector<int>& B, int n) {
    int idx = m+n-1, i = m-1, j = n-1;

    while (i >= 0 && j >= 0) {
        if(A[i] >= B[j]) {
            A[idx] = A[i];
            idx--; i--;
        } else {
            A[idx] = B[j];
            idx--; j--;
        }
    }

    while (j >= 0) {
        A[idx] = B[j];
        idx--; j--;
    }
}

int main() {
    vector<int> A = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> B = {2, 5, 6};
    int n = 3;

    merge(A, m, B, n);

    for (int x : A) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}