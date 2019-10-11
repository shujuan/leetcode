class LRUCache {
    int cap;
    list<pair<int,int>>val;
    unordered_map<int, list<pair<int,int>>::iterator>mp;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        int res = -1;
        if(mp.count(key)){
            res = mp[key]->second;
            val.splice(val.begin(), val, mp[key]);
            mp[key]=val.begin();
        }
        
        return res;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            val.erase(mp[key]);   
        } 
        val.push_front({key, value});
        mp[key]=val.begin();
        if(mp.size() > cap) {
            mp.erase(val.back().first);
            val.pop_back();
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */