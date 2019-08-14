class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        sort(S.begin(), S.end());
        int res = 0;
        int n = S.size();
        for(int i = n-1; i>=2; i--) {
            int left =0;
            for(int right = i-1; right > left; right--){
                while(left < right && S[left] + S[right] <= S[i]){
                    left++;
                }
                res += right-left;
               
            }
        }
        return res;

    }
};
