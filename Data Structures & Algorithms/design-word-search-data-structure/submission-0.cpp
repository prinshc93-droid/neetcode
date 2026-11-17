class WordDictionary {
private:

    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;

            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    // DFS Search
    bool dfs(TrieNode* node, string& word, int index) {

        // Complete word found
        if (index == word.size()) {
            return node->isEnd;
        }

        char ch = word[index];

        // Case 1: Wildcard '.'
        if (ch == '.') {

            for (int i = 0; i < 26; i++) {

                if (node->children[i] != nullptr) {

                    if (dfs(node->children[i],
                            word,
                            index + 1)) {
                        return true;
                    }
                }
            }

            return false;
        }

        // Case 2: Normal character
        int pos = ch - 'a';

        if (node->children[pos] == nullptr) {
            return false;
        }

        return dfs(node->children[pos],
                   word,
                   index + 1);
    }

public:

    WordDictionary() {
        root = new TrieNode();
    }

    // Insert word
    void addWord(string word) {

        TrieNode* curr = root;

        for (char ch : word) {

            int index = ch - 'a';

            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->isEnd = true;
    }

    // Search word
    bool search(string word) {

        return dfs(root, word, 0);
    }
};