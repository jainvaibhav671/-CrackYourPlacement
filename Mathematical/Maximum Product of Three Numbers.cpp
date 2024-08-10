class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() == 3) return nums[0] * nums[1] * nums[2];
        
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int maxProduct = INT_MIN;
        if (nums[0] < 0 && nums[1] < 0)
            maxProduct = max(maxProduct, nums[0] * nums[1] * nums[n-1]);
        
        int j = n - 3;

        while (j >= 0) {
            maxProduct = max(maxProduct, nums[j+2] * nums[j+1] * nums[j]);
            j--;
        }

        return maxProduct;
    }
};