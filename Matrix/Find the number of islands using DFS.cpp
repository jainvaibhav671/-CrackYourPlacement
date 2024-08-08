#include <iostream>
#include <vector>

using namespace std;

class Solution {

	void dfs(vector<vector<int>>& matrix, pair<int, int> pos) {
		auto [ x, y ] = pos;
		int m = matrix.size();
		int n = matrix[0].size();

		if (x < 0 || y < 0 || x >= m || y >= n || matrix[x][y] == 0) return;

		vector<pair<int, int>> dirs = {
			{ 0, 1 }, { 1, 0 },
			{ 0, -1 }, { -1, 0 },

			{-1, -1}, {1, 1},
			{-1, 1}, {1, -1}
		};

		matrix[x][y] = 0;

		for (auto dir : dirs) {
			auto [dx, dy] = dir;
			dfs(matrix, { x + dx, y + dy });
		}
	}

public:

	int numberOfIslandsDFS(vector<vector<int>> matrix) {
		int m = matrix.size();
		int n = matrix[0].size();

		int count = 0;
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				if (matrix[i][j] == 1) {
					count++;
					dfs(matrix, { i, j });
				}
			}
		}
		return count;
	}
};

int main() {
	vector<vector<int>> matrix = {{1, 1, 0, 0, 0},
		                          {0, 1, 0, 0, 1},
		                          {1, 0, 0, 1, 1},
		                          {0, 0, 0, 0, 0},
		                          {1, 0, 1, 0, 0}};

	Solution sol;
	cout << "Solution: " << sol.numberOfIslandsDFS(matrix) << endl;
}