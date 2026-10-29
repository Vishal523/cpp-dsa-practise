// Problem: 3Sum (LeetCode 15)
//          Find all unique triplets in the array that add up to 0.
//          The answer must not contain duplicate triplets.
// Approach: Sort the array, then fix one number (i) and use two pointers (j, k)
//           on the rest. If the sum is too small, move j right. If it is too big,
//           move k left. If it is 0, store the triplet and move both pointers.
//           Skip repeated values of i and j so no duplicate triplet is added.
// Time: O(n^2), Space: O(1) extra (ignoring the answer)
// Brute force: three nested loops plus a set to remove duplicates, O(n^3)

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i=0; i<n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i+1; k = n - 1;

        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum< 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++, k--;

                while(j < k && nums[j] = nums[j-1]) j++;
            }
        }
    }

    return ans;
}

// Example question:
// Input:  nums = [-1, 0, 1, 2, -1, -4]
// Output: [[-1, -1, 2], [-1, 0, 1]]
// Explanation: -1 + -1 + 2 = 0 and -1 + 0 + 1 = 0. The two triplets are different.
int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);

    for (auto& t : ans) {
        cout << t[0] << " " << t[1] << " " << t[2] << endl;
    }
    return 0;
}