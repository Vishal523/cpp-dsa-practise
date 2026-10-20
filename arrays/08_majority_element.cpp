// Problem: Majority Element
// Given an array, find the element that appears more than n/2 times.
// Approach: Sort the array so equal elements sit next to each other.
//           Walk through it counting the length of each run of equal values.
//           As soon as a run's count exceeds n/2, that value is the majority.
// Time: O(n log n) because of sorting, Space: O(1)
// Brute force: count every element with nested loops, O(n^2)
// Better: Moore's Voting Algorithm solves it in O(n) time, O(1) space.

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();

    // sort
    sort(nums.begin(), nums.end());

    // freq count
    int freq = 1, ans = nums[0];
    for (int i = 1; i<n; i++){
        if ( nums[i] == nums[i-1]) {
            freq++;
        }else {
            freq = 1;
            ans = nums[i];
        }
        if (freq > n/2){
            return ans;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {0,1,0};
    cout << "the mojority element is the given arrray is : " << majorityElement(nums) << endl;
}