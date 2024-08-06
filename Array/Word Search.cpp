#include <vector>

using namespace std;

class Solution {

    bool recurse(vector<vector<char>>& board, string& word, int index, int i, int j) {
        if (index == word.length()) return true;

        int m = board.size();
        int n = board[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[index] || board[i][j] == ' ') return false;

        char ch = board[i][j];
        board[i][j] = ' '; // mark the location

        bool top = recurse(board, word, index + 1, i-1, j);
        bool down = recurse(board, word, index + 1, i+1, j);
        bool left = recurse(board, word, index + 1, i, j-1);
        bool right = recurse(board, word, index + 1, i, j+1);

        board[i][j] = ch;
        
        return top || down || left || right;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == word[0]) {
                    if (recurse(board, word, 0, i, j)) return true;
                }
            }
        }
        return false;
    }
};