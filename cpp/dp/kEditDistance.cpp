
struct TrieNode{
    bool isword;
    TrieNode* child[26];
    string wd;
    TrieNode() {
        isword = false;
        for(int i=0; i<26; i++){
            child[i] = nullptr;
        }
    }
    
};


class Solution {
    
    
    TrieNode* root;
public:
    
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */
    
    Solution() {
        root = new TrieNode();
    } 
    
    
    void buildTree(string &word) {
        TrieNode* tmp = root;
        for(int i = 0; i<word.size(); i++) {
            if(!tmp->child[word[i]-'a']) tmp->child[word[i]-'a'] = new TrieNode();
            tmp = tmp->child[word[i]-'a'];
        }
        tmp->isword = true;
        tmp->wd = word;
    }
     
     
     
     
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        // write your code here
        int n = words.size();
        for (int i=0; i<n; i++){
            buildTree(words[i]);
        }
        
        vector<string> res;
        int m = target.size();
        vector<int>dp(m+1, 0);
        for(int i=0; i<=m; i++){
            dp[i] = i;
        }
        find(root, target, dp, k, res);
        return res;

    }
    
    void find(TrieNode* node, string& target, vector<int>& dp, int k, vector<string>& res){
        if(!node){
            return;
        }
        int n = target.size();
        if(node->isword && dp[n]<=k){
            res.push_back(node->wd);
            
        }
        vector<int>next(n+1, 0);
        for (int i=0; i<26; i++) {
            if(!node->child[i]) continue;
            next[0]= dp[0]+1;
            for(int j=1; j<=n; j++) {
                if(target[j-1] == 'a'+i) {
                    next[j] = dp[j-1];
                } else {
                    next[j] = min(dp[j-1]+1, min(dp[j]+1, next[j-1]+1));
                }
            }
            
            find(node->child[i], target, next, k, res);
        }
        
    }