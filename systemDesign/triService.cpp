/**
 * Definition of TrieNode:
 * class TrieNode {
 * public:
 *     TrieNode() {}
 *     map<char, TrieNode*> children;
 *     vector<int> top10;
 * };
 */
class TrieService {
private:
    TrieNode* root;

public:
    TrieService() {
        root = new TrieNode();
    }

    TrieNode* getRoot() {
        // Return root of trie root, and 
        // lintcode will print the tree struct
        
        return root;
    }

    void insert(string& word, int frequency) {
        // Write your code here
        TrieNode* tmp = root;
        for(int i=0; i<word.size(); i++) {
            if(!tmp->children.count(word[i])){
                tmp->children[word[i]] = new TrieNode();
            } 
            tmp = tmp->children[word[i]];
            if( tmp->top10.size() < 10 || tmp->top10.back() < frequency){
                if(tmp->top10.size() >= 10){
                    tmp->top10.pop_back();
                }
                tmp->top10.push_back(frequency);
                sort(tmp->top10.begin(), tmp->top10.end(), greater<int>());
            }
           
        }
    }
};
