// Problem: Search a 2D Matrix (LeetCode 74)
// Given an m x n integer matrix where each row is sorted in non-decreasing
// order and the first integer of each row is greater than the last integer
// of the previous row, return true if `target` is in `matrix`, or false otherwise.
// Example: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3 -> true
//
// Approach: Two-step Binary Search (binary search on rows, then on columns).
//   1. `searchMatrix` performs binary search across the rows (`startRow` to
//      `endRow`) to locate the unique row whose range `[matrix[midRow][0],
//      matrix[midRow][n - 1]]` can contain `target`.
//      - If `target` falls within `midRow`'s bounds, delegate to `searchInRow`.
//      - If `target > matrix[midRow][n - 1]`, search the lower half (`startRow = midRow + 1`).
//      - Otherwise, search the upper half (`endRow = midRow - 1`).
//   2. `searchInRow` runs a standard 1D binary search (`st` to `end`) across
//      the selected `row` to check if `target` exists.
//
// Time: O(log m + log n) = O(log(m * n)), where m is the number of rows and n
//       is the number of columns (O(log m) to find the row + O(log n) to search it)
// Space: O(1), uses only a constant number of pointer variables
// Alternative: Treat the 2D matrix as a single flattened sorted 1D array of
//   size m * n and run a single binary search using `row = mid / n` and
//   `col = mid % n` for the same O(log(m * n)) time and O(1) space.


#include<iostream>
#include<vector>
using namespace std;

bool searchInRow(vector<vector<int>>& matrix, int target, int row) {        // search for the target in the row 
    int n = matrix[0].size();
    int st = 0, end = n-1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (target == matrix[row][mid]) {
            return true;
        } else if (target > matrix[row][mid]) {
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // Binary Search in total rows
    int m = matrix.size(), n = matrix[0].size();
    int startRow = 0, endRow = m-1;

    while (startRow <= endRow) {
        int midRow = startRow + (endRow - startRow) / 2;

        if (target >= matrix[midRow][0] && target <= matrix[midRow][n-1]) {
            return searchInRow(matrix, target, midRow);
        } else if (target >= matrix[midRow][0]) {
            startRow = midRow + 1;
        } else {
            endRow = midRow - 1;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 34;

    if (searchMatrix(matrix, target)) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}