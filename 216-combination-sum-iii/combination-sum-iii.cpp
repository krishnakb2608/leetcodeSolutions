class Solution {
public:
    void solve(int k,int n,vector<int>temp,vector<vector<int>>&ans,int num){
        if(n<0)return;
        if(n==0&&k==0){
            ans.push_back(temp);
            return;
        }
        if(num==10)return;
        
        if(k==0)return;
        solve(k,n,temp,ans,num+1);//skip and move to next
        temp.push_back(num);
        solve(k-1,n-num,temp,ans,num+1);//take and then move
        temp.pop_back();

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(k,n,temp,ans,1);
        return ans;
    }
};