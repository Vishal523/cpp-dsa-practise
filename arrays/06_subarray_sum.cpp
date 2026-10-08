// C++ program to print all subarrays of an array
// Approach : Use 3 nested loops to print all subarrays
// Time : O(n^3)  Space : O(1)

#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};

    for (int st =0; st < n; st++) {
        for (int end = st; end < n; end++) {
            for (int i = st; i <= end; i++) {
                cout << arr[i] << " ";
            }
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}