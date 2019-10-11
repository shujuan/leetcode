/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if(!root) return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            if(!t) res +="# ";
            else {
                res +=to_string(t->val) + " ";
                q.push(t->left);
                q.push(t->right);
            }
        }
        return res;
    
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        string s;
        queue<TreeNode*>q;
        if(!(in>>s) || s== "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(s));
        
        q.push(root);
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            
            if(!(in>>s)) break;
            if(s !="#") {
                t->left = new TreeNode(stoi(s));
                q.push(t->left);
            }
            
            if(!(in>>s)) break;
             if(s !="#") {
                t->right = new TreeNode(stoi(s));
                q.push(t->right);
            }
            
        }
        
        return root;
        
        
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));