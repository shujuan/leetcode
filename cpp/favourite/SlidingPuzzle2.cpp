class Solution {
    vector<pair<int, int>> dirs = {{-1, 0}, {1,0}, {0, 1}, {0, -1}};
public:
    /**
     * @param init_state: the initial state of chessboard
     * @param final_state: the final state of chessboard
     * @return: return an integer, denote the number of minimum moving
     */
    int minMoveStep(vector<vector<int>> &init_state, vector<vector<int>> &final_state) {
        // # write your code here
        string start = matrixToString(init_state);
        string end = matrixToString(final_state);
        queue<string>q;
        q.push(start);
        unordered_set<string>visited;
        visited.insert(start);
        int level = 0;
        while(!q.empty()) {
            int n = q.size();
            level++;
            for(int i=0; i<n; i++){
                auto t = q.front();
                q.pop();
                vector<string> nexts = getNext(t);
                for(auto next : nexts) {
                    if(next == end) return level;
                    if(!visited.count(next)){
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
        return -1;
    }
    
    string matrixToString(vector<vector<int>>& state){
        string res;
        for(int i=0; i<state.size(); i++) {
            for(int j=0; j<state[0].size(); j++) {
                res += to_string(state[i][j]);
            }
        }
        return res;
    }
    
    vector<string> getNext(string cur) {
        vector<string>res;
        int indx = cur.find('0');
        int x = indx/3;
        int y = indx%3;
        for(auto dir : dirs) {
            int nx = x+dir.first;
            int ny = y+dir.second;
            if(nx>=0 && nx<3 && ny>=0 && ny<3){
                int nextIndx = nx*3+ny;
                string tmp = cur;
                swap(tmp[indx], tmp[nextIndx]);
                res.push_back(tmp);
            }
        }
        
        return res;
        
    }
    
    
};