class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=part.length();
        string result="";
        for(auto x: s){
            result.push_back(x);
            if(result.length()>=part.length()&& result.substr(result.length()-n)==part){
                result.erase(result.length()-n);
            }
        }

        return result;
    }
};