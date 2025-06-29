using namespace std;
#include <vector>
#include <iostream>

class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = __INT_MAX__;
        for (auto price : prices) {
            minPrice = min(price, minPrice);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution sol;
    cout << sol.maxProfit(prices) << endl; // Output: 5
    return 0;
}