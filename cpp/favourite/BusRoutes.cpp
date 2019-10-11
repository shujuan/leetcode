class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int, unordered_set<int>>station;
        if(S==T) return 0;
        for(int i=0; i<routes.size(); i++) {
            for(int j=0; j<routes[i].size(); j++) {
                station[routes[i][j]].insert(i);
            }
        }
        
        int level =0; 
        unordered_set<int>visited;
        queue<int>q;
        q.push(S);
        while(!q.empty()) {
            int n = q.size();
            level++;
            for(int i=0; i<n; i++) {
                auto t = q.front();
                q.pop();
                
                for(auto nextbus : station[t]) {
                    if(visited.count(nextbus)) continue;
                    visited.insert(nextbus);
                    for(auto stat : routes[nextbus]){
                        if(stat == T) return level;
                        
                        q.push(stat);  
                    }
                }
            }
        }
        
        return -1;
        
    }
};