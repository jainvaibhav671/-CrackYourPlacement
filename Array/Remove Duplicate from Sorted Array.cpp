#include <vector>

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int i = 1, j = -1, k = 1;

    int n = nums.size();
    while (i < n) {
      if (nums[i] == nums[i - 1] && j == -1) {
        j = i;
      } else if (nums[i] != nums[i - 1]) {
        if (j != -1)
          nums[j++] = nums[i];
        k++;
      }
      i++;
    }

    return k;
  }
};
