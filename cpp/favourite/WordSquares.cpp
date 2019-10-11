struct TrieNode{

    TrieNode* child[26];
    vector<int> prefix;
    TrieNode(){
      
        for (int i=0; i<26; i++) {
            child[i] = nullptr;
        }
    }
};



class Solution {
    TrieNode* root;
public:
    /*
     * @param words: a set of words without duplicates
     * @return: all word squares
     */
    
    Solution(){
        root = new TrieNode();
    }
    
    void buildTrie(vector<string>& words) {
        
        for(int j=0; j<words.size(); j++) {
           TrieNode* tmp = root;
           for(int i =0; i<words[j].size(); i++) {
               
               if(!tmp->child[words[j][i]-'a']){
                   tmp->child[words[j][i]-'a'] = new TrieNode();
               }
               tmp->prefix.push_back(j);
               tmp = tmp->child[words[j][i]-'a'];
           }
          
          
        }
    }
    
    vector<vector<string>> wordSquares(vector<string> &words) {
        // write your code here
        vector<vector<string>> res;
        int m = words.size();
        if(!m) return res;
        buildTrie(words);
        
        vector<string> out;
        for(int i=0; i<m; i++) {
            out.push_back(words[i]);
            getSquare(out, words, res);
            out.pop_back();
        }
        
        return res;
        
    }
    
    void getSquare(vector<string>& out, vector<string>& words, vector<vector<string>>& res) {
        if(out.size() == words[0].size()) {
            res.push_back(out);
            return;
        }
        
        int sz = out.size();
        string target;
        for (int i=0; i<sz; i++) {
            target += out[i][sz];
        }
        
        auto tmp = root;
        for (int i=0; i<target.size(); i++) {
            if(!tmp->child[target[i]-'a']) return;
            tmp = tmp->child[target[i]-'a'];
        }
        
        vector<string>next;
        for (int i=0; i<tmp->prefix.size(); i++) {
            next.push_back(words[tmp->prefix[i]]);
        }
        
        for (auto nt : next) {
            out.push_back(nt);
            getSquare(out, words, res);
            out.pop_back();
        }
   
        
    }
 
    
    
    
};