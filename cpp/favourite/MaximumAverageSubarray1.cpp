class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, res = INT_MIN;
        int i=0;
        for(; i<nums.size(); i++) {
            if(i <(k)){
                sum+=nums[i];
                if(i==k-1) res = max(sum/k, res);
                continue;
            }
            sum += nums[i]-nums[i-k]; 
            res = max(sum/k, res);
           // cout<<sum/k <<" "<<res<<"\n";
            
            
        }
        if(i==k) return sum/k;
        return res;
        
    }
};