class Solution {
public:
    void solve(vector<int>& nums, int& k, int& result,
               unordered_map<int, int>& mp, int idx) {

        if (idx >= nums.size()) {
            result++;
            return;
        }
        if (!mp.count(nums[idx] + k) && !mp.count(nums[idx] - k)) {
            mp[nums[idx]]++;
            solve(nums, k, result, mp, idx + 1);
            mp[nums[idx]]--;
            if (mp[nums[idx]] == 0)
                mp.erase(nums[idx]);
        }
        solve(nums, k, result, mp, idx + 1);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int result = 0;
        solve(nums, k, result, mp, 0);
        return result - 1;
    }
};