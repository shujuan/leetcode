class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int res = 0, i=0;
        while (i+k <= n; ) {
            vector<int>m(26,0);
            int mask = 0, max_indx = i;
            for (int j=i; j<n; j++) {
                int t = s[j]- 'a';
                m[t]++;
                if(m[t] < k) mask |= 1<<t;
                else mask &= (~(1<<t));
                if (mask == 0) {
                    res = max(res, j-i+1);
                    max_indx = j;
                }
            }
            i = max_indx+1;
        }
        return res;
    }
};