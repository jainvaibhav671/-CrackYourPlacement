class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i = 0;
        int j = 0;

        int m = matrix.size();

        while (i < m && j < m) {
            for (int x=i; x<m; x++) swap(matrix[x][i], matrix[i][x]);
            i++;
            j++;
        }

        for (int i=0; i<m; i++) reverse(matrix[i].begin(), matrix[i].end());
    }
};