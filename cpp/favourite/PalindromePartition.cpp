class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string>out;
        vector<vector<string>>res;
        getPartition(s, 0, out, res);
        return res;
    }
    
    void getPartition(string s, int start, vector<string>& out, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(out);
            return;
        }
        
        for (int i=start; i<s.size(); i++) {
            string tmp = s.substr(start, i-start+1);
            if(isPalin(tmp)) {
                out.push_back(tmp);
                getPartition(s, i+1, out, res);
                out.pop_back();
            }
        }
    }
    
    bool isPalin(string t) {
        int l = t.size();
        for (int i=0, j=l-1; i<=j; i++, j--) {
            if(t[i] != t[j]) {
                return false;
            }
        }
        return true;
    }
};