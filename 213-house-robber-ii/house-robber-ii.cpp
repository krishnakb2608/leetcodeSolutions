class Solution {
public:
    int solve(vector<int>&nums,int start,int end,vector<int>&dp){
        dp[start]=nums[start];
        if(start==end)return dp[start];
        dp[start+1]=max(nums[start],nums[start+1]);
        for(int i=start+2;i<=end;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp(nums.size());
        vector<int>dp1(nums.size());
        int first=solve(nums,0,n-2,dp);
        int second=solve(nums,1,n-1,dp1);
        return max(first,second);

    }
};