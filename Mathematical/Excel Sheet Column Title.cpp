class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string title = "";
        while (columnNumber) {
            columnNumber--;
            char ch = (columnNumber % 26) + 'A';
            title = ch + title;
            columnNumber /= 26;
        }

        return title;
    }
};