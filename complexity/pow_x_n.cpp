#include<iostream>
#include<vector>
using namespace std;

int myPow(double x, int n) {
    long binForm = n;
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
    cout << myPow(2, 10) << endl;
    return 0;

}