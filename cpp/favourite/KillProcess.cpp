class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int,set<int>>m;
        for(int i = 0; i< ppid.size(); i++) {
            if(ppid[i]) m[ppid[i]].insert(pid[i]);
        }
        
        vector<int> res;
        killP(res, m, kill);
        return res;
        
      
    }
    
    void killP(vector<int>& res, unordered_map<int,set<int>>& m,  int kill) {
        res.push_back(kill);
        for (auto neigh : m[kill]) {
            killP(res,m, neigh);
        }
    }
};