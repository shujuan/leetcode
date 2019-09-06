class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        // write your code here
        int sz = nums.size();
        unordered_set<int>st;
        int i=0;
        while( i<sz) {
            if(!st.count(nums[i])) {
                st.insert(nums[i++]);
            }else{
                swap(nums[i], nums[sz-1]);
                sz--;
            }
        }
        
        return sz;
    }
};
