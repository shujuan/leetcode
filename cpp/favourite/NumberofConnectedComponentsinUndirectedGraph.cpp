class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if(n<=1) return n;
        unordered_map<int, unordered_set<int>>graph;
        for(auto e:edges){
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        int count=0;
        unordered_set<int>visited;
        for(int i=0;i<n;i++){
            if(visited.find(i)==visited.end()){
                visited.insert(i);
                dfs(i,graph,visited);
                count++;
            }
        }
        return count;
        
    }
    
    void dfs(int i, unordered_map<int,unordered_set<int>>&graph, unordered_set<int>&visited){
       
        for(auto n:graph[i]){
            if(visited.find(n)==visited.end()){
                visited.insert(n);
                dfs(n,graph,visited);
            }
        }
    }
    
    
};