class Solution {
public:
    /**
     * @param x: a double
     * @return: the square root of x
     */
    double sqrt(double x) {
        // write your code here
        bool isDigit = false;
        if(x<1) {
            isDigit = true;
            x=1/x;
        }
        double left =0, right = x;
        while(abs(left-right) >1e-10) {
            double mid = (left+right)/2.0;
            if(mid*mid < x) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return isDigit ? 1/left : left;
    }
};
