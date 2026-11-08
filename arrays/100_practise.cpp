#include<iostream>
#include<vector>
using namespace std;

int peakIndexInMountainArray(vector <int> &A) {
    int st = 1; int end = A.size()-1;

        int mid = st + (end - st) / 2;

        for(int i=1; i<A.size(); i++){
            if(A[mid-1 < A[mid] && A[mid] > A[mid + 1]]){
                return mid;
            } else if (A[mid] > A[mid -1]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return 0;
}