// Problem: Print All Subsets of an Array
// Given an integer array `arr`, print all possible subsets (the power set)
// to the console, including the empty subset.
// Example: arr = {1, 2, 3} -> prints:
//   1 2 3
//   1 2
//   1 3
//   1
//   2 3
//   2
//   3
//   (empty line)
//
// Approach: Recursive Backtracking (Include / Exclude pattern).
//   1. Maintain a working subset vector `ans` (passed by reference) and an
//      index `i` representing the current element being decided in `arr`.
//   2. Base case: When `i == arr.size()`, iterate through `ans` and print its
//      elements separated by spaces, followed by a newline, then return.
//   3. Include branch: Push `arr[i]` into `ans` and recurse for `i + 1`.
//   4. Backtrack: Pop `arr[i]` from `ans` (`ans.pop_back()`) to undo the choice.
//   5. Exclude branch: Recurse for `i + 1` without `arr[i]` in `ans`.
//
// Time: O(n * 2^n), where n is arr.size() (generates 2^n leaf subsets, and
//       printing each subset takes up to O(n) time)
// Space: O(n) auxiliary space for the recursion call stack depth (n) and the
//        temporary `ans` vector (at most n elements)
// Alternative: Iterative bitmasking (loop `mask` from `0` to `(1 << n) - 1`
//   and print `arr[j]` whenever the j-th bit of `mask` is set).


#include<iostream>
#include<vector>
using namespace std;

void printSubsets(vector<int> &arr, vector<int> &ans, int i) {
    if(i == arr.size()) {
        for (int val : ans) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    // include
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i+1);

    ans.pop_back();                     //backtrack
    // exclude
    printSubsets(arr, ans, i+1);

}

    int main() {
        vector<int> arr = {4,5,6};
        vector<int> ans;

        printSubsets(arr, ans, 0);
        return 0;
    }