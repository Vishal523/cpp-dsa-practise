// Problem: Allocate Books / Minimum Pages (Book Allocation)
//          Given n books where arr[i] is the number of pages in the i-th book, allocate
//          them to m students so that each student gets at least one book, books are
//          given in contiguous order, and every book goes to exactly one student.
//          Minimize the maximum number of pages assigned to any single student.
//          If m > n, allocation is not possible, so return -1.
// Approach: Binary search on the answer. The answer lies between 0 and sum of all pages.
//           For a mid value (max pages allowed per student), check with isValid():
//           go through the books greedily, keep adding pages to the current student, and
//           when adding the next book crosses mid, give that book to a new student.
//           If any single book is bigger than mid, or students needed > m, mid is invalid.
//           If mid is valid, store it as ans and search left (end = mid - 1) to find a smaller one.
//           If mid is not valid, search right (st = mid + 1).
// Time: O(n * log(sum)), where isValid() is O(n) and binary search runs log(sum) times
// Space: O(1) extra
// Brute force: try every value from max(arr) to sum as the limit and check each one
//              with isValid(), O(n * sum).


#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int>&arr, int n, int m,int maxAllowedPages) {
    int student = 1, pages = 0;

    for (int i=0; i<n; i++) {
        if(arr[i] > maxAllowedPages) {
            return false;
        }

        if (pages + arr[i] <= maxAllowedPages) {
            pages += arr[i];
        } else {
            student ++;
            pages = arr[i];
        }
    }

    return student > m ? false : true;
}

int allocateBooks(vector<int>&arr, int n, int m) {

    if (m > n){
        return -1;
    }

    int sum = 0;
    for(int i=0; i<n; i++) {        //O(n)
        sum += arr[i];
    }

    int ans = -1;
    int st = 0, end = sum;      // range of all possible ans

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if(isValid(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;              // left
        } else {
            st = mid + 1;               // right
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {15, 17, 20};
    int n = 4, m = 2;

    cout << allocateBooks(arr, n, m) << endl;
    return 0;
}