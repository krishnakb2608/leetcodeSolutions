class LRUCache {
private:
    int size;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    list<int>dll;
public:
    LRUCache(int capacity) {
        this->size=capacity;

    }
    
    int get(int key) {
        if(!mp.count(key))return -1;
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            dll.erase(mp[key].first);
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            return;
        }
        if(mp.size()==this->size){
            int x=dll.back();
            mp.erase(x);
            dll.pop_back();
        }
        dll.push_front(key);
        mp[key]={dll.begin(),value};

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */