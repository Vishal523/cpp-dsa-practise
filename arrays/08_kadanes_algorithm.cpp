// Problem: Maximum Subarray Sum (Kadane's Algorithm)
// Approach: Keep a running sum. If it drops below 0, reset it to 0,
//           because a negative prefix can only hurt any later subarray.
//           Track the best sum seen so far.
// Time: O(n), Space: O(1)
// Brute force for comparison: O(n^2) (see 07_max_subarray_sum.cpp)

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubarray(vector<int>& nums) {
    int currsum = 0, maxsum = INT_MIN;
    for (int val : nums) {
        currsum += val;
        maxsum = max(currsum, maxsum);

        if(currsum < 0){
            currsum = 0;
        }
    }
    return maxsum;

}

int main() {
    vector<int> nums = {-1, 9, -3, 4, 5};
        
    cout << " the subarray with largest sum = " << maxSubarray(nums) << endl;
    return 0;
}