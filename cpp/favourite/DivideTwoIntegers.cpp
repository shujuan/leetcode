class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        if(dividend==INT_MIN&&divisor==1||dividend==INT_MAX&&divisor==-1) return INT_MIN;
        int sign = (dividend < 0)^(divisor< 0)?-1:1;
        long long div = labs(dividend);
        long long dis = labs(divisor);
        int res=0;
        while(div >= dis) {
            long long m = dis;
            int tmp = 1;
            while(div>=m<<1) {
                m<<=1;
                tmp<<=1;
            }
            div-= m;
            res+=tmp;
            
        }
        //if (res==INT_MIN && sign == -1) return INT_MAX;
        return res*sign;
        
    }
};