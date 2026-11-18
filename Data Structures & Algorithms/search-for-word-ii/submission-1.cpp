class Solution {
public:

    struct TrieNode {
        TrieNode* children[26]{};
        string word = "";

        TrieNode() {}
    };

    TrieNode* root;

    vector<string> result;

    int rows, cols;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    Solution() {
        root = new TrieNode();
    }

    void insert(string& word) {

        TrieNode* node = root;

        for (char c : word) {

            int index = c - 'a';

            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }

            node = node->children[index];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int r, int c,
             TrieNode* node) {

        char ch = board[r][c];

        int index = ch - 'a';

        TrieNode* next = node->children[index];

        if (next == nullptr) {
            return;
        }

        if (!next->word.empty()) {

            result.push_back(next->word);

            next->word = "";
        }

        board[r][c] = '#';

        for (int k = 0; k < 4; k++) {

            int nr = r + dx[k];
            int nc = c + dy[k];

            if (nr >= 0 && nr < rows &&
                nc >= 0 && nc < cols &&
                board[nr][nc] != '#') {

                dfs(board, nr, nc, next);
            }
        }

        board[r][c] = ch;
    }

    vector<string> findWords(
        vector<vector<char>>& board,
        vector<string>& words
    ) {

        rows = board.size();
        cols = board[0].size();

        result.clear();

        // Build Trie
        for (string& word : words) {
            insert(word);
        }

        // DFS
        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                dfs(board, i, j, root);
            }
        }

        return result;
    }
};