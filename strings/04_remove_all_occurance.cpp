// Problem: Remove All Occurrences of a Substring (LeetCode 1910)
//          Given strings s and part, repeatedly find the leftmost occurrence of part
//          in s and remove it, until part no longer appears in s.
//          Return s after all removals.
// Approach: Simulation. Use s.find(part) to get the index of the leftmost occurrence.
//           While it exists (find() < s.length(), since find() returns npos, a huge
//           value, when nothing is found), erase part.length() characters from that
//           index. Removing a part can join the characters around it into a new
//           occurrence, which is why we keep searching from the start in a loop.
// Time: O(n^2) worst case. There are at most n / m removals (m = part.length()),
//       and each round costs O(n * m) for find() plus O(n) for erase().
// Space: O(n) because s is passed by value (a copy is made), O(1) extra beyond that.
//        Passing s by reference would make it O(1).
// Alternative: Stack / string-as-stack approach, push characters one by one and pop
//              part when the top matches it, O(n * m)

#include<iostream>
#include<vector>
using namespace std;

string removeOccurances(string s, string part) {
    while (s.length() > 0 && s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }

    return s;
}