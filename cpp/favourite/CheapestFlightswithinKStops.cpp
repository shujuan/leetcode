class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        unordered_map<int,vector<pair<int,int>>>costs;
        unordered_map<int,int>memo;
        int res = INT_MAX;
        int f = flights.size();
        if(!f) return -1;
        for(auto flight : flights) {
            costs[flight[0]].push_back({flight[1], flight[2]});
        }
        
        queue<pair<int,int>>q;
        q.push({src, 0});
        memo[src] = 0;
        int level=0;
        while(!q.empty()) {
            int sz = q.size();
            level++;
            if(level>K+1) break;
            for(int i=0; i<sz; i++) {
                auto t = q.front();
                q.pop();
                for(auto neighbor : costs[t.first]) {
                    if(neighbor.first == dst){
                        res = min(res, t.second + neighbor.second);
                        continue;
                    }
                    if(memo.count(neighbor.first) && memo[neighbor.first] < (t.second+neighbor.second))
                        continue;
                    memo[neighbor.first] = t.second+neighbor.second;
                    q.push({neighbor.first, t.second+neighbor.second});
                }
            }    
        }
        
        return res==INT_MAX ? -1 : res;
    }
};