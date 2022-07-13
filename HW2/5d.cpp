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
    bool isValidBST(TreeNode* root) {
        bool isValid = true;
        TreeNode* prev = nullptr;
        inorder(root, prev, isValid);
        return isValid;

    }
    void inorder(TreeNode* root, TreeNode* &prev, bool& isValid) {
        if (root == nullptr || !isValid)
            return;
        inorder(root->left, prev, isValid);
        if (prev && prev->val >= root->val)
        {
            isValid = false;
            return;
        }
        prev = root;
        inorder(root->right, prev, isValid);
    }
};
