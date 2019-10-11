class Solution {
    vector<int>indexNode;
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if(!n) return vector<int>{};
        vector<int>cnt(n, 0);
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto num : nums) {
            mini = min(mini, num);
        }
       // vector<int> nums2(n,0);
        for(int i=0; i<n; i++ ) {
            nums[i] -= mini;
            maxi = max(maxi, nums[i]);
        }
        
        indexNode.resize(maxi+1, 0);
        for(int i= n-1; i>=0; i--) {
            cnt[i] = get(nums[i]-1);
            update(nums[i]);
        }
        return cnt;
    }
        
        
        
//         int len = nums.size();
//         vector<int>count(len,0);
//         if(len==0) return count;
//         vector<int>nums2(len,0);
//         int maxi = INT_MIN;
//         int mini = INT_MAX;
//         for(auto i: nums){
//             mini = i<mini?i:mini;
//         }
//         for(int i=0; i<len; i++){
//             nums2[i]=nums[i]-mini;
//             maxi = nums2[i]>maxi?nums2[i]:maxi;
//         }
//         indexNode.resize(maxi+1, 0);
        
//         for(int i= len-1; i>=0; i--){
//             count[i]=get(nums2[i]-1);
//             update(nums2[i]);  
//         }
      
//         return count;
//     }
    
//     int get(int index){
//         int res=0;
//         for(int i = index; i>=0; i -= i&(-i)) {
//             res += indexNode[i];
//             if(i==0) break;
//         }
//         return res;
//     }
    
//     void update(int index){
//         for(int i= index; i<indexNode.size(); i += i&(-i)) {
//             indexNode[i]++;
//             if(i==0) break;
//         }
//     }
    
    
      
    int get(int i){
        int res=0;
       
        while(i>=0){
            res+=indexNode[i];
            if(i==0) break;
            i-=i&(-i);
        }
        return res;
    }
    
    void update(int i){
        
        while(i<indexNode.size()){
            indexNode[i]++;
            if(i==0) break;
            i+=i&(-i);
        }
        
    }
};