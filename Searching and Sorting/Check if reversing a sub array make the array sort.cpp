#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	bool solve(vector<int>& v) {
		int n = v.size();
		int i = -1;
		int j = -1;

		// get the start and end of the subarray
		for (int x=0; x<n-1; x++) {
			if (v[x] > v[x+1]) {
				if (i == -1) i = x;
				y = x + 1;
			}
		}

		// sorted array
		if (x == -1 && y == -1) return true;

		// reverse subarray
		while (i < j) swap(v[i++], v[j--]);

		// check sorted
		for (int i=0; i<n-1; i++) {
			if (v[i] > v[i+1]) return false;
		}

		return true;
	}
};

int main() {
	Solution sol;

	vector<int> v1 = { 1, 2, 5, 4, 3 };
	for (auto x : v1) cout << x << " ";
	cout << endl;
	cout << (sol.solve(v1) ? "true" : "false") << endl;

	vector<int> v2 = { 1, 2, 4, 5, 3 };
	for (auto x : v2) cout << x << " ";
	cout << endl;
	cout << (sol.solve(v2) ? "true" : "false") << endl;

}