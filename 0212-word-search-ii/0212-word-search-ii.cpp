class Solution {
private:
    struct Node {
        Node* links[26];
        bool wordEnd;
        string word;

        Node() {
            wordEnd = false;
            word = "";

            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
        }

        bool containsKey(char ch) {
            return links[ch - 'a'] != nullptr;
        }

        Node* getKey(char ch) {
            return links[ch - 'a'];
        }

        void putKey(char ch) {
            links[ch - 'a'] = new Node();
        }
    };

    Node* root;

    void insert(string word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->putKey(ch);
            }

            node = node->getKey(ch);
        }

        node->wordEnd = true;
        node->word = word;
    }

    void dfs(
        int row,
        int col,
        vector<vector<char>>& board,
        vector<vector<bool>>& visited,
        Node* node,
        vector<string>& ans
    ) {
        int m = board.size();
        int n = board[0].size();

        if (row < 0 || row >= m || col < 0 || col >= n) {
            return;
        }

        if (visited[row][col]) {
            return;
        }

        char ch = board[row][col];

        if (!node->containsKey(ch)) {
            return;
        }

        node = node->getKey(ch);

        if (node->wordEnd) {
            ans.push_back(node->word);

            // Prevent duplicate answers
            node->wordEnd = false;
        }

        visited[row][col] = true;

        dfs(row + 1, col, board, visited, node, ans);
        dfs(row - 1, col, board, visited, node, ans);
        dfs(row, col + 1, board, visited, node, ans);
        dfs(row, col - 1, board, visited, node, ans);

        visited[row][col] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();

        for (string& word : words) {
            insert(word);
        }

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<string> ans;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                dfs(row, col, board, visited, root, ans);
            }
        }

        return ans;
    }
};