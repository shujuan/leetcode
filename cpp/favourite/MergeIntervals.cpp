class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        int n = intervals.size();
        if(!n) return res;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0]<b[0];});
        for(int i=0; i<n; i++) {
            if(res.empty() || intervals[i][0] > res.back()[1]) res.push_back(intervals[i]);
            else if(intervals[i][1] > res.back()[1]) res.back()[1] = intervals[i][1];
        }
        return res;
    }
};