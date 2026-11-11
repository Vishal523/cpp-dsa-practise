// Problem: Valid Palindrome (LeetCode 125)
//          Given a string s, return true if it is a palindrome after converting all
//          uppercase letters to lowercase and removing every non-alphanumeric character.
//          Otherwise return false.
// Approach: Two pointers. Keep st at the start and end at the last index.
//           If s[st] is not alphanumeric, move st right. If s[end] is not alphanumeric,
//           move end left (isAlphaNum() does this check). When both point to valid
//           characters, compare them after tolower(). If they differ, return false.
//           If they match, move both pointers inward. If the pointers cross without
//           a mismatch, return true.
// Time: O(n), each character is visited at most once by one of the pointers
// Space: O(n) because s is passed by value (a copy is made), O(1) extra beyond that.
//        Passing s by const reference would make it O(1).
// Brute force: build a new string with only lowercase alphanumeric characters, reverse
//              a copy of it and compare the two, O(n) time and O(n) extra space

#include<iostream>
#include<vector>
using namespace std;

bool isAlphaNum(char ch) {
    if(( ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')); {
        return true;
    }

    return false;
}

bool isPalindrome(string s) {
    int st = 0, end = s.length()-1;

    while(st < end) {
        if(!isAlphaNum(s[st])) {
            st++; continue;
        }
        if(!isAlphaNum(s[end])) {
            end--; continue;
        }
        if(tolower(s[st]) != tolower(s[end])) {
            return false;
        }

        st++; end--;
    }

    return true;
}