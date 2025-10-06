#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        unordered_map<char,int> need, window;
        for (char c : t) need[c]++;

        int have = 0, required = need.size();
        int l = 0, r = 0, minLen = INT_MAX, start = 0;

        while (r < s.size()) {
            char c = s[r++];
            window[c]++;
            if (need.count(c) && window[c] == need[c]) have++;

            while (have == required) {
                if (r - l < minLen) {
                    minLen = r - l;
                    start = l;
                }
                char d = s[l++];
                if (need.count(d) && window[d]-- == need[d]) have--;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

int main() {
    Solution sol;
    cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl; // Output: "BANC"
    return 0;
}
