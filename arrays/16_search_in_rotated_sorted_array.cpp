// Problem: Search in Rotated Sorted Array
// Given a sorted array that was rotated at some pivot (e.g. [4,5,6,7,0,1,2])
// and a target, return the target's index, or -1 if it is not present.
// Assumes all values are distinct.
// Approach: Modified binary search. After finding mid, at least one half is
//           always sorted.
//           - If nums[st] <= nums[mid], the left half is sorted. If the target
//             lies inside that range, search left (end = mid - 1), else right.
//           - Otherwise the right half is sorted. If the target lies inside
//             that range, search right (st = mid + 1), else left.
// Time: O(log n), Space: O(1)
// Brute force: linear search, O(n)

#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int st = 0, end = nums.size() - 1;

    while ( st <= end ) {
        int mid = st + (end - st)/2 ;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[st]<= nums[mid]) {
            if(nums[st] <= target && target <= nums[mid]) { // left sorted
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        } else { // right sorted
            if ( nums[mid] <= target && target <= nums[end]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1;

}

int main () {
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << search (nums, 0) << endl;
    return 0;
}