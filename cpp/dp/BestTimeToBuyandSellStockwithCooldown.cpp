class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell=0, preSell = 0, preBuy = INT_MIN, buy = INT_MIN;
        for(int i=0; i<prices.size(); i++) {
            preBuy = buy;
            buy = max(preSell-prices[i], preBuy);
            preSell = sell;
            sell = max(preBuy+prices[i], preSell);
        }
        
        
        return sell;
    }
};