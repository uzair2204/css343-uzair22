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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            else if (root->left == nullptr) {
                TreeNode* node = root->right;
                delete root;
                return node;
            }
            else if (root->right == nullptr) {
                TreeNode* node = root->left;
                delete root;
                return node;
            }
            else {
                TreeNode* node = root;
                if (root->right->left) {
                    TreeNode* previous = root->right;
                    for (root = root->right; root->left; root = root->left)
                        previous = root;
                    previous->left = root->right;
                    root->right = node->right;
                }
                else {
                    root = root->right;
                }
                root->left = node->left;
                delete node;
            }
        }
        return root;
    }
};
