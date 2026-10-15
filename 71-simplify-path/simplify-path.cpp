class Solution {
public:
    string simplifyPath(string path) {
        // tokenize the complete path using getline function
        string token = "";
        stringstream ss(path);
        stack<string> st;
        while (getline(ss, token, '/')) {
            if (token == "." || token.empty()) {
                continue;
            } else if (token == "..") {
                if (!st.empty())
                    st.pop();
            } else {
                st.push(token);
            }
        }
        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        return result.empty() ? "/" : result;
    }
};