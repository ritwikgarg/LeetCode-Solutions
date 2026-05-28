class Trie {
private:
    struct Node {
        Node* links[26];
        bool wordEnd = false;

        Node() {
            wordEnd = false;
            for (int i=0; i<26; i++) {
                links[i] = nullptr;
            }
        }

        bool containsKey(char ch) {
            if (links[ch-'a'] != nullptr) return true;
            return false;
        }

        Node* insertKey(char ch) {
            Node* newNode = new Node();
            links[ch-'a'] = newNode;
            return newNode;
        }

        Node* getKey(char ch) {
            return links[ch-'a'];
        }

        void markEnd() {
            wordEnd = true;
        }

        bool checkEnd() {
            return wordEnd;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        int n = word.size();
        for (int i=0; i<n; i++) {
            char ch = word[i];
            if (!node->containsKey(ch)) {
                node = node->insertKey(ch);
            } else {
                node = node->getKey(ch);
            }
        }
        node->markEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        int n = word.size();
        for (int i=0; i<n; i++) {
            char ch = word[i];
            if (node->containsKey(ch)) {
                node = node->getKey(ch);
            } else {
                return false;
            }
        }
        return node->checkEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        int n = prefix.size();
        for (int i=0; i<n; i++) {
            char ch = prefix[i];
            if (node->containsKey(ch)) {
                node = node->getKey(ch);
            } else {
                return false;
            }
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */