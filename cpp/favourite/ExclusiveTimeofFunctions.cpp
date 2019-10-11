class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>res(n,0);
        stack<int> st;
        int pre_ts=0;
        for (auto l : logs) {
            int pos1 = l.find(':', 0);
            int fid = stoi(l.substr(0, pos1));
            int pos2 = l.find(':', pos1+1);
            string s = l.substr(pos1+1, pos2-pos1-1);
            int ts = stoi(l.substr(pos2+1));
            if(!st.empty()) res[st.top()] += ts - pre_ts;
            pre_ts = ts;
            if (s == "start") {
                st.push(fid);
            } else {
                auto t = st.top();
                st.pop();
                res[t]++;
                pre_ts ++;
                
            }
            
        }
        
        return res;
    }
};