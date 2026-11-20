// Problem: Create and Print a String
// Initialize a C++ `std::string` variable and output its value to the console.
// Example: str = "Hello World !!" -> prints "Hello World !!"
//
// Approach: Basic `std::string` initialization and standard output.
//   1. Declare and initialize `str` with the string literal `"Hello World !!"`.
//   2. Print `str` followed by a newline (`endl`) using `cout`.
//
// Time: O(n), where n is the length of the string (copying and printing n characters)
// Space: O(n), to store the characters of `str` in memory
// Note: Explicitly adding `#include <string>` is good practice when using
//       `std::string`, as `<iostream>` is not guaranteed to include it on all compilers.


#include<iostream>
using namespace std;

int main() {
    string str = "Hello World !!";
    cout << str << endl;
    return 0;
}