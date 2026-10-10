class Solution {
public:
    void solve(string &digits,unordered_map<char,string>&mp,int idx,string temp,vector<string>&result){
        if(idx==digits.size()){
            result.push_back(temp);
            return;
        }
        char ch=digits[idx];
        string str= mp[ch];
        for(int i=0;i<str.size();i++){
            temp.push_back(str[i]);
            solve(digits,mp,idx+1,temp,result);
            temp.pop_back();
            //there is no option of dont take, we take, explore and then backtrack if wrong
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp;
        vector<string>result;
        solve(digits,mp,0,temp,result);
        return result;
    }
};