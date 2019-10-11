class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
  
        unordered_map<string, vector<string>>memo;
        return getWordList(s, wordDict, memo);
       
    }
    
    vector<string> getWordList(string s,  vector<string>& wordDict,  unordered_map<string, vector<string>>& m) {
        if(s.empty()) return {""};
        if(m.count(s)) return m[s];
        vector<string> res;
        for (auto word : wordDict) {
            if (s.substr(0, word.size()) != word) continue;
            vector<string>tmp = getWordList(s.substr(word.size()), wordDict, m);
            for(auto t : tmp) {
                res.push_back(word + (t.size() ? " " :"") +t);
            }
        }
        return m[s]=res;
    }
};