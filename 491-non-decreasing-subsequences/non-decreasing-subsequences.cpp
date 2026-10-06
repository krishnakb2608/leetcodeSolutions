class Solution {
public:
    void solve(vector<int>& nums, int idx, vector<int>& temp,
               vector<vector<int>>& result) {
        if (temp.size() >= 2) {
            result.push_back(temp);
        }
        unordered_set<int> st;
        for (int i = idx; i < nums.size(); i++) {
            if (!temp.empty() && nums[i] < temp.back())continue;
            if (st.count(nums[i]))continue;
            st.insert(nums[i]);
            temp.push_back(nums[i]);
            solve(nums,i+1,temp,result);
            temp.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        solve(nums, 0, temp, result);
        return result;
    }
};