class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int,int>memo;
        memo[0] =0;
        return getChange(coins, amount, memo);
       
    }
    
    int getChange(vector<int>& coins, int target, unordered_map<int, int>&memo) {
        if(target <0) return -1;
        if(memo.count(target)) return memo[target];
        int cur = INT_MAX;
        for (int i=0; i<coins.size(); i++) {
            int tmp = getChange(coins, target-coins[i], memo);
            if(tmp>=0) cur = min(cur, tmp+1);
                
        }
        
        return memo[target] = (cur == INT_MAX) ? -1 : cur;
    }
};