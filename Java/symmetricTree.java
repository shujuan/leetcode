 // Definition for a binary tree node.
class TreeNode {
     int val;
     TreeNode left;
     TreeNode right;
     TreeNode(int x) { val = x; }
 }

class symmetricTree {
   public static void main(String[] args){
       symmetricTree tree = new symmetricTree();
       TreeNode root = new TreeNode(1);
       root.left = new TreeNode(2);
       root.right = new TreeNode(2);
       root.left.left = new TreeNode(3);
       root.left.right = new TreeNode(4);
       root.right.left = new TreeNode(4);
       root.right.right = new TreeNode(3);
       boolean output = tree.isSymmetric(root);
       if (output==true)
         System.out.println("1");
       else
         System.out.println("0");
   }


    public boolean isSymmetric(TreeNode root) {
        return root==null || isSym(root.left, root.right);
    }
    
    private boolean isSym(TreeNode left, TreeNode right){
        if(left == null || right == null){
            return left == right;
        } 
        if(left.val !=right.val)
            return false;
        return isSym(left.left, right.right) && isSym(left.right, right.left);
    }
}
