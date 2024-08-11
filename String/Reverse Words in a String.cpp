class Solution {
public:
    string reverseWords(string s) {
        stack<string> words;

        if (s[s.length() - 1] != ' ') s += ' ';

        int start = 0;
        for (int i=0; i<s.length(); i++) {
            if (s[i] != ' ') continue;

            if (start == i) start++;
            else {
                words.push(s.substr(start, i - start));
                start = i + 1;
            }
        }

        string str = "";
        while (!words.empty()) {
            str += words.top();
            words.pop();
            if (!words.empty()) str += ' ';
        }

        return str;
    }
};