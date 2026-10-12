class Solution {
public:
    void solve(string& tiles, int& result, vector<int>& used) {
        for (int i = 0; i < tiles.size(); i++) {
            if (used[i])
                continue;
            if (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1])
                continue;
            result++;
            used[i] = 1;
            solve(tiles, result, used);
            used[i] = 0;
        }
    }
    int numTilePossibilities(string tiles) {
        int result = 0;
        vector<int> used(tiles.size(), 0);
        sort(tiles.begin(), tiles.end());
        solve(tiles, result, used);
        return result;
    }
};