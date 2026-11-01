#include<iostream>
#include<vector>
using namespace std;

int maxSubarray(vector<int>& nums) {
    int currSum = 0, maxSum = INT_MIN;

    for(int val : nums) {
        currSum += val;
        maxSum = max(currSum, maxSum);

        if (currSum < 0) {
            currSum = 0;
        }
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-1,2,3,-3,5,4,6,2,-9};
    cout << "max subarray sum = " << maxSubarray(nums) << endl;
    return 0;
}