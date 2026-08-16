class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        bool negative = false;
        bool started = false;

        for (int i = 0; i < s.size(); i++) {
            if (!started && s[i] == ' ') {
                continue;
            } 
            else if (!started && s[i] == '-') {
                negative = true;
                started = true;
            } 
            else if (!started && s[i] == '+') {
                started = true;
            } 
            else if (s[i] >= '0' && s[i] <= '9') {
                started = true;
                num = num * 10 + (s[i] - '0');
                if (!negative && num > INT_MAX) return INT_MAX;
                if (negative && -num < INT_MIN) return INT_MIN;
            } 
            else {
                break;
            }
        }

        if (negative) num = -num;
        return (int)num;
    }
};

