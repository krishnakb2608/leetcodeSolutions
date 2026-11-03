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
        vector<vector<long long>>dp(nums.size()+1,vector<long long>(2,0));
        int n=nums.size();
        for(int idx=n-1;idx>=0;idx--){
            dp[idx][0]=max(dp[idx+1][0],-nums[idx]+dp[idx+1][1]);
            dp[idx][1]=max(dp[idx+1][1],nums[idx]+dp[idx+1][0]);

        }
        return dp[0][1];
    }
};