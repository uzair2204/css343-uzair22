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
    
    //Main function
    void flatten(TreeNode* root) {
        TreeNode* next = nullptr;
        flatten(root, next);
    }
    
    //Helper function
    TreeNode* flatten(TreeNode* root, TreeNode* next) {
        //Checking to see if root is present
        if (root) {
            
            //Recursive calls
            next = flatten(root->right, next);
            next = flatten(root->left, next);
            
            //Root's right node becomes next
            root->right = next;
            //Root's left node becomes null
            root->left = nullptr;
          
            return root;
        }
        return next;
    }
};
