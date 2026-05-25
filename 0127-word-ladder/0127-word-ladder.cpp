class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q; // Stores {word, steps}
        unordered_set<string> st(wordList.begin(), wordList.end());

        q.push({beginWord, 1});

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endWord) return steps;

            string wordCopy = word;
            for (int i=0; i<word.size(); i++) {
                for (char ch='a'; ch<='z'; ch++) {
                    wordCopy[i] = ch;
                    if (st.find(wordCopy) != st.end()) {
                        st.erase(wordCopy);
                        q.push({wordCopy, steps+1});
                    }
                }
                wordCopy = word;
            }
        }
        return 0;
    }
};