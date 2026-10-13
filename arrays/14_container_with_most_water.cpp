// C++ program to find the container with the most water (LeetCode 11)
// Approach : Two pointers. Start with the widest container (lp = 0, rp = n-1).
//            Area = width * min(height[lp], height[rp]). Keep the max area,
//            then move the pointer at the shorter line inward, since only a
//            taller line can give a bigger area.
// Time : O(n)  Space : O(1)

#include<iostream>
#include<vector>
using namespace std;

int maxArea (vector<int>& height) {
    int maxWater = 0;
    int lp = 0, rp = height.size() - 1;

    while (lp < rp) {
        int w = rp - lp;
        int ht = min (height[lp], height[rp]);
        int currWater = w * ht;
        maxWater = max(maxWater, currWater);

        height[lp] < height[rp] ? lp++ : rp--;
    }
    
    return maxWater;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Max water = " << maxArea(height) << endl;
    return 0;
}