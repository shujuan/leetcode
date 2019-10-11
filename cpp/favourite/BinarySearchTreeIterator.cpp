/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class BSTIterator {
   stack<TreeNode*>st;
public:
    BSTIterator(TreeNode* root) {
         
         while(root){
             st.push(root);
             root=root->left;
         }
    }
    
 
    /** @return the next smallest number */
    int next() {
        auto t = st.top();
        st.pop();
        int res = t->val;
        if(t->right) {
            t = t->right;
            while(t){
                st.push(t);
                t=t->left;
               
            }
  
        }
        
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */