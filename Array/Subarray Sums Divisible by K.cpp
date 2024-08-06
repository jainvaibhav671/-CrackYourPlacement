#include <vector>

class Solution {
public:

    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(k, 0);

        int sum = 0;
        int count = 0;

        prefix[0] = 1;
        for (int i=0; i<n; i++) {
            sum = (sum + nums[i]) % k;
            if (sum < 0) sum += k;
            
            if (prefix[sum] != 0) count += prefix[sum];
            prefix[sum]++;
        }
        
        return count;
    }
};