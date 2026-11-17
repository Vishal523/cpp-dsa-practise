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