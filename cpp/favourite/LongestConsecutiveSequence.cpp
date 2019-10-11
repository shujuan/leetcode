class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int>st;
        for(auto num : nums) {
            st.insert(num);
        }
        int res = 0;
        for(auto num : nums) {
            if(st.count(num)){
                
                st.erase(num);
                int left = num-1, right = num+1;
                while(st.count(left)) {
                    
                    st.erase(left);
                    left--;
                }
                while(st.count(right)){
                    
                    st.erase(right);
                    right++;
                }
                res = max(res, right-left-1);
                
            }
        }
        return res;
        
    }
};