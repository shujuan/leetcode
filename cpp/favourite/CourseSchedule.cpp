class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>req(numCourses, vector<int>{});
        vector<int>in(numCourses, 0);
        vector<bool>visited(numCourses, false);
        for(auto p:prerequisites) {
            req[p[0]].push_back(p[1]);
            in[p[1]]++;  
        }
        
        queue<int>q;
        for(int i=0; i<numCourses; i++) {
            if(in[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            if(visited[t]) return false;
            visited[t] = true;
            for(auto neigh : req[t]){
                in[neigh]--;
                if(in[neigh]==0) {
                    q.push(neigh);
                }
            }
        }
        
        for(int i=0; i<numCourses; i++) {
            if(!visited[i]) return false;
        }
        return true;
        
    }
};