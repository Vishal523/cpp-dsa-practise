#include<iostream>
#include<vector>
using namespace std;

int singleNum (vector<int>& nums) {
    int ans = 0;

    for (int val : nums) {
        ans ^= val;
    }

    return ans;
}

int main () {
    vector<int> nums = {2, 0, 0, 5, 2};
    cout << "Sinle number in the array = " << singleNum(nums) << endl;
    return 0;
}