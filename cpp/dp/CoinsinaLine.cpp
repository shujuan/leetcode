class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        vector<bool> f(n+1, false);
        f[0]= false;
        f[1] = true;
        f[2] = true;
        for (int i=3; i<=n; i++) {
            f[i] = f[i-3];
            
        }
        return f[n];
    }
};