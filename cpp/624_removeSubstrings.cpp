class Solution {
public:
    /*
     * @param s: a string
     * @param dict: a set of n substrings
     * @return: the minimum length
     */
    int minLength(string &s, unordered_set<string> &dict) {
        // write your code here
        int res = s.size();
        queue<string>q;
        q.push(s);
        unordered_map<string, bool>visited;
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            visited[top] = true;
            for(auto word : dict) {
                int pos =0;
                while(pos < top.size() && top.find(word, pos) != string::npos) {
                    //cout<< pos <<" " << word<<"\n";
                    pos = top.find(word, pos);
                    string next = top.substr(0, pos) + top.substr(pos+word.size());
                    if(!visited[next]){
                        q.push(next);
                        visited[next] = true;
                        res = min((int)next.size(), res);
                    }
                    pos = pos+word.size();
                }
            }
        }
        
        return res;
    }
};
