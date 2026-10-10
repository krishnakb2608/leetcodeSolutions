class Solution {
public:

    void solve(vector<vector<int>>&grid,int row,int col,int ans,vector<vector<int>>&visited,int &finalAns){
        int m=grid.size();
        int n=grid[0].size();
        if(row<0||row>=m||col<0||col>=n)return;
        if(visited[row][col])return;
        if(grid[row][col]==0)return;
        visited[row][col]=1;
        ans+=grid[row][col];
        finalAns=max(ans,finalAns);
        solve(grid,row+1,col,ans,visited,finalAns);
        solve(grid,row,col+1,ans,visited,finalAns);
        solve(grid,row-1,col,ans,visited,finalAns);
        solve(grid,row,col-1,ans,visited,finalAns);
        visited[row][col]=0;
        // ans-=grid[row][col]; 
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int finalAns=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                solve(grid,i,j,ans,visited,finalAns);
            }
        }
        return finalAns;
    }
};