class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int g_sum=0, l_sum=0;
        int indx=0;
        for(int i=0; i<gas.size(); i++) {
            g_sum += gas[i]-cost[i];
            if(l_sum<0) {
                indx= i;
                l_sum=0;
            }
            l_sum += gas[i]-cost[i];
            
        }
        if(g_sum <0) return -1;
        return indx;
    }
};