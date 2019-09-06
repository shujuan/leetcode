static bool cmp(string& a, string& b) {
    return a.size() > b.size();
}

class Solution {
public:
    /**
     * @param a: The A array
     * @param b: The B array
     * @param s: The S string
     * @return: The answer
     */
     
  
    string stringReplace(vector<string> &a, vector<string> &b, string &s) {
        // Write your code here
        unordered_map<string, string>mp;
        for(int i=0; i<a.size(); i++) {
            mp[a[i]] = b[i];
        }
        sort(a.begin(), a.end(), cmp);
        int n = s.size(), pos = 0;
        while(pos < n) {
            for(int i=0; i<a.size(); i++) {
                int len = a[i].size();
                if(pos+len > n)continue;
                string str = s.substr(pos, len);
                if(str == a[i]) {
                    s.replace(pos, len, mp[a[i]]);
                    pos +=len-1;
                    break;
                }
                
            }
            pos++;
        }
        return s;
        
    }
};
