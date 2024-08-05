#include <vector>

class Solution {

    vector<int> dp;
    bool backtrack(vector<int>& nums, int curr) {
        if (curr >= nums.size()) return 0;
        if (curr == nums.size() - 1) return 1;

        if (dp[curr] != -1) return dp[curr];

        int maxJumps = nums[curr];
        for (int jump=1; jump<=maxJumps; jump++) {
            int res = backtrack(nums, curr + jump);

            dp[curr] = res;
            if (res == 1) return res; // reached last index
        }

        return 0;
    }

public:
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return backtrack(nums, 0) == 1;
    }
};