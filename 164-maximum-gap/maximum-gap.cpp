class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int diff=0;
        if(nums.size()<2){
            return 0;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size()-2;i++){
            int sub=nums[i+1]-nums[i];
            diff=max(diff,sub);
        }
        return diff;
    }
};