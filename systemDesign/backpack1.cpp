#include<iostream>
#include<vector>
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
        vector<bool>dp(m+1, false);
        dp[0]=true;
        
        for(int i=0; i<A.size(); i++) {
            for(int j=m; j>= A[i]; j--) {
                dp[j] = dp[j] || dp[j-A[i]];
            }
        }
        
        for(int j=m; j>0; j--) {
            if(dp[j]) return j;
        }
        return -1; 
    }
};

int main() {
    Solution test = Solution();
    int m = 9;
    vector<int> A = {3, 4, 8, 5};
    int res = test.backPack(m, A);
    printf("The test result is %d\n", res);

}
