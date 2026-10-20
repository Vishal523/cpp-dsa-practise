// Problem: Pair Sum (Two Sum on a sorted array)
// Given a sorted array and a target, return the indices of the two
// numbers that add up to the target.
// Approach: Two pointers. Start with i at the beginning and j at the end.
//           - If nums[i] + nums[j] > target, move j left (need a smaller sum)
//           - If nums[i] + nums[j] < target, move i right (need a bigger sum)
//           - If equal, return the pair of indices
//           This only works because the array is sorted.
// Time: O(n), Space: O(1)
// Brute force for comparison: two nested loops, O(n^2)


#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int>& nums, int target) {
    vector<int> ans;
    int n = nums.size();
    
    int i=0, j=n-1;
    while (i<j){
        int pairSum = nums[i] + nums [j];
            if(pairSum > target) {
                j--;
            }else if (pairSum < target ){
                i++;
            }else {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
    }
    return ans;

}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 26;
        
    vector<int> ans = pairSum(nums, target);
    cout << ans[0] << " , "<< ans[1] << endl;
    return 0;
}