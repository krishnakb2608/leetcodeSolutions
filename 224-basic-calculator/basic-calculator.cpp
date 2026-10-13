class Solution {
public:
    int calculate(string s) {
        long long number = 0;
        long long result = 0;
        int sign = 1;
        stack<long long> st;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');
                continue;
            } else if (s[i] == '+') {
                result += number * sign;
                number = 0;
                sign = 1;
            } else if (s[i] == '-') {
                result += number * sign;
                number = 0;
                sign = -1;
            } else if (s[i] == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                number = 0;
                sign = 1;
            } else if (s[i] == ')') {
                result += number * sign;
                number = 0;

                long long sig = st.top();
                st.pop();

                long long num = st.top();
                st.pop();

                result *= sig;
                result += num;
            }
        }

        result += number * sign;

        return static_cast<int>(result);
    }
};