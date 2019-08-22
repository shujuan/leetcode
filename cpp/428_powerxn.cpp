class Solution {
public:
    /**
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, long long n) {
        // write your code here
        double tmp = x;
        double cur=1;
        bool pos = n>0? true : false;
        if(!pos) n= -1*n;
        while (n) {
            if(n&1) {
                cur *= tmp;
            } 
            tmp *= tmp;
            n>>=1;
        }
        return pos ? cur : 1/cur;
    }
};
