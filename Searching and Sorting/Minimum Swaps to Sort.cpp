#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	   // vector<pair<int, int>> arr;
	   // for (int i=0; i<nums.size(); i++) arr.push_back({ nums[i], i });
	   // sort(arr.begin(), arr.end());
	   
	    map<int, int> mp;
	    for (int i=0; i<nums.size(); i++) mp[nums[i]] = i;
	    
	    for (auto [k,v] : mp) {
	        cout << k << " " << v << endl;
	    }
	    
	    int count = 0;
	    for (int i=0; i<nums.size(); i++) {
	        if (i == mp[nums[i]]) continue;
	        else {
	            int j = mp[nums[i]];
	            swap(nums[i], nums[j]);
	            count++;
	            i--;
	        }
	    }
	    
	    return count;
	    
	    // 4  3  2  0  1
	    // 3  5  6 10 19
	    // 3 19 6  5  10
	    // 0  1  2  3  4
	}
};

int main() {
	vector<int> v = { 10, 19, 6, 5, 3 };

	Solution sol;
	int res = sol.minSwaps(v);
	cout << "Min Swaps: " << res << endl;
}