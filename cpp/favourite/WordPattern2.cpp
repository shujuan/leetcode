class Solution {
public:
    /**
     * @param pattern: a string,denote pattern string
     * @param str: a string, denote matching string
     * @return: a boolean
     */
    bool wordPatternMatch(string &pattern, string &str) {
        // write your code here
        unordered_map<char, string> m;
        bool res = getMatch(pattern, 0, str, 0, m);
        return res;
    }
    
    bool getMatch(string &pattern, int p, string &str, int s, unordered_map<char, string>& m) {
        if (pattern.size() == p && s == str.size()) return true;
        if (pattern.size() == p || s == str.size()) return false;
         
        char pat = pattern[p];
        for (int i = s; i< str.size(); i++) {
            string tmp = str.substr(s, i-s+1);
           
            
            if (m.count(pat) && m[pat] == tmp) {
                if(getMatch(pattern, p+1, str, i+1, m)) return true;;
            } else if (!m.count(pat)) {
                bool b = false;
                for (auto elm : m) {
                    if (elm.second == tmp) b = true;
                }
                if (!b) {
                    m[pat] = tmp;
                    if(getMatch(pattern, p+1, str, i+1, m)) return true;
                    m.erase(pat);
                }
            }
        }
        
        return false;
    }
};