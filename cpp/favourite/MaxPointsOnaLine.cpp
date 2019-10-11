class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res=0;
        
        int n = points.size();
        if(!n) return res;
        for(int i=0; i<n; i++){
            map<pair<int, int>,int>mp;
            int duplicate = 1;
            for(int j=i+1; j<n; j++){
                if(points[i][0]==points[j][0] && points[i][1] == points[j][1]) {
                    duplicate++;
                    continue;
                }
                int diff_x = points[i][0]-points[j][0];
                int diff_y = points[i][1] - points[j][1];
                int commonNum = gcd(diff_x, diff_y);
                mp[{diff_x/commonNum, diff_y/commonNum}]++;
                
            }
            
            res = max(res, duplicate);
            for(auto m:mp){
                res = max(res, m.second+duplicate);
            }
        }
        
        return res;
    }
    
    int gcd(int x, int y) {
        return y==0 ? x : gcd(y, x%y);
    }
};