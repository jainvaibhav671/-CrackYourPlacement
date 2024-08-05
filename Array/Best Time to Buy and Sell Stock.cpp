#include <vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyDay = 0;
        int sellDay = 0;
        int maxProfit = -1;

        for (int i=0; i<prices.size(); i++) {
            int price = prices[i];

            if (price < prices[buyDay]) {
                buyDay = sellDay = i;
            } else if (price > prices[sellDay]) {
                sellDay = i;
                maxProfit = max(maxProfit, prices[sellDay] - prices[buyDay]);
            }

            // cout << i << " " << buyDay << " " << sellDay << " " << maxProfit << endl;
        }
        return (maxProfit < 0) ? 0 : maxProfit;
    }
};