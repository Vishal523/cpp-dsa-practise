#include<iostream>
using namespace std;

int factorial(int n) {
    if(n == 0) {
        return 1;
    }

    return n * factorial(n-1);
}


int main() {
    cout << "the factorial for the given number is : " << factorial(8) << endl;
    return 0;
}