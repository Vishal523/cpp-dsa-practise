// Problem: Product of Array Except Self
// Given nums, return an array ans where ans[i] is the product of all the
// elements of nums except nums[i]. Division is not allowed.
// Example: [1,2,3,4] -> [24,12,8,6]
//
// Approach: Two passes, using the answer array itself to store the prefix products.
//   Pass 1 (left to right): ans[i] = product of everything to the LEFT of i.
//   Pass 2 (right to left): keep one running variable `suffix` holding the
//           product of everything to the RIGHT of i, and multiply it into ans[i].
//   After both passes, ans[i] = (left product) * (right product), which is
//   the product of everything except nums[i].
//
// Why not divide: dividing the total product by nums[i] fails when the array
//   contains a 0 (division by zero, or wrong results).
//
// Time: O(n), two passes
// Space: O(1) extra space, because the output array does not count
//   (the earlier version with separate prefix and suffix arrays used O(n))
// Brute force: for each i, multiply all the other elements, O(n^2)

#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf (vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);

    // prefix 
    for (int i = 1; i < n; i++) {
        ans[i] = ans [i-1] * nums [i-1];
    }

    // suffix

    int suffix = 1;

    for (int i = n-2 ; i >= 0; i--) {
        suffix *= nums[i+1];
        ans[i] *= suffix;
    }

    return ans;
}

int main() {
    vector<int> nums = {1,2,3,4};
    vector<int> result = productExceptSelf(nums);

    for (int x : result) {
    cout << x << " ";
    }
    cout << endl;

    return 0;
}