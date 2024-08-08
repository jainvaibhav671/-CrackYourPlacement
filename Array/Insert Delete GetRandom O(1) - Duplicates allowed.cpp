class RandomizedCollection {

    vector<pair<int, int>> nums;
    unordered_map<int, unordered_set<int>> idx_map;

public:
    RandomizedCollection() {}
    
    bool insert(int val) {
        bool exist = idx_map[val].empty();
        idx_map[val].insert(nums.size());
        nums.push_back({ val, nums.size() });

        return exist;        
    }
    
    bool remove(int val) {
        if (idx_map[val].empty()) return false;

        int rm_idx = *idx_map[val].begin();
        idx_map[val].erase(rm_idx);

        auto last_elem = nums.back();
        nums[rm_idx] = last_elem;

        idx_map[last_elem.first].insert(rm_idx);
        idx_map[last_elem.first].erase(nums.size() - 1);

        nums.pop_back();

        if (idx_map[val].empty()) idx_map.erase(val);

        return true;
    }
    
    int getRandom() {
        int randIndex = rand() % nums.size();
        return nums[randIndex].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */