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
        getSerial(root, res);
        return res;
    }
    
    void getSerial(TreeNode* root, string& res) {
        if (!root) {
            res += " #";
            return;
        }
        res+=" " + to_string(root->val);
        getSerial(root->left, res);
        getSerial(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream in(data);
        return deserial(in);
    }
    
    TreeNode* deserial(stringstream& in) {
        string s;
        TreeNode* root;
        in>>s;
        if (s != "#") {
            root = new TreeNode(stoi(s));
            root->left = deserial(in);
            root->right = deserial(in);
        }
        else return NULL;
     
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));