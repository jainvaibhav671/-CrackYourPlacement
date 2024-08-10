class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        long long int totalProduct = 1;
        
        int zeroIndex = -1; // index of first occurence of zero
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                
                // this is second zero
                if (zeroIndex != -1) return vector<long long int>(nums.size(), 0);
                
                zeroIndex = i;
                continue;
            }
            
            totalProduct *= nums[i];
        }

        vector<long long int> ans(nums.size(), 0);
        if (zeroIndex != -1) {
            ans[zeroIndex] = totalProduct;
            return ans;
        }

        for (int i=0; i<nums.size(); i++) ans[i] = totalProduct / nums[i];
        return ans;
    }
};