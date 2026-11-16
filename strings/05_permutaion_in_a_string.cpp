// Problem: Permutation in String (LeetCode 567)
// Given two strings s1 and s2, return true (1) if s2 contains a permutation
// of s1, or false (0) otherwise. In other words, return true if one of s1's
// permutations is a substring of s2.
// Example: s1 = "ab", s2 = "eidbaooo" -> true ("ba" is a permutation of "ab")
//
// Approach: Fixed-size window frequency matching.
//   1. Build a frequency array `freq[26]` counting occurrences of each lowercase
//      letter ('a'-'z') in `s1`.
//   2. Set `windSize = s1.length()`. Iterate through each starting index `i` in `s2`.
//   3. For each starting index `i`, initialize a fresh `windFreq[26]` array and
//      count the characters of the substring of length `windSize` starting at `i`
//      (using `windIdx` and `idx`).
//   4. Compare `freq` and `windFreq` using `isFreqSame()`. If all 26 character
//      counts match, a valid permutation substring was found—return true.
//   5. If no window matches after checking all starting indices, return false.
//
// Time: O(n * m), where n = s2.length() and m = s1.length() (for each of the n
//       starting positions, up to m characters are scanned and 26 counts compared)
// Space: O(1), since both frequency arrays (`freq` and `windFreq`) have a fixed
//        size of 26 regardless of input length
// Alternative: Instead of rebuilding `windFreq` from scratch at every index `i`,
//   slide the window by 1 character at a time (add the entering right character,
//   remove the leaving left character) to bring time complexity down to O(n + m).
// Assumes s1 and s2 consist only of lowercase English letters ('a'-'z').


#include<iostream>
using namespace std;

bool isFreqSame(int freq1[], int freq2[]) {
    for (int i=0; i<26; i++) {
        if(freq1[i] != freq2[i]) {
            return false;
        }
    }

    return true;
}

int checkInclusion(string s1, string s2) {
    int freq[26] = {0};
    for (int i=0; i<s1.length(); i++) {
        freq[s1[i] - 'a']++;                //int idx = s1[i] - 'a';
    }

    int windSize = s1.length();

    for (int i=0; i<s2.length(); i++) {
        int windIdx=0, idx=i;
        int windFreq[26] = {0};

        while(windIdx < windSize && idx < s2.length()) {
            windFreq[s2[idx]-'a']++;
            windIdx++; idx++;
        }

        if(isFreqSame(freq, windFreq)) {
            return true;
        }
    }

    return false;
}