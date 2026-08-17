/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(int left,int right,vector<int>&nums){
        if(left>right)return nullptr;
        int maxIdx=left;
        for(int i=left;i<=right;i++){
            if(nums[i]>=nums[maxIdx])maxIdx=i;
        }
        TreeNode * node=new TreeNode(nums[maxIdx]);
        node->left=solve(left,maxIdx-1,nums);
        node->right=solve(maxIdx+1,right,nums);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(0,nums.size()-1,nums);
    }
};