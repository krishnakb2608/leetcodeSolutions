class Solution {
public:
    double epsilon=1e-6;
    bool solve(vector<double>&cards){
        if(cards.size()==1){
            return abs(cards[0]-24)<=epsilon;
        }

        for(int i=0;i<cards.size();i++){
            for(int j=0;j<cards.size();j++){
                if(i==j)continue;
                //pick two numbers

                vector<double>temp;
                for(int k=0;k<cards.size();k++){
                    if(k!=i&&k!=j)temp.push_back(cards[k]);
                }
                double a=cards[i];
                double b=cards[j];
                vector<double>possibleVal={a+b,a-b,b-a,a*b};
                if(abs(a)>0)possibleVal.push_back(b/a);
                if(abs(b)>0)possibleVal.push_back(a/b);

                for(auto val: possibleVal){
                    temp.push_back(val);
                    if(solve(temp))return true;
                    temp.pop_back();
                }

            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double>nums;
        for(auto x: cards){
            nums.push_back(1.0*x);
        }
        return solve(nums);
    }
};