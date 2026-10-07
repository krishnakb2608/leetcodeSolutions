class Solution {
public:
    void solve(vector<int>&cookies,int k,vector<int>&bags,int &result,int idx){
        if(idx==cookies.size()){
            int unfairness=0;
            for(int i=0;i<k;i++){
                unfairness=max(unfairness,bags[i]);
            }
            result=min(result,unfairness);
            return;
        }

        for(int i=0;i<k;i++){
            bags[i]+=cookies[idx];
            if(bags[i]<result)solve(cookies,k,bags,result,idx+1);
            bags[i]-=cookies[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>bags(k,0);
        int result=INT_MAX;
        solve(cookies,k,bags,result,0);
        return result;
    }
};