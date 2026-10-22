// Problem: Find Missing and Repeated Values (LeetCode 2965)
// Approach: Use a set to catch the repeated number (a). Use the sum formula for the missing one.
//           expected sum of 1..n^2 = (n^2)(n^2+1)/2
//           actualSum = expSum + a - b  ->  b = expSum + a - actualSum
// Time: O(n^2), Space: O(n^2)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int a = 0, b = 0;

        int expSum = 0, actualSum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                actualSum += grid[i][j];

                if (s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }

        expSum = (n * n) * (n * n + 1) / 2;
        b = expSum + a - actualSum;
        ans.push_back(b);

        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {{1, 3}, {2, 2}};

    Solution sol;
    vector<int> ans = sol.findMissingAndRepeatedValues(grid);
    cout << ans[0] << " " << ans[1] << endl;   // repeated, missing
    return 0;
}