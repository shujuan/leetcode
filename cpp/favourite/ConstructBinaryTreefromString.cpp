/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* str2tree(string s) {
        if(s.empty()) return NULL;
        int i=0;
        return buildTree(s, i);
    }
    
    TreeNode* buildTree(string s, int &i) {
        int  start = i;
        if (s[i] == '-') {
            i++;
        }
        while(isdigit(s[i])) i++;
        int v = stoi(s.substr(start, i-start));
        TreeNode* node = new TreeNode(v);
        if (s[i] == '(') {
            node->left = buildTree(s, ++i);
            i++;
        }
        
        if (s[i] == '(') {
            node->right = buildTree(s, ++i);
            i++;
        }
        
        return node;
        
    }
};