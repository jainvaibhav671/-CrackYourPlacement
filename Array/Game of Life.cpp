#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> board_copy = board;

        int m = board.size();
        int n = board[0].size();

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int alive_count = 0;

                if (i > 0 && board_copy[i-1][j] == 1) alive_count++; // top
                if (j > 0 && board_copy[i][j-1] == 1) alive_count++; // left
                if (i < m-1 && board_copy[i+1][j] == 1) alive_count++; // bottom
                if (j < n-1 && board_copy[i][j+1] == 1) alive_count++; // right

                if (i > 0 && j > 0 && board_copy[i-1][j-1] == 1) alive_count++; // top-left
                if (i > 0 && j < n-1 && board_copy[i-1][j+1] == 1) alive_count++; // top-right
                if (i < m-1 && j > 0 && board_copy[i+1][j-1] == 1) alive_count++; // bottom-left
                if (i < m-1 && j < n-1 && board_copy[i+1][j+1] == 1) alive_count++; // bottom-right
                
                if (board_copy[i][j] == 0 && alive_count == 3) {
                    board[i][j] = 1;
                } else if (alive_count < 2 || alive_count > 3) {
                    board[i][j] = 0;
                }
            }
        }
    }
};