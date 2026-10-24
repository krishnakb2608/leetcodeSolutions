class RandomizedSet {
private:
    vector<int>vec;
    unordered_map<int,int>mp;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val))return false;
        vec.push_back(val);
        mp[val]=vec.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val))return false;
        int idx=mp[val];
        int lastIdx=vec.size()-1;
        int num=vec[lastIdx];
        if(idx!=lastIdx){
            swap(vec[idx],vec[lastIdx]);
            mp[num]=idx;
        }
        vec.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx=rand()%vec.size();
        return vec[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */