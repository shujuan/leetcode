class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.size() != endWord.size()) return 0;
        unordered_set<string>m(wordList.begin(), wordList.end());
        int res =0;
        if(beginWord == endWord) return res;
        queue<string>q;
     
        q.push(beginWord);
        m.erase(beginWord);
        while(!q.empty()) {
            int n = q.size();
            res++;
            
            for(int i=0; i<n; i++) {
                auto t = q.front();
                q.pop();      
                if(t == endWord) return res;
                addWord(t, m, q);
            }
            
        }      
        return 0;
        
    }
    
    void addWord(string curWord,  unordered_set<string>& m, queue<string>&q) {
       
        for(int i=0; i<curWord.size(); i++) {
            char c = curWord[i];
            for(int j=0; j<26; j++) {
                //string nextWord =(i==0 ? "" :curWord.substr(0, i)) + string(1, ('a'+j)) + ((i==curWord.size()-1) ? "" :curWord.substr(i+1));
                curWord[i] = 'a'+j;
                if(m.count(curWord) ) {
                    q.push(curWord);
                    m.erase(curWord);
                }
            }
            curWord[i] = c;
        }
        
    }
};