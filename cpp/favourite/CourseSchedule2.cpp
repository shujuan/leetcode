class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses, vector<int>{});
        vector<int>in(numCourses,0);
        vector<int>res;
        
        for(auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            in[p[0]]++;
        }
        
        queue<int>q;
        for(int i=0; i<numCourses; i++) {
            if(in[i]==0) {
                res.push_back(i);
                q.push(i);
                
            }
        }
        
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            for(auto neigh : graph[t]) {
                in[neigh]--;
                if(in[neigh]==0) {
                    q.push(neigh);
                    res.push_back(neigh);
                }
                if(in[neigh]<0) return vector<int>{};
            }
        }
        
        for(int i=0; i<numCourses; i++) {
            if(in[i]) return vector<int>{};
        }
        return res;
    }
};