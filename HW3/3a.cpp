/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* nodes[100];
        for (int i = 0; i < 100; i++) {
            nodes[i] = nullptr;
        }
        Node* copy = cloneGraph_helper(nodes, node);
        return copy;
    }

    Node* cloneGraph_helper(Node* nodes[100], Node* node) {
        if (!node)
            return node;
        if (nodes[node->val - 1])
            return nodes[node->val - 1];
        nodes[node->val - 1] = new Node();
        nodes[node->val - 1]->val = node->val;
        nodes[node->val - 1]->neighbors = vector<Node*>(node->neighbors.size(), nullptr);
        for (int i = 0; i < node->neighbors.size(); i++) {
            Node* copy = cloneGraph_helper(nodes, node->neighbors[i]);
            nodes[node->val - 1]->neighbors[i] = copy;
        }
        return nodes[node->val - 1];
    }
};
