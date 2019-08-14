#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        vector<int>dp(m+1, 0);
        dp[0]=1;
        for(int i=0; i<A.size(); i++) {
            for(int j=m; j>= A[i]; j--) {
                int cnt = 1;
                while(j >= cnt*A[i]){
                    dp[j] += dp[j-cnt*A[i]];
                    cnt++;
                }
            }
        }

        return dp[m];
        
    }
};

int main() {
    Solution test = Solution();
    int m = 7;
    vector<int> A = {2, 3, 6, 7};
    int res = test.backPack(m, A);
    printf("The test result is %d\n", res);

}
