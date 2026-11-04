class Solution {
public:
    bool isPredecessor(string &prev, string &curr) {
        int i = 0, j = 0;
        if (prev.size() + 1 != curr.size())
            return false;
        while (i < prev.size() && j < curr.size()) {
            if (prev[i] == curr[j]) {
                i++;
                j++;
            } else
                j++;
        }
        return i == prev.size();
    }
    int solve(vector<string>& words, int idx, int prev,
              vector<vector<int>>& dp) {
        if (idx == words.size())
            return 0;
        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int skip = solve(words, idx + 1, prev, dp);

        int take = 0;

        if (prev == -1 || isPredecessor(words[prev], words[idx])) {
            take = 1 + solve(words, idx + 1, idx, dp);
        }

        return dp[idx][prev + 1] = max(take, skip);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        vector<vector<int>> dp(words.size(), vector<int>(words.size() + 1, -1));
        return solve(words, 0, -1, dp);
    }
};