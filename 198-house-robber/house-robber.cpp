class Solution {
public:
    int solve(vector<int>&nums,int idx,vector<int>&dp){
        int n=nums.size();
        
        if(idx>=n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int incl=nums[idx]+solve(nums,idx+2,dp);
        int excl=solve(nums,idx+1,dp);
        return dp[idx]=max(incl,excl);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        vector<int>dp(nums.size()+1,-1);
        int ans=solve(nums,0,dp);
        return ans;
    }
};