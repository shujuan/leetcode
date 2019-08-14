class WebLogger {
public:
    WebLogger() {
        // do intialization if necessary
    }

    /*
     * @param timestamp: An integer
     * @return: nothing
     */
    map<int, int> info;
    void hit(int timestamp) {
        // write your code here
        
        info[timestamp]++;
        
        
    }

    /*
     * @param timestamp: An integer
     * @return: An integer
     */
    int get_hit_count_in_last_5_minutes(int timestamp) {
        // write your code here
        int res=0;
        for(auto it = info.lower_bound(timestamp-300+1); it != info.end() && it->first<=timestamp; it++) {
            res += it->second;
        }
        return res;
        
        
        
    }
};
