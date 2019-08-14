/**
 * Definition of TrieNode:
 * class TrieNode {
 * public:
 *     TrieNode() {}
 *     map<char, TrieNode*> children;
 * };
 */
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a trie which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TrieNode* root) {
        // Write your code here
        string res;
        if(!root) return NULL;
        for(auto c :root->children){
            res += c.first + serialize(c.second);
        }
        return '<' + res + '>';
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TrieNode* deserialize(string data) {
        // Write your code here
        if(data.empty()) return nullptr;
        TrieNode* root = new TrieNode();
        TrieNode* p = root;
        stack<TrieNode*>st;
        for(int i=0; i<data.size(); i++) {
            switch(data[i]){
                case '<':
                    st.push(p);
                    break;
                case '>':
                    st.pop();
                    break;
                default:
                    p = new TrieNode();
                    st.top()->children[data[i]] = p;
                    
            }
        }
        
        return root;
    }
};
