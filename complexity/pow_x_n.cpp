// Problem: Pow(x, n), calculate x raised to the power n
// Approach: Binary exponentiation. Look at n in binary. Whenever the current
//           bit is 1, multiply ans by x. Then square x and halve n.
//           Example: 2^10 -> 10 is 1010 in binary, so only 2^2 and 2^8 get multiplied.
//           Negative n: use (1/x)^(-n).
// Time: O(log n), Space: O(1)
// Brute force: multiply x by itself n times, O(n)

#include<iostream>
#include<vector>
using namespace std;

int myPow(double x, int n) {
    long binForm = n;

    if (n < 0) {
        x = 1/x;
         binForm = -binForm;
    }

    double ans = 1;

    while( binForm > 0){
        if (binForm % 2 == 1){
            ans *= x;
        }
        x *= x;
        binForm /= 2;
    }
    return ans;
}

int main() {
    cout << myPow(2, 10) << endl;    // 1024
    cout << myPow(2, -2) << endl;    // 0.25
    cout << myPow(2.5, 2) << endl;   // 6.25
    return 0;

}