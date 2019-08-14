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
    int backPack(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        vector<int>dp(m+1, 0);
        
        for(int i=0; i<A.size(); i++) {
            for(int j=m; j>= A[i]; j--) {
                dp[j] = max(dp[j], dp[j-A[i]] + V[i]);
            }
        }

        return dp[m];
        
    }
};

int main() {
    Solution test = Solution();
    int m = 10;
    vector<int> A = {2, 3, 5, 7};
    vector<int> V = {1,5, 2, 4};
    int res = test.backPack(m, A, V);
    printf("The test result is %d\n", res);

}
