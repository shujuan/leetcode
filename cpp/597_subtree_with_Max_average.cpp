/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
    pair<TreeNode*, double>maxAve ={nullptr, INT_MIN};
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode * findSubtree2(TreeNode * root) {
        // write your code here
        int cnt =0;
        getSum(root, cnt);
        return maxAve.first;
    }
    
    int getSum(TreeNode* root, int& cnt){
        if(!root) return 0;
        int cntleft = cnt, cntright = cnt;
        int leftSum = getSum(root->left, cntleft);
        int rightSum = getSum(root->right, cntright);
        cnt = cntleft + cntright -cnt+1;
        double ave = (leftSum + rightSum+ root->val)/(double)cnt;
        if(ave > maxAve.second) {
            maxAve= {root, ave};
        }
        return leftSum + rightSum+ root->val;
        
    }
};
