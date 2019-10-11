class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto word:words) {
            mp[word]++;
        }
        vector<int>res;
        int n = words.size();
        if(!n) return res;
        int strLen = words[0].size();
        int totalLen = n*strLen;
        for(int i=0; i+totalLen <= s.size(); i++) {
            unordered_map<string,int>curMp;
            for(int j=i; j+strLen<=i+totalLen; j+=strLen) { 
                string w = s.substr(j, strLen);
                if(!mp.count(w)) break;
                curMp[w]++; 
            }
            if(mp == curMp) res.push_back(i);
        }
        return res;
        
    }
};