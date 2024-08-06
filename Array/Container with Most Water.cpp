#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
      int n = height.size();
      int l = 0;
      int r = n - 1;

      int max_water = INT_MIN;
      while (l < r) {
        int lh = height[l];
        int rh = height[r];

        max_water = max( (r-l) * min(lh, rh), max_water );

        if (height[l] < height[r]) l++;
        else r--;
      }
      return max_water;
    }
};