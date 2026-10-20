// A function to print a single/unique number
// Approach : Use the Bitwise ( ^ ) operator to find the unique element
//            - X ^ X = 0 ( Duplicates cancel out )
//            - X ^ 0 = X ( Unique number remains )
// Time : O(1)  Space : O(1)

#include<iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;

    for(int val : nums) {
        ans = ans ^ val;        // Bitwise XOR operation
    }
    return ans;
}

int main () {
    vector<int> nums= {5,3,4,3,4};
    
    cout << singleNumber(nums) << endl;

    return 0;

}