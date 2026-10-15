// Problem: Product of Array Except Self
// Given nums, return an array where ans[i] is the product of all elements
// except nums[i]. Division is not allowed.
// Approach: Prefix and suffix products.
//           prefix[i] = product of everything to the left of i
//           suffix[i] = product of everything to the right of i
//           ans[i] = prefix[i] * suffix[i]
//           Division would fail when the array contains a 0, so we avoid it.
// Time: O(n), Space: O(n) for the prefix and suffix arrays
// Better: compute prefix straight into ans, then multiply a running suffix
//         variable from the right. That uses O(1) extra space.

#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);

    // prefix
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] * nums[i-1];
    }

    // suffix
    for (int i = n-2; i >= 0; i--) {
        suffix[i] = suffix[i+1] * nums[i+1];
    }

    // ans
    for (int i = 0; i < n; i++) {
        ans[i] = prefix[i] * suffix[i];
    }

    return ans;
}

int main() {
    vector<int> a = {1, 2, 3, 4};        // expected 24 12 8 6
    vector<int> b = {-1, 1, 0, -3, 3};   // expected 0 0 9 0 0

    vector<int> r1 = productExceptSelf(a);
    for (int v : r1) cout << v << " ";
    cout << endl;

    vector<int> r2 = productExceptSelf(b);
    for (int v : r2) cout << v << " ";
    cout << endl;
    return 0;
}