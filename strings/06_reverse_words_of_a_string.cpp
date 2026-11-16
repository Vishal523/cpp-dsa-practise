// Problem: Reverse Words in a String (LeetCode 151)
// Given a string s, reverse the order of the words. A word is a run of
// non-space characters. The result must have the words separated by exactly
// one space, with no leading or trailing spaces, even if s has extra spaces.
// Example: "  hello   world  " -> "world hello"
//
// Approach: Reverse the whole string, then reverse each word back.
//   1. reverse(s) puts the words in the opposite order, but every word is
//      also reversed ("the sky" -> "yks eht").
//   2. Scan the reversed string and pick out each word (skipping spaces).
//   3. Reverse that word again so it reads normally, and append it to ans
//      with a space in front of it.
//   4. The first word added also has a leading space, so ans.substr(1)
//      removes it at the end.
//   Skipping empty words is what removes the extra spaces.
//
// Time: O(n), each character is visited a constant number of times
// Space: O(n) for ans and the word buffer (s is passed by value, so the
//        original string is not modified)
// Alternative: split into words with stringstream and join them from the
//   end, also O(n). Or do it in place with two pointers for O(1) extra space.
// Assumes s has at least one word (LeetCode guarantees this).

#include<iostream>
using namespace std;

string reverseWords(string s) {
    int n = s.length();
    string ans = "";

    reverse(s.begin(), s.end());

    for (int i=0; i<n; i++) {
        string word = "";
        while(i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());
        if(word.length() > 0) {
            ans += " " + word;
        }
    }

    return ans.substr(1);
}