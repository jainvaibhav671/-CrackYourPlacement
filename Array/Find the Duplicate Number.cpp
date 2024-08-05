#include <vector>
#include <map>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;

        map<int, int> mp;
        for (auto x : nums) {
            if (mp[x] != 0) return x;
            mp[x]++;
        }

        return n;
    }
};