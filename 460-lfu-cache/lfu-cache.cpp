class LFUCache {
private:
    int size;
    int cap;
    unordered_map<int, list<vector<int>>::iterator>
        mp;                           // key,address of the node
    map<int, list<vector<int>>> freq; // vector-> key,value,counter
public:
    LFUCache(int capacity) {
        this->cap = capacity;
        size = 0;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;
        auto &vec = *mp[key];
        int value = vec[1];
        int f = vec[2];
        freq[f].erase(mp[key]);
        if (freq[f].empty())
            freq.erase(f);
        f++;
        freq[f].push_front({key, value, f});
        mp[key] = freq[f].begin();
        return value;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;
        if (mp.count(key)) {
            auto& vec = *mp[key];
            int f = vec[2];
            freq[f].erase(mp[key]);
            if (freq[f].empty())
                freq.erase(f);
            f++;
            freq[f].push_front({key, value, f});
            mp[key] = freq[f].begin();
        }else if(size<cap){
            size++;
            freq[1].push_front({key,value,1});
            mp[key]=freq[1].begin();
        }else{
            //time to remove
            auto &vec=freq.begin()->second;
            int keyToDelete=vec.back()[0];
            vec.pop_back();
            if(vec.empty()){
                freq.erase(freq.begin()->first);
            }
            freq[1].push_front({key,value,1});
            mp.erase(keyToDelete);
            mp[key]=freq[1].begin();
        }
    }
};

