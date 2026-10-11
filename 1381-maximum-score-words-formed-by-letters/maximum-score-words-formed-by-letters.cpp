class Solution {
public:
    void solve(vector<string>&words,vector<char>&letters,vector<int>&score,vector<int>freq,int idx,int &result,int n,int x){
        if(idx==n){
            result=max(result,x);
            return;
        }
        int temp=0;
        vector<int>tempVec=freq;
        for(auto x:words[idx]){
            tempVec[x-'a']--;
            if(tempVec[x-'a']<0){
                temp=0;
                break;
            }
            temp+=score[x-'a'];
        }
        x+=temp;
        solve(words,letters,score,tempVec,idx+1,result,n,x);
        x-=temp;
        solve(words,letters,score,freq,idx+1,result,n,x);

    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26,0);
        for(auto x: letters){
            freq[x-'a']++;
        }
        int result=0;
        solve(words,letters,score,freq,0,result,words.size(),0);
        return result;
    }
};