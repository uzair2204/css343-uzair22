/*
Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


class Solution {
public:
    Node* connect(Node* root) {
        connect_helper(root);
        return root;
    }

    void connect_helper(Node* root) {
        if (root && root->left) {
            if (root->next != nullptr) {
                root->right->next = root->next->left;
            }
            root->left->next = root->right;
            connect_helper(root->left);
            connect_helper(root->right);
        }
    }

};
