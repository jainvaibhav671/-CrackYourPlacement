class Solution {

    bool isPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }

        return true;
    }

public:
    bool validPalindrome(string s) {

        int n = s.length();

        // if already a palindrome string
        // don't need to remove a character
        if (isPalindrome(s, 0, n - 1)) return true;

        int start = 0;
        int end = n - 1;
        for (int i=0; i<s.length(); i++) {
            if (s[start] == s[end]) {
                start++;
                end--;
            } else {
                return isPalindrome(s, start, end-1) || isPalindrome(s, start+1, end);
            }
        }

        return false;
    }
};