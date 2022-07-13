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
    void flatten(TreeNode* root) {
        TreeNode* next = nullptr;
        flatten(root, next);
    }
    TreeNode* flatten(TreeNode* root, TreeNode* next) {
        if (root) {
            next = flatten(root->right, next);
            next = flatten(root->left, next);
            root->right = next;
            root->left = nullptr;
            return root;
        }
        return next;
    }
};
