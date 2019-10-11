class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,int>in;
        unordered_map<char, unordered_set<char>>graph;
        unordered_set<char>st;
        for(auto word:words) {
            st.insert(word.begin(), word.end());
        }
        
        string res;
        for(int i=1; i<words.size(); i++) {
            int m = min(words[i-1].size(), words[i].size());
            int j=0;
            for(; j<m; j++) {
                if(words[i-1][j] == words[i][j]) continue;
                if(!graph[words[i-1][j]].count(words[i][j])){
                    graph[words[i-1][j]].insert(words[i][j]);
                    in[words[i][j]]++;
                }
                break;
            }
            if(j==m && words[i-1].size() > words[i].size()) return "";
            
        }
        
        queue<char>q;
        for(auto s:st) {
            if(in[s]==0) {
                q.push(s);
            }
        }
        
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            res += t;
            for(auto next : graph[t]) {
                
                in[next]--;   
              //  cout<<t<< " "<< next<<" "<<in[next]<<"\n";
                if(in[next]==0) {
                    q.push(next);
                }
                else if(in[next]<0) {
                    return "";
                }
            }
        }
        //cout<<res<<" "<<st.size()<<"\n";
        if(res.size() == st.size()) return res;
        else return "";
        
        
        
    }
};