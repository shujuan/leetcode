class Solution {
public:
    string getPermutation(int n, int k) {
        string str, res;
        int f=1;
        for(int i=1; i<=n; i++) {
            f *= i;
            str += to_string(i);
        }
        k--;
        for(int j=0; j<n; j++) {
            f /=n-j;
            int l = k/f;
            res.push_back(str[l]);
            str.erase(l,1);
            k%=f;
        }
        
        return res;
    }
};