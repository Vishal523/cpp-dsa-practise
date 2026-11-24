// Problem: Sum of First N Natural Numbers
// Given a positive integer `n`, calculate and return the sum of all natural
// numbers from 1 to n (1 + 2 + ... + n) using recursion.
// Example: n = 9 -> 45
//
// Approach: Linear recursion.
//   1. Base case: When `n == 1`, the sum of the first 1 natural number is 1,
//      so return 1 to stop further recursive calls.
//   2. Recursive step: Return `n + sum(n - 1)`, breaking the problem down
//      into adding `n` to the sum of the first `n - 1` numbers.
//
// Time: O(n), makes n recursive calls from n down to 1, doing O(1) work per call
// Space: O(n), due to the recursion call stack holding n active frames
// Alternative: Use the closed-form arithmetic series formula `n * (n + 1) / 2`
//   for O(1) time and O(1) space, or a `for` loop for O(n) time and O(1) space.
// Assumes n >= 1 (passing n <= 0 will cause infinite recursion / stack overflow).

#include<iostream>
using namespace std;

int sum (int n) {
    if (n == 1) {
        return 1;
    }

    return n + sum(n-1);
}

int main() {
    cout << "sum = " << sum(8) << endl;
}