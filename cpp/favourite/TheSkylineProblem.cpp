bool cmp(pair<int,int>& a, pair<int,int>& b) {
    return a.first<b.first ||(a.first == b.first && a.second < b.second);
}

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<pair<int,int>>heights;
        for(int i=0; i<n; i++) {
            heights.push_back({buildings[i][0], -buildings[i][2]});
            heights.push_back({buildings[i][1], buildings[i][2]});
        }
        
        sort(heights.begin(), heights.end(), cmp);
        multiset<int>st;
        st.insert(0);
        vector<vector<int>> res;
        int pre = 0;
        for(int i=0; i<heights.size(); i++) {
            
            if(heights[i].second <0) {
                st.insert(-heights[i].second);
            } else {
                st.erase(st.find(heights[i].second));
            }
            
            int cur = *st.rbegin();
            if(cur != pre) {
                res.push_back({heights[i].first, cur});
            }
            pre = cur;
        }
        
        return res;
    }
};