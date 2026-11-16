    // Problem: Reverse String (LeetCode 344)
// Write a function that reverses a string. The input string is given as an
// array of characters s. You must do this by modifying the input array
// in-place with O(1) extra memory.
// Example: s = ['h','e','l','l','o'] -> ['o','l','l','e','h']
//
// Approach: Two-pointer in-place swap.
//   1. Initialize two pointers: `st` at the start (0) and `end` at the last
//      index (s.size() - 1).
//   2. While `st < end`, swap the characters at `s[st]` and `s[end]`.
//   3. Increment `st` and decrement `end` (handled post-swap via `st++` and
//      `end--`) until the pointers meet or cross in the middle.
//
// Time: O(n), where n is s.size() (performs n/2 swaps, touching each element once)
// Space: O(1), since `s` is passed by reference (`vector<char>&`) and modified
//        in-place without allocating extra data structures
// Alternative: Use the built-in `std::reverse(s.begin(), s.end())` from
//   `<algorithm>`, or solve recursively (which uses O(n) call-stack space).


#include<iostream>
    #include<vector>
    #include<string>
    using namespace std;

    void reverseString(vector<char>& s ) {
        int st = 0, end = s.size() - 1;

        while (st < end) {
            swap(s[st++], s[end--]);
        }
    }