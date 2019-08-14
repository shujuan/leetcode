class HeartBeat {
    unordered_map<string, int>slave_time;
   
    int liveTime;
public:
    HeartBeat() {
        // do intialization if necessary
    }

    /*
     * @param slaves_ip_list: a list of slaves'ip addresses
     * @param k: An integer
     * @return: nothing
     */
    void initialize(vector<string> &slaves_ip_list, int k) {
        // write your code here
        liveTime = k;
        for(int i=0; i<slaves_ip_list.size(); i++) {
            slave_time[slaves_ip_list[i]] = 2*k;
        }
    }

    /*
     * @param timestamp: current timestamp in seconds
     * @param slave_ip: the ip address of the slave server
     * @return: nothing
     */
    void ping(int timestamp, string &slave_ip) {
        // write your code here
        if(slave_time.count(slave_ip)) slave_time[slave_ip] = timestamp + 2*liveTime;
    }

    /*
     * @param timestamp: current timestamp in seconds
     * @return: a list of slaves'ip addresses that died
     */
    vector<string> getDiedSlaves(int timestamp) {
        // write your code here
        vector<string>res;
        for(auto info : slave_time){
            if(info.second <= timestamp) {
                res.push_back(info.first);
            }
        }
        return res;
    }
};
