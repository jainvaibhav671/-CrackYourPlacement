#include <iostream>
#include <vector>

using namespace std;

class Solution {

    int dfs(vector<vector<char>>& matrix, int i, int j, pair<int, int> dir) {
        auto [x, y] = dir;
        int m = matrix.size();
        int n = matrix[0].size();
        
        // new coordinates
        i += x;
        j += y;

        // check bounds
        if (i < 0 || j < 0 || i >= m || j >= n) return 0;
        if (matrix[i][j] == 'X') return 1; // if found an X return 1

        return dfs(matrix, i, j, dir); // go further in the 'dir' direction
    }

public:
    void solve(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<char>> copy = matrix;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (copy[i][j] == 'X') continue;

                // check if surrounded by Xs
                int count = 0;
                if (i > 0) count += dfs(copy, i, j, {-1, 0});
                if (j > 0) count += dfs(copy, i, j, {0, -1});
                if (i < m-1) count += dfs(copy, i, j, {1, 0});
                if (j < n-1) count += dfs(copy, i, j, {0, 1});

                if (count == 4) matrix[i][j] = 'X';
            }
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    Solution sol;
    
    vector<vector<char>> matrix1 = {
        {'X', 'O', 'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'O', 'O', 'X'},
        {'O', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'O', 'X', 'O', 'O', 'O'}
    };
    sol.solve(matrix1);

    vector<vector<char>> matrix2 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}
    };
    sol.solve(matrix2);
    return 0;
}
