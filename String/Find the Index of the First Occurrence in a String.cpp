class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i=0; i<haystack.size(); i++) {
            if (haystack[i] != needle[0]) continue;

            bool valid = true;
            for (int j=1; j<needle.size(); j++) {
                if (haystack[i+j] != needle[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid) return i;
        }
        return -1;
    }
};