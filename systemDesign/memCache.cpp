class Memcache {
    unordered_map<int, pair<int,int>>m;
    
public:
    Memcache() {
        // do intialization if necessary
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @return: An integer
     */
    int get(int curtTime, int key) {
        // write your code here
        if(m.count(key) && m[key].first >= curtTime) {
            return m[key].second;
        }
        else return INT_MAX;
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @param value: An integer
     * @param ttl: An integer
     * @return: nothing
     */
    void set(int curtTime, int key, int value, int ttl) {
        // write your code here
        if(ttl) m[key] = {curtTime+ttl-1, value};
        else m[key] = {INT_MAX, value};
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @return: nothing
     */
    void del(int curtTime, int key) {
        // write your code here
        if(m.count(key)) m.erase(key);
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @param delta: An integer
     * @return: An integer
     */
    int incr(int curtTime, int key, int delta) {
        // write your code here
        if(m.count(key) ) {
            int targetTime = m[key].first;
            if (targetTime < curtTime) return INT_MAX;
            else {
                m[key] = {targetTime, m[key].second+delta};
                return m[key].second;
            }
        }
        return INT_MAX;
    }

    /*
     * @param curtTime: An integer
     * @param key: An integer
     * @param delta: An integer
     * @return: An integer
     */
    int decr(int curtTime, int key, int delta) {
        // write your code here
         if(m.count(key) ) {
            int targetTime = m[key].first;
            if (targetTime < curtTime) return INT_MAX;
            else {
                m[key] = {targetTime, m[key].second-delta};
                return m[key].second;
            }
        }
        return INT_MAX;
    }
};
