// Problem: Sort Colors / Sort an Array of 0s, 1s, and 2s (LeetCode 75)
// Given an array `nums` with n objects colored red, white, or blue (represented
// by integers 0, 1, and 2), sort them in-place so that objects of the same
// color are adjacent, in the order 0, 1, and 2.
// Example: nums = [2, 0, 2, 1, 1, 0] -> [0, 0, 1, 1, 2, 2]
//
// Approach: Dutch National Flag Algorithm (three-pointer single pass).
//   1. Maintain three pointers: `low = 0` (boundary for 0s), `mid = 0`
//      (current element being inspected), and `high = n - 1` (boundary for 2s).
//   2. Loop while `mid <= high`:
//      - If `nums[mid] == 0`: swap `nums[low]` and `nums[mid]`, then increment
//        both `low` and `mid`.
//      - If `nums[mid] == 1`: it is already in the middle region, so just
//        increment `mid`.
//      - If `nums[mid] == 2`: swap `nums[high]` and `nums[mid]`, then decrement
//        `high` (do not increment `mid`, as the swapped element from `high`
//        still needs to be checked).
//
// Time: O(n), where n is nums.size() (each element is examined at most once)
// Space: O(1), sorts `nums` in-place via reference without extra memory
// Alternative: Two-pass counting sort (count occurrences of 0, 1, and 2, then
//   overwrite the array), which is also O(n) time and O(1) space.


#include<iostream>
#include<vector>
using namespace std;

void sortCColour(vector<int>& nums) {       // Dutch National Flag Algorithm
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;

    while (mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            mid++; low++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[high], nums[mid]);
            high--;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortCColour(nums);

    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}