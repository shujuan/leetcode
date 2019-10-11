class Solution {
public:
    double myPow(double x, int n) {
        if(x==1 || x==0) return x;
        long long p;
        if(n<0) {
            x = 1/x;
            p = labs(n);
        } else if(n==0){
            return 1;
        } else {
            p = n;
        }
        
        double temp = 1;

        while(p>0){
            if(p&1)temp*=x;
            x*=x;
            p>>=1;
        }
       
         return temp;
    }
};