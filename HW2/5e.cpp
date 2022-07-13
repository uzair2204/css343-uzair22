/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //If root is present
        if (root) {
            //If value to be inserted is less than root 
            if (val < root->val) {
                //Recursive call to get root's left node
                root->left = insertIntoBST(root->left, val);
            } 
            else {
                //Recursive call to get root's right node
                root->right = insertIntoBST(root->right, val);
            }
        }
        //If root is not present 
        else {
            root = new TreeNode(val);
        }
        return root;
    }
};
