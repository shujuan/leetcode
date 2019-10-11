class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> mp(wordList.begin(), wordList.end());
        vector<vector<string>>res;
        vector<string>path;
       
        queue<vector<string>>q;
       
        path.push_back(beginWord);
        if(beginWord == endWord) return vector<vector<string>>(1, path);
        q.push(path);
        unordered_set<string>visited;
        while(!q.empty()) {
            int n = q.size();
            
            for(int i=0; i<n; i++) {
                auto t = q.front();
                q.pop();
                addWord(t, endWord, res, visited, mp, q);
                
            }
            
            if(!res.empty())return res;
            //clean visited words after each level;
            for(auto word : visited) {
                mp.erase(word);
            }
            visited.clear();
            
        }
        return res;
        
    }
    
    void addWord(vector<string>& t, string endWord, vector<vector<string>>& res, unordered_set<string>& visited, unordered_set<string>&mp, queue<vector<string>>& q) {
        string curWord = t.back();
        for(int i=0; i<curWord.size(); i++) {
            char c = curWord[i];
            for(int j=0; j<26; j++) {
                curWord[i] = 'a' + j;
                
                if(mp.count(curWord)){
                    vector<string>nextPath = t;
                    nextPath.push_back(curWord);
                    if(curWord == endWord){
                        res.push_back(nextPath);
                    } else {
                        q.push(nextPath); 
                    }
                    visited.insert(curWord);
                }
            }
            curWord[i] = c;
        }
    }
};