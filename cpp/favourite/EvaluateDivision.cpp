class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>res;
        unordered_map<string, unordered_map<string, double>> graph;
        for(int i=0; i<equations.size(); i++) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            if(values[i])graph[equations[i][1]][equations[i][0]] = 1/values[i]; 
        }
        
        for(auto q : queries) {
            if(!graph.count(q[0])){
                res.push_back(-1);
                continue;
            }
            if(q[0] == q[1]) {
                res.push_back(1.0);
                continue;
            }
            double num=1;
            unordered_set<string>visited;
            bool found = false;
            dfs(q[0], q[1], num, visited, graph, found);
            if(!found) res.push_back(-1);
            else res.push_back(num);
            
        }
        return res;
    }
    
    void dfs(string curStr, string target, double& num, unordered_set<string>&visited, unordered_map<string, unordered_map<string, double>>&graph,  bool& found){
        visited.insert(curStr);
        for(auto g : graph[curStr]){
            if(g.first == target) {
                num *=g.second;
                found = true;
                return;
            }
            if(visited.count(g.first)) continue;
            num *= g.second;
            dfs(g.first, target, num,visited, graph,  found);
            
            if(found) return;
            num /= g.second;
            
        }
        //visited.erase(curStr);
    }
    
};