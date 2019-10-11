class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double l = INT_MAX, r = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            l = min(nums[i], (int)l);
            r = max(nums[i], (int)r);
        }
        int n = nums.size();
        vector<double>sums(n+1,0);
        while((r-l)>1e-5) {
            double mid = (r+l)/2;
            for(int i=1; i<=n; i++) {
                sums[i] = sums[i-1]+nums[i-1] -mid;
            }
            double preMin =0;
            double sumMax = INT_MIN;
            for(int i=k; i<=n; i++) {
                sumMax = max(sumMax, sums[i]-preMin);
                preMin = min(preMin, sums[i-k+1]);
            }
            
            if(sumMax ==0) {
                return mid;
            } else if(sumMax >0) {
                l=mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};