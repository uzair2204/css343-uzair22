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
        //Check if there are any elements in the input vector that are smaller than or equal to the ending point, which is end - 1.
        if (inorder.size() > 0 && inorder.size() == postorder.size()) {
            int p = postorder.size() - 1;
            root = buildTree(inorder, postorder, 0, inorder.size() - 1, p);
        }
        return root;
    }
    //Overloaded method. Called if starting point is smaller than or equal to ending point.
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int start, int end, int& p) {
        //If starting point is smaller than or equal to ending point
        if (start <= end) {
           
            TreeNode* node = new TreeNode(postorder[p--]);
            //Checks condition and returns node if necessary; otherwise, it continues iterating through the rest of
            //the vectors until either i == n or i < n + 1.
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
            //When i < n + 1 (i <= end), then node->right will be created with postorder[n] as its val and node->left 
            //will be created with postorder[end] as its val.
            node->right = buildTree(inorder, postorder, i + 1, end, p);
            node->left = buildTree(inorder, postorder, start, i - 1, p);
            return node;
        }
        return nullptr;
    }
};
