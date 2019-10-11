class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        int i=0; 
        for(;i<intervals.size(); i++) {
            if(intervals[i][1] < newInterval[0]){
                res.push_back(intervals[i]);
            } else if(newInterval[1] < intervals[i][0]){
                break;
            } else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.push_back(newInterval);
        for(int k=i; k<intervals.size(); k++) {
            res.push_back(intervals[k]);
        }
        
        return res;
    }
};