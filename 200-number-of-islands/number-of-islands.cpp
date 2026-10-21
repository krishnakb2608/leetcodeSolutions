class Solution {
public:
    void solve(vector<vector<char>>&grid,int i,int j,int &row,int &col){
        //base case
        if(i<0||i>=row||j<0||j>=col||grid[i][j]=='0'){
            return;
        }

        //operation
        grid[i][j]='0';
        solve(grid,i+1,j,row,col);
        solve(grid,i,j+1,row,col);
        solve(grid,i-1,j,row,col);
        solve(grid,i,j-1,row,col);

    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    count++;
                    solve(grid,i,j,row,col);
                }
            }
        }
        return count;
    }
};