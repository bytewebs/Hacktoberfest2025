#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        unordered_map<string, vector<string>> parents;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        bool found = false;

        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> levelVisited;
            for (int i = 0; i < sz; i++) {
                string word = q.front(); q.pop();
                string temp = word;
                for (int j = 0; j < word.size(); j++) {
                    char orig = temp[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[j] = c;
                        if (!dict.count(temp)) continue;
                        if (temp == endWord) found = true;
                        if (!visited.count(temp)) {
                            parents[temp].push_back(word);
                            levelVisited.insert(temp);
                        }
                    }
                    temp[j] = orig;
                }
            }
            for (auto& w : levelVisited) q.push(w);
            visited.insert(levelVisited.begin(), levelVisited.end());
        }

        vector<vector<string>> res;
        if (found) {
            vector<string> path = {endWord};
            backtrack(endWord, beginWord, parents, path, res);
        }
        return res;
    }

    void backtrack(string word, string& beginWord, unordered_map<string, vector<string>>& parents,
                   vector<string>& path, vector<vector<string>>& res) {
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }
        for (auto& p : parents[word]) {
            path.push_back(p);
            backtrack(p, beginWord, parents, path, res);
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    string begin = "hit", end = "cog";
    vector<string> words = {"hot","dot","dog","lot","log","cog"};
    auto result = sol.findLadders(begin, end, words);
    for (auto& path : result) {
        for (auto& w : path) cout << w << " ";
        cout << endl;
    }
    return 0;
}
