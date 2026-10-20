// Problem: Majority Element (Moore's Voting Algorithm)
// Approach: Keep a candidate and a count. Matching element: count++.
//           Different element: count--. When count hits 0, pick a new candidate.
//           Different elements cancel out, so the majority survives.
// A second pass verifies the candidate; returns -1 if no majority exists.
// Time: O(n), Space: O(1)
// Assumes a majority element always exists.

#include<iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
   int  freq = 0, ans = 0;

   for(int i=0; i < nums.size(); i++) {
    if (freq == 0) {
        ans = nums[i];
    }
    if ( ans == nums[i]){
        freq++;
    }else{
        freq--;
    }
   }

   // Verification: check that ans really appears more than n/2 times
    int count = 0;
    for (int val : nums) {
        if (val == ans) {
            count++;
        }
    }

    if (count > nums.size() / 2) {
        return ans;
    } else {
        return -1;
    }

   return ans;
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums) << endl;
    return 0;
}