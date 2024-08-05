#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        for (auto x : nums) {
            mp[x]++;
            if (mp[x] > n/2) return x;
        }
        return 0;
    }
};