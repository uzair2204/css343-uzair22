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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = nullptr;
        if (inorder.size() > 0 && inorder.size() == postorder.size()) {
            int p = postorder.size() - 1;
            root = buildTree(inorder, postorder, 0, inorder.size() - 1, p);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int start, int end, int& p) {
        if (start <= end) {
            TreeNode* node = new TreeNode(postorder[p--]);
            if (start == end) {
                return node;
            }
            int i = start, n;
            for (n = start; n <= end; n++) {
                if (inorder[n] == node->val) {
                    i = n;
                    break;
                }
            }
            node->right = buildTree(inorder, postorder, i + 1, end, p);
            node->left = buildTree(inorder, postorder, start, i - 1, p);
            return node;
        }
        return nullptr;
    }
};
