#include<iostream>
#include<vector>
using namespace std;

int peakIndexInMountainArray(vector<int> & A) {
    int st = 1, end = A.size()-1;


    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (A[mid-1] < A[mid] && A[mid] > A[mid+1]) {
            return mid;
        } else if (A[mid-1] < A[mid]) {   // rising, peak is on the right
            st = mid + 1;
        } else {                           // falling, peak is on the left
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> a = {0, 1, 0};
    cout << peakIndexInMountainArray(a) << endl;
    return 0;
}