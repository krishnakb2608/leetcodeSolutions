class Solution {
public:
    int solve(vector<int>&nums,int idx,int prev,vector<vector<int>>&dp){
        if(idx==nums.size())return 0;
        if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
        int take=0;
        int skip=solve(nums,idx+1,prev,dp);
        if(prev==-1||nums[idx]>nums[prev]){
            take=1+solve(nums,idx+1,idx,dp);
        } 
        return dp[idx][prev+1]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1)return 1;
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        int ans=solve(nums,0,-1,dp);
        return ans;
    }
};