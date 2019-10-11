class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n ==2) return vector<int>{0,1};
        if(n==1) return vector<int>{0};
        unordered_map<int, unordered_set<int>>graph;
        vector<int>in(n,0);
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
            in[edges[i][0]]++;
            in[edges[i][1]]++;
            
        }
        queue<int>q;
        unordered_set<int>visited;
        for(int i=0; i<n; i++) {
            if(in[i]==1){
                q.push(i);
                visited.insert(i);
            }
        }
   
        
        while(!q.empty()){
            int m = q.size();
            if(visited.size()>=n-2) break;
            for(int i=0; i<m; i++) {
                auto t = q.front();
                q.pop();
              
                for(auto next : graph[t]) {
                    if(visited.count(next)) continue;
                    in[next]--;
                    if(in[next] ==1) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
        
        vector<int>res;
        for(int i=0; i<n; i++) {
            if(!visited.count(i)) res.push_back(i);
        }
        return res;
        
    }
};