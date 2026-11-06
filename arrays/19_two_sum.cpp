// Problem: 2Sum 
//          Given an array of integers and a target sum, find the indices of 
//          the two numbers such that they add up to the target.
//
// Approach: One-pass Hash Map. Iterate through the array once. For each element (first),
//           calculate its complement (sec = tar - first). Check if 'sec' already 
//           exists in the hash map. If found, push the indices to the answer and 
//           break. If not found, insert the current element and its index into the map.
//
// Time Complexity:  O(n) — Single pass through the array. Hash map lookups and 
//                           insertions take O(1) average time.
// Space Complexity: O(n) — In the worst case, we store up to 'n' elements in the 
//                           hash map if no matching pair is found immediately.


#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;

    for (int val : nums) {
        ans ^= val;
    }

    return ans;
}

int main() {
    vector<int> nums = {1,2,1,2,3};
    cout << "single number in the array is = " << singleNumber(nums) << endl;
    return 0;
}