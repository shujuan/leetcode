



class Solution {
    
    
   unordered_map<long,int>cost;
public:
    int dfs(vector<vector<int>>&workers, vector<vector<int>>& bikes, int curWorker, long mask){
        if(curWorker == workers.size()) return 0;
       
        long curMask = (curWorker<<11) + mask;
         cout<<curWorker << " "<<mask<<" "<<curMask<<"\n";
        if(cost.count(curMask)) return cost[curMask];
        int res = INT_MAX;
        for(int i=0; i<bikes.size(); i++) {
            if(((mask>>i) & 1)==0){
                cout<<"bike "<<mask<< " "<<i<<"\n";
                int nextCost = dfs(workers, bikes, curWorker+1, mask|(1<<i));
                res = min(res, nextCost+ abs(workers[curWorker][0] - bikes[i][0]) + abs(workers[curWorker][1]-bikes[i][1]));
            }
        }
        cost[curMask] = res;
        return res;
    }
    
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        return dfs(workers, bikes, 0, 0);
        
    
    }
  
       
};