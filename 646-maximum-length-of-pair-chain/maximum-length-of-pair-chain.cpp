class Solution {
public:
    int solve(vector<vector<int>>& pairs, int idx, int prev, int n,
              vector<vector<int>>& dp) {
        if (idx == n)
            return 0;
        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];
        int skip = solve(pairs, idx + 1, prev, n, dp);
        int incl = 0;

        if (prev == -1 || pairs[prev][1] < pairs[idx][0]) {
            incl = 1 + solve(pairs, idx + 1, idx, n, dp);
        }

        return dp[idx][prev + 1] = max(skip, incl);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(pairs.size(), vector<int>(pairs.size() + 1, -1));
        return solve(pairs, 0, -1, pairs.size(), dp);
    }
};