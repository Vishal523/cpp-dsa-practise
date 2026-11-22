// Problem: Subsets / Power Set (LeetCode 78)
// Given an integer array `nums` of unique elements, return all possible
// subsets (the power set). The solution set must not contain duplicate
// subsets, and the subsets can be returned in any order.
// Example: nums = [1, 2, 3] -> [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
//
// Approach: Recursive Backtracking (Include / Exclude pattern).
//   1. Maintain a current subset vector `ans` and an index `i` tracking the
//      current element in `nums`.
//   2. Base case: When `i == nums.size()`, all elements have been decided, so
//      push the current subset `ans` into `allSubsets` and return.
//   3. Include branch: Add `nums[i]` to `ans` (`push_back`) and recurse for `i + 1`.
//   4. Backtrack: Remove `nums[i]` from `ans` (`pop_back`) to restore state.
//   5. Exclude branch: Recurse for `i + 1` without including `nums[i]`.
//
// Time: O(n * 2^n), where n is nums.size() (there are 2^n subsets, and copying
//       each subset of average length n/2 into `allSubsets` takes O(n) time)
// Space: O(n) auxiliary recursion stack and `ans` buffer depth (O(n * 2^n)
//        including the output vector `allSubsets`)
// Alternative: Iterative cascading (start with `[[]]` and for each number in
//   `nums`, append it to every existing subset) or bit manipulation (iterating
//   masks from `0` to `2^n - 1`).
// Note: Change `getAllSubsets` return type from `int` to `void` (since line 8
//       uses `return;`) and pass `allSubsets` by reference (`vector<vector<int>>&`)
//       so collected subsets persist back to `subsets()`.

#include<iostream>
#include<vector>
using namespace std;

int getAllSubsets(vector<int>& nums, vector<int> &ans, int i, vector<vector<int>> allSubsets) {
    if (i == nums.size()) {
        allSubsets.push_back({ans});
        return;
    }

    // include
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i+1, allSubsets);

    ans.pop_back();

    // exclude
    getAllSubsets(nums, ans, i+1, allSubsets);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> allSubsets;
    vector<int> ans;

    getAllSubsets(nums, ans, 0, allSubsets);

    return allSubsets;
}