#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int m = matrix.size();
        int n = matrix[0].size();

        int row_start = 0;
        int row_end = m - 1;
        int col_start = 0;
        int col_end = n - 1;

        while (row_start<=row_end && col_start<=col_end) {
            // go right on top row
            for (int j=col_start; j<=col_end; j++) ans.push_back(matrix[row_start][j]);
            row_start++;

            // go down on last column
            for (int i=row_start; i<=row_end; i++) ans.push_back(matrix[i][col_end]);
            col_end--;

            // go left on last row
            if (row_start <= row_end) {
                for (int j=col_end; j>=col_start; j--) ans.push_back(matrix[row_end][j]);
                row_end--;
            }

            // go up on first column
            if (col_start <= col_end) {
                for (int i=row_end; i>=row_start; i--) ans.push_back(matrix[i][col_start]);
                col_start++;
            }
        }
        return ans;
    }
};