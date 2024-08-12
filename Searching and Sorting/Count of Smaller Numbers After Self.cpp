class Solution {

    int findRight(vector<int>& nums, int val) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end-start) / 2;

            if (val > nums[mid]) start = mid + 1;
            else if (val <= nums[mid]) end = mid - 1;
        }

        return start;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sortedNums;
        vector<int> ans;

        int n = nums.size();

        for (int i=n-1; i>=0; i--) {
            int idx = findRight(sortedNums, nums[i]);
            ans.push_back(idx);
            sortedNums.insert(sortedNums.begin() + idx, nums[i]);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};