/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    return (1 + countNodes(root->left) + countNodes(root->right) );
}

//une solution Java avec O(logn)
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int leftHeight(TreeNode root){
        if(root == null)return 0;
        int height=0;
        while(root!=null){
            height++;
            root=root.left;
        }
        return height;
    } 
    private int rightHeight(TreeNode root){
        if(root == null)return 0;
        int height=0;
        while(root!=null){
            height++;
            root=root.right;
        }
        return height;
    } 
    public int countNodes(TreeNode root) {
        if(root == null)return 0;

        int left=leftHeight(root);
        int right=rightHeight(root);

        if(left == right)return  (int)Math.pow(2,left)-1;

        return countNodes(root.left) +  countNodes(root.right) + 1;
    }
}
