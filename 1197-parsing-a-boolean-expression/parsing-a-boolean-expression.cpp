class Solution {
public:
    char solveOperator(char &op,vector<char>&temp){
        if(op=='!'){
            return temp[0]=='0'?'1':'0';
        }
        if(op=='&'){
            for(auto x:temp){
                if(x=='0')return '0';
            }
            return '1';
        }
        if(op=='|'){
            for(auto x:temp){
                if(x=='1')return '1';
            }
            return '0';
        }
        return '0';
    }
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for (auto x : expression) {
            if (x == '(' || x == '&' || x == '|' || x == '!') {
                st.push(x);
            } else if (x == ',') {
                continue;
            } else if (x == 't') {
                st.push('1');
            } else if (x == 'f') {
                st.push('0');
            } else if (x == ')') {
                vector<char>temp;
                while (st.top()!='(') {
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                st.push(solveOperator(op,temp));
            }
        }
        return st.top()=='0'?0:1;
    }
};