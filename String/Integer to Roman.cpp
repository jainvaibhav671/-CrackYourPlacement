#include <map>
#include <string>

using namespace std;

class Solution {
    map<int, string> mp;

    int romanKey(int num) {
        int maxi = INT_MIN;
        for (auto [k, v]: mp) {
            if (num >= k) maxi = max(maxi, k);
        }

        return maxi;
    }

public:
    string intToRoman(int num) {

        mp[1] = "I";
        mp[4] = "IV";
        mp[5] = "V";
        mp[9] = "IX";
        mp[10] = "X";
        mp[40] = "XL";
        mp[50] = "L";
        mp[90] = "XC";
        mp[100] = "C";
        mp[400] = "CD";
        mp[500] = "D";
        mp[900] = "CM";
        mp[1000] = "M";

        string ans = "";

        // for (auto [k,v] : mp) cout << k << " " << v << endl;

        while (num != 0) {
            int key = romanKey(num);
            ans = ans + mp[key];
            num = num - key;

            // cout << key << endl;
        }

        return ans;
    }
}