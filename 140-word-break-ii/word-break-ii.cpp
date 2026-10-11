class Solution {
public:
    void solve(string currSentence,int idx,string &s,unordered_set<string>&st,vector<string>&result){
        if(idx==s.length()){
            result.push_back(currSentence);
            return;
        }

        for(int j=idx;j<s.size();j++){
            string word=s.substr(idx,j-idx+1);
            if(st.count(word)){
                string tempSentence=currSentence;
                if(!currSentence.empty()){
                    currSentence+=" ";
                }
                currSentence+=word;
                
                solve(currSentence,j+1,s,st,result);
                currSentence=tempSentence;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string currSentence="";
        unordered_set<string>st;
        for(auto x:wordDict){
            st.insert(x);
        }
        vector<string>result;
        solve(currSentence,0,s,st,result);
        return result;
    }
};