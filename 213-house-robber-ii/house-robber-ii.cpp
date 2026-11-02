class Solution {
public:
    int solve(vector<int>&nums,int start,int end,vector<int>&dp){
        if(start>end)return 0;
        if(dp[start]!=-1)return dp[start];
        int incl=nums[start]+solve(nums,start+2,end,dp);
        int excl=solve(nums,start+1,end,dp);
        return dp[start]=max(incl,excl);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp(nums.size(),-1);
        vector<int>dp1(nums.size(),-1);
        int first=solve(nums,0,n-2,dp);
        int second=solve(nums,1,n-1,dp1);
        return max(first,second);

    }
};