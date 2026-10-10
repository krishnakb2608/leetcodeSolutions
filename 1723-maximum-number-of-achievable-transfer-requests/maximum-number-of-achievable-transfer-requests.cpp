class Solution {
public:
    void solve(vector<vector<int>>&requests,vector<int>&resultant,int &result,int idx,int count,int &n){
        if(idx==requests.size()){
            bool allZero=true;
            for(int &x:resultant){
                if(x!=0)allZero=false;
            }
            if(allZero){
                result=max(result,count);
                
            }
            return;
        }
        int from=requests[idx][0];
        int to=requests[idx][1];
        resultant[from]--;
        resultant[to]++;
        solve(requests,resultant,result,idx+1,count+1,n);
        resultant[from]++;
        resultant[to]--;
        solve(requests,resultant,result,idx+1,count,n);

    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>resultant(n,0);
        int result=INT_MIN;
        solve(requests,resultant,result,0,0,n);
        return result;
    }
};