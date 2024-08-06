#include <vector>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int total = 0;
        for (int i=0; i<n; i++) total += cardPoints[i];

        if (k == n) return total;

        int win_size = n - k;
        int win_sum = 0;
        for (int i=0; i<win_size; i++) win_sum += cardPoints[i];

        int max_score = INT_MIN;
        for (int i=0; i<n-win_size+1; i++) {
            max_score = max(max_score, total - win_sum);
            cout << max_score << endl;
            if (i + win_size < n) win_sum = win_sum - cardPoints[i] + cardPoints[i + win_size];
        }
        return max_score;

    }
};