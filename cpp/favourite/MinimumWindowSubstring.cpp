class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        string res;
        if (n > m) return res;
        unordered_map<char,int> dict;
        for (auto c:t) {
            dict[c]++;
        }
        int left = 0, minLen = INT_MAX, cnt=0;
        for (int i = 0; i<s.size(); i++) {
            if(--dict[s[i]] >=0)  cnt++;
            while(cnt == n) {
                if(minLen > i-left +1) {
                    minLen = i-left +1;
                    res = s.substr(left, minLen);
                }
                if(++dict[s[left++]] > 0) cnt--;
            }
        }
        
        return res;
    }
};