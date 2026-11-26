#include<iostream>
#include<string>
using namespace std;

string removeOccurance (string s, string part) {
    while (s.length() > 0 && s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }

    return s;
}