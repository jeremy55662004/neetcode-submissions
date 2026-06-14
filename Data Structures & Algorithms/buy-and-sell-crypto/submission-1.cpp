class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_buy = prices[0];

        for (int& sell : prices) {
            max_profit = max(max_profit, sell - min_buy);
            min_buy = min(min_buy, sell);
        }
        return max_profit;
    }
};
