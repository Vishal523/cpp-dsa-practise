#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int freq = 0, ans = 0;

    for (int i=0; i < nums.size(); i++) {
        if ( freq == 0 ) {
            ans = nums[i];
        }

        if (ans == nums[i]) {
            freq++;
        } else {
            freq--;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {3,1,3,5,3,3,3,3,3,3};
    cout << "the majority element is = " << majorityElement(nums) << endl;
    return 0;
}