class Solution {
public:
    void solve(vector<vector<int>>& visited,
               int totalCells,
               int& ways,
               vector<vector<int>>& grid,
               int row,
               int col,
               int m,
               int n,
               int countVisited) {

        if(row < 0 || row == m || col < 0 || col == n)
            return;

        if(grid[row][col] == -1 || visited[row][col])
            return;

        if(grid[row][col] == 2) {
            if(countVisited == totalCells)
                ways++;
            return;
        }

        visited[row][col] = 1;

        solve(visited, totalCells, ways, grid,
              row - 1, col, m, n, countVisited + 1);

        solve(visited, totalCells, ways, grid,
              row + 1, col, m, n, countVisited + 1);

        solve(visited, totalCells, ways, grid,
              row, col - 1, m, n, countVisited + 1);

        solve(visited, totalCells, ways, grid,
              row, col + 1, m, n, countVisited + 1);

        visited[row][col] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int totalCells = 0;
        int startRow = 0, startCol = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] != -1)
                    totalCells++;

                if(grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                }
            }
        }

        int ways = 0;

        vector<vector<int>> visited(
            m, vector<int>(n, 0)
        );

        solve(visited, totalCells, ways, grid,
              startRow, startCol, m, n, 1);

        return ways;
    }
};