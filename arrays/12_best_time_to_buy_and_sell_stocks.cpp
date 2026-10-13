// C++ program to find the maximum profit from buying and selling a stock once
// Approach : Keep track of the lowest price seen so far (bestBuy).
//            For each day, profit = today's price - bestBuy; keep the maximum.
// Time : O(n)  Space : O(1)

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int maxProfit = 0, bestBuy = prices[0];
        for (int i=1; i < prices.size(); i++) {
            if (prices[i] > bestBuy) {
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }
            bestBuy = min (bestBuy, prices[i]);
        }
        return maxProfit;
}

int main() {
    vector<int> prices = {7,1,5,3,6,2};
    cout << " Max profit = " << maxProfit(prices) << endl;
}