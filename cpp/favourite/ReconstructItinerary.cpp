class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>>mp;
        for(int i=0; i<tickets.size(); i++) {
            mp[tickets[i][0]].insert(tickets[i][1]);
        }
        
        vector<string>res;
        getItinerary(mp, res, "JFK");
        reverse(res.begin(), res.end());
        return res;
        
    }
    
    void getItinerary(unordered_map<string, multiset<string>>& mp, vector<string>& res, string s) {
        while(mp[s].size()) {
            auto next = *mp[s].begin();
            mp[s].erase(mp[s].begin());
            getItinerary(mp, res, next);
           
        }
        res.push_back(s);
    }
};