class Trie {
private:
    class TreeNode
    {
    public:
        char character;
        bool is_word;
        TreeNode* children[26] = {};
        TreeNode(char character = ' ', bool is_word = false) : character(character), is_word(is_word) {}
    };
    TreeNode* root;
public:
    Trie() : root(new TreeNode()) {}

    void insert(string word) {
        int i, index;
        TreeNode* node = root;
        for (i = 0; i < word.size(); i++) {
            index = word[i] - 'a';
            if (node->children[index] == nullptr)
                node->children[index] = new TreeNode(word[i]);
            node = node->children[index];
        }
        node->is_word = true;
    }

    bool search(string word) {
        TreeNode* node = root;
        for (int i = 0; i < word.size() && node; i++)
            node = node->children[word[i] - 'a'] ? node->children[word[i] - 'a'] : nullptr;
        return node && node->is_word;
    }

    bool startsWith(string prefix) {
        TreeNode* node = root;
        for (int i = 0; i < prefix.size() && node; i++)
            node = node->children[prefix[i] - 'a'] ? node->children[prefix[i] - 'a'] : nullptr;
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
