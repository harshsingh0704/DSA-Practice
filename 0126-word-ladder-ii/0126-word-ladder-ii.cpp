class Solution {
public:

    // Stores all shortest transformation sequences
    vector<vector<string>> ans;

    // parent[word] = list of words from which 'word'
    // can be reached in the shortest path
    unordered_map<string, vector<string>> parent;

    // DFS to reconstruct all paths from endWord to beginWord
    void dfs(string word, string beginWord, vector<string>& path) {

        // Base case: reached beginWord
        if(word == beginWord) {

            // Path is currently from end -> begin
            // Reverse it to get begin -> end
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());

            ans.push_back(temp);
            return;
        }

        // Explore all parents of current word
        for(auto &par : parent[word]) {

            path.push_back(par);

            dfs(par, beginWord, path);

            path.pop_back(); // backtrack
        }
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList) {

        // Store all words in a set for O(1) lookup
        unordered_set<string> st(wordList.begin(), wordList.end());

        // If endWord is not present, no transformation possible
        if(st.find(endWord) == st.end())
            return {};

        // level[word] = shortest distance from beginWord
        unordered_map<string, int> level;

        queue<string> q;

        q.push(beginWord);

        // beginWord starts at level 0
        level[beginWord] = 0;

        int wordLen = beginWord.size();

        // ---------------- BFS ----------------
        // Build shortest-path parent graph
        while(!q.empty()) {

            string word = q.front();
            q.pop();

            int currLevel = level[word];

            // Save original word because we'll modify it
            string originalWord = word;

            // Change every character one by one
            for(int i = 0; i < wordLen; i++) {

                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    // Ignore words not in dictionary
                    if(st.find(word) == st.end())
                        continue;

                    // First time visiting this word
                    if(level.find(word) == level.end()) {

                        level[word] = currLevel + 1;

                        q.push(word);

                        // Store parent
                        parent[word].push_back(originalWord);
                    }

                    // Same shortest level reached again
                    // Store additional parent
                    else if(level[word] == currLevel + 1) {

                        parent[word].push_back(originalWord);
                    }
                }

                // Restore original character
                word[i] = original;
            }
        }

        // endWord was never reached
        if(level.find(endWord) == level.end())
            return {};

        // ---------------- DFS ----------------
        // Start path reconstruction from endWord

        vector<string> path;

        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};