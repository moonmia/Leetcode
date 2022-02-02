class RandomizedSet {
private:
    unordered_map<int,int>map;
    vector<int>nums;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) 
    {
        if(map.count(val)) return false;
        
        map[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) 
    {
        if(!map.count(val)) return false;
        
        nums[map[val]] = nums.back();
        map[nums.back()] = map[val];
        map.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() 
    {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */