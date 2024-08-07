#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto ch : s) {
            if (st.empty()) {
                st.push(ch);
                continue;
            }

            char top = st.top();

            if (ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else if (ch == ')' && top == '(') st.pop();
            else if (ch == '}' && top == '{') st.pop();
            else if (ch == ']' && top == '[') st.pop();
            else return false;
        }

        return st.empty();
    }
};