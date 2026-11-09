#include<iostream>
#include<vector>
using namespace std;

bool isAplhaNum(char ch) {
    if(( ch >= '0' && ch <= '9')) || (tolower(ch) >= 'a' && tolower(ch) <= 'z'); {
        return true;
    }

    return false;
}