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
    
    //Main function
    Node* connect(Node* root) {
        connect_helper(root);
        return root;
    }
    
    //Helper function taking root node as an argument
    void connect_helper(Node* root) {
        //Checking to see if there is a root and it's left child is present
        if (root && root->left) {
            //Checking if the root doesn't point towards a null pointer 
            if (root->next != nullptr) {
                //Setting root's next right to root's next left 
                root->right->next = root->next->left;
            }
            root->left->next = root->right;
            //Recursive calls 
            connect_helper(root->left);
            connect_helper(root->right);
        }
    }

};
