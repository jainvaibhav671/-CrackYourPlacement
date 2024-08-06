#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        map<int, int> count;

        for (auto x : nums) count[x]++;

        for (auto [k, v] : count) {
            if (v == 2) ans.push_back(k);
        }

        return ans;
    }
};