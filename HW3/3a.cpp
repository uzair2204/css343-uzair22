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
    //Main function
    Node* cloneGraph(Node* node) {
        //Create node array
        Node* nodes[100];
        for (int i = 0; i < 100; i++) {
            //Set all nodes in array to nullptr
            nodes[i] = nullptr;
        }
        //Call helper function
        Node* copy = cloneGraph_helper(nodes, node);
        return copy;
    }
    
    //Helper function. Used to create a clone of the graph.
    Node* cloneGraph_helper(Node* nodes[100], Node* node) {
        //Return null if no such node exists.
        if (!node)
            return node;
        //check if there are any nodes before the given node in order to find its predecessor.
        //If there are no nodes before the given node, then it will return a new Node object with an index value of 0.
        if (nodes[node->val - 1])
            return nodes[node->val - 1];
        nodes[node->val - 1] = new Node();
        nodes[node->val - 1]->val = node->val;
        nodes[node->val - 1]->neighbors = vector<Node*>(node->neighbors.size(), nullptr);
        //Creates a new Node object with the same value as the current node and sets its neighbors to a vector containing all of its neighboring nodes.
        for (int i = 0; i < node->neighbors.size(); i++) {
            Node* copy = cloneGraph_helper(nodes, node->neighbors[i]);
            nodes[node->val - 1]->neighbors[i] = copy;
        }
        //Returns the newly created Node object that was returned from this function call.
        return nodes[node->val - 1];
    }
};
