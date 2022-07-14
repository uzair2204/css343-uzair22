class Trie {
private:
    class TreeNode
    {
    public:
        //Fields
        char character;
        bool is_word;
        
        //Array of 26 TreeNode objects (one for each letter of the alphabet).
        TreeNode* children[26] = {};
        //Constructor
        TreeNode(char character = ' ', bool is_word = false) : character(character), is_word(is_word) {}
    };
    TreeNode* root;
public:
    Trie() : root(new TreeNode()) {}

    //The insert function takes in a string word and inserts it into the trie.
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
    
    //The search function searches through the trie to find the word passed in as an argument.
    bool search(string word) {
        TreeNode* node = root;
        for (int i = 0; i < word.size() && node; i++)
            node = node->children[word[i] - 'a'] ? node->children[word[i] - 'a'] : nullptr;
        return node && node->is_word;
    }

    //The startsWith function checks to see if the passed argument is a prefix of any word in the dictionary
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
