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
    //Function that takes in a TreeNode* and returns true if the tree is valid.
    bool isValidBST(TreeNode* root) {
        bool isValid = true;
        TreeNode* prev = nullptr;
        inorder(root, prev, isValid);
        return isValid;

    }
    void inorder(TreeNode* root, TreeNode* &prev, bool& isValid) {
        //Checking to see if the root node is null or not, then it checks to see if the boolean variable "isValid" is set to false
        if (root == nullptr || !isValid)
            return;
        //Iterate through each of the nodes in order from left to right until it reaches a node with an equal 
        //value on its left side and a greater value on its right side 
        inorder(root->left, prev, isValid);
        //Attempts to check if a tree node is valid.
        if (prev && prev->val >= root->val)
        {
            isValid = false;
            return;
        }
        //Declares a TreeNode* pointer named "prev" and initializes it with nullptr.
        prev = root;
        //Iterates over the inorder function
        inorder(root->right, prev, isValid);
    }
};
