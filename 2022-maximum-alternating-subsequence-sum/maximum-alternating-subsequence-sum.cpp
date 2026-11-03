class Solution {
public:
    long long solve(vector<int>&nums,bool flag,long long idx,vector<vector<long long>>&dp){
        if(idx==nums.size())return 0;
        long long val=nums[idx];
        if(dp[idx][flag]!=-1)return dp[idx][flag];
        if(!flag)val=-val;
        long long skip=solve(nums,flag,idx+1,dp);
        long long take=solve(nums,!flag,idx+1,dp)+val;
        return dp[idx][flag]=max(take,skip);
    }
    long long maxAlternatingSum(vector<int>&nums) {
        vector<vector<long long>>dp(nums.size(),vector<long long>(2,-1));
        long long ans=solve(nums,true,0,dp);
        return ans;
    }
};