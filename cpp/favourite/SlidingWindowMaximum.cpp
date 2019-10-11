class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>maxQ;
        for(int i=0; i<nums.size(); i++) {
            while(!maxQ.empty() && nums[i]>maxQ.back()) maxQ.pop_back();
            maxQ.push_back(nums[i]);
            if(i<k-1) continue;
            res.push_back(maxQ.front());
            if(maxQ.front()==nums[i-k+1]) maxQ.pop_front();
        }
        return res;
    }
};