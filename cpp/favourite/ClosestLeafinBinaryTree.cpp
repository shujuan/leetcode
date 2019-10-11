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
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode*, TreeNode*>parent;
        TreeNode* res = getTarget(root, k, parent);
        cout<< res->val<<"\n";
        queue<TreeNode*>q;
        q.push(res);
        unordered_set<TreeNode*>visited;
        visited.insert(res);
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            if(!top->left && !top->right) {
                return top->val;
            } 
            if(top->left && !visited.count(top->left)) {
                q.push(top->left);
                visited.insert(top->left);
            } 
            if(top->right && !visited.count(top->right)) {
                q.push(top->right);
                visited.insert(top->right);
            } 
            
            if(parent.count(top) && !visited.count(parent[top])){
                q.push(parent[top]);
                visited.insert(parent[top]);
            }
        }
        return -1;
    }
    
    TreeNode* getTarget(TreeNode*root, int k, unordered_map<TreeNode*, TreeNode*>&parent){
        TreeNode* res = root;
        if(root->left) {
            parent[root->left] = root;
            TreeNode* tmp = getTarget(root->left, k, parent);
            res = tmp->val == k ? tmp : res;
        }
        
        if(root->right) {
            parent[root->right] = root;
            TreeNode*tmp = getTarget(root->right, k, parent);
            res = tmp->val == k ? tmp : res;
        }
        
        return res;
    }
};