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
    //Function that deletes the node with the given key
    TreeNode* deleteNode(TreeNode* root, int key) {
        //If there is no such node, then it returns nullptr.
        if (!root) return root;
        //If there is a left child of the current node and right child of the current node, 
        //then they are deleted in order to make room for this new one.
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        //Checking whether or not root has children (if it does not have any children, then it will return nullptr).
        else {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            //Checks whether or not its left and right children exist before deleting them.
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
            //After all the above steps are done, deleteNode() returns the newly created tree node which
            //was just created from root's parent (root->right)
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
