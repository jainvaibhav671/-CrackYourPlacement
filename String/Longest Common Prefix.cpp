#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        string prefix = "";

        int min_len = INT_MAX;
        for (auto x : strs) min_len = min(min_len, (int) x.length());

        while (index < min_len) {
            char ch = strs[0][index];
            for (auto str : strs) {
                if (str.length() == 0) return "";
                if (str[index] != ch) return prefix;
            }

            index++;
            prefix = prefix + ch;
        }

        return prefix;
    }
};