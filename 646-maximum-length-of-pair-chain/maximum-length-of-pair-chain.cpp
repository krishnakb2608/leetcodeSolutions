class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int count=0;
        int prevIdx=-1;
        sort(pairs.begin(),pairs.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });
        for(int i=0;i<pairs.size();i++){
            int nextNum=pairs[i][0];
            if(prevIdx==-1||nextNum>pairs[prevIdx][1]){
                count++;
                prevIdx=i;
            }
        }
        return count;
    }
};