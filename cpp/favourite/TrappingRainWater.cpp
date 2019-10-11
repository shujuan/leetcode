class Solution {
public:
    int trap(vector<int>& height) {
        int res =0;
        int n = height.size();
        int left = 0, right = n-1, level=0;
        while(left<right){
            int lower = height[height[left]<height[right]? left++ : right--];
            level = max(level,lower);
            res += level -lower;
            
        }
        return res;
    }
};