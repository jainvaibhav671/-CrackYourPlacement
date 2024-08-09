class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        
        map<int, int> mp;
        for (auto a : arr) {
            mp[a]++;
            // printf("Count %d: %d\n", a, mp[a]);
        };
        
        for (int i=0; i<arr.size(); i++) {
            int target1 = x + arr[i];
            int target2 = arr[i] - x;
            
            // printf("%d %d %d\n", arr[i], target1, target2);
            // printf("%d %d\n\n", mp.count(target1), mp.count(target2));
            if (target1 == arr[i] && mp[target1] > 1) return 1;
            if (target2 == arr[i] && mp[target2] > 1) return 1;
            
            if (target1 != arr[i] && mp[target1] > 0) return 1;
            if (target2 != arr[i] && mp[target2] > 0) return 1;
            
        }
        
        return -1;
        
        // | x - y | = k
        // x - y = +k
        // x - y = -k
    }
};