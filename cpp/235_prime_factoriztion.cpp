class Solution {
public:
    /**
     * @param num: An integer
     * @return: an integer array
     */
    vector<int> primeFactorization(int num) {
        // write your code here
        vector<int>res;
        for(int i=2; i*i<=num; i++) {
            while(num%i == 0) {
                num /=i;
                res.push_back(i);
            }
        }
        
        if(num != 1) res.push_back(num);
        return res;
        
    }
};
