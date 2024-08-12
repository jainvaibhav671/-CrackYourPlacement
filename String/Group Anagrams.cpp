class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for (auto str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(str);
        }

        for (auto [k, v] : mp) {
            ans.push_back(v);
        }

        // sort(ans.begin(), ans.end(), [](auto v1, auto v2) {
        //     return v1.size() < v2.size();
        // });

        return ans;
    }
};