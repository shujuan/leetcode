class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for (int i=0; i<=31; i++) {
            int cnt =0;
            for(auto num : nums) {
                if((num>>i) & 1) cnt ++;
               
            }
            if(cnt % 3) {
                res|=1<<i;
            }
        }
        return res;
        
        // int ans=0;
        // for (int i=0; i<31; i++) {
        //     if(res&1){
        //         ans|=1;
        //         ans<<=1;
        //         res>>=1;
        //     }
        // }
        // return res;
    }
};