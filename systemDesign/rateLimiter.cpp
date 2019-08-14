#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    /*
     * @param timestamp: the current timestamp
     * @param event: the string to distinct different event
     * @param rate: the format is [integer]/[s/m/h/d]
     * @param increment: whether we should increase the counter
     * @return: true or false to indicate the event is limited or not
     */
    
    map<string, map<int,int>> cnt;
    bool isRatelimited(int timestamp, string event, string rate, bool increment) {
        // write your code here
        int n = rate.size();
        int rateNum = stoi(rate.substr(0, n-2));
        string unit = string(1, rate[n-1]);
        int unitNum = 0;
        if(unit == "s"){
            unitNum = 1;
        } else if(unit == "m") {
            unitNum = 60;
        } else if(unit == "h") {
            unitNum = 60*60;
        } else if (unit == "d") {
            unitNum = 24*60*60;
        };
        
        int lastTime = timestamp - unitNum+1;
        if(!cnt.count(event)) cnt[event] = map<int,int>();
        auto& mp = cnt[event];
        int num =0;
        
        for(auto it = mp.lower_bound(lastTime); it!=mp.end(); it++) {
            num += it->second;
            if(num >= rateNum) return true;
        }
        
        if(increment) {
            if(mp.count(timestamp)) {
                mp[timestamp]++;
            } else {
                mp[timestamp] = 1;
            }
        }
        
        return false;
        
    }
};


int main() {
    Solution test = Solution();
    bool res = test.isRatelimited(1,"login", "3/m", true);
    printf("first test is %s\n", res?"true" : "false");
    res = test.isRatelimited(11,"login", "3/m", true);
    printf("second test is %s\n", res?"true" : "false");
    res = test.isRatelimited(21,"login", "3/m", true);
    printf("third test is %s\n", res?"true" : "false");
}






