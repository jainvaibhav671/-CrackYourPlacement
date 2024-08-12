class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;

        for (int i=0; i<n; i++) {
            int left = (i > 0) ? nums[i-1] : INT_MIN;
            int right = (i < n-1) ? nums[i+1] : INT_MIN;

            if (nums[i] > left && nums[i] > right) return i;
        }

        return -1;
    }
};