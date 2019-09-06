struct pos{
    int x, y;
    pos(int a, int b) {
        x = a;
        y = b;
    }
};

class Solution {
public:
    /**
     * @param nums: the given k sorted arrays
     * @return: the median of the given k sorted arrays
     */
    double findMedian(vector<vector<int>> &nums) {
        // write your code here
    if (nums.empty()) 
        {
            return 0;
        }
        int n = 0;
        for (vector<int> & A : nums) 
        {
            n += A.size();
        }
        if (n == 0) 
        {
            return 0;
        }
        
        if (n % 2 == 0) 
        {
            return findKth(nums, n / 2) / 2.0 + findKth(nums, n / 2 + 1) / 2.0;
        }
        
        return findKth(nums, n / 2 + 1);
    }
    
private:
    int findKth(vector<vector<int>> &nums, int k) 
    {
        int lb = INT_MAX, ub = INT_MIN;
        for (vector<int> & A : nums) 
        {
            if (A.empty()) 
            {
                continue;
            }
            lb = min(lb, A[0]);
            ub = max(ub, A.back());
        }
        
        int start = lb, end = ub;
        while (start + 1 < end) 
        {
            int mid = start + (end - start) / 2;
            int count = countLessOrEqual(nums, mid);
            if (count < k) 
            {
                start = mid + 1;
            } 
            else if (count > k) 
            {
                end = mid;
            } 
            else 
            {
                end = mid;
            }
        }
        
        if (countLessOrEqual(nums, start) >= k) 
        {
            return start;
        }
        return end;
    }

    int countLessOrEqual(vector<vector<int>> &nums, int key) 
    {
        int count = 0;
        for (vector<int> & A : nums) 
        {
            count += upper_bound(A.begin(),A.end(), key) - A.begin();
        }
        return count;
    }
    
};
    
//     int rank(vector<int> &A, int key) 
//     {
//         if (A.size() == 0) 
//         {
//             return 0;
//         }
//         int start = 0, end = A.size() - 1;
//         while (start + 1 < end) {
//             int mid = start + (end - start) / 2;
//             if (A[mid] < key) 
//             {
//                 start = mid + 1;
//             } 
//             else if (A[mid] > key) 
//             {
//                 end = mid;
//             } 
//             else 
//             {
//                 start = mid + 1;
//             }
//         }
//         if (A[start] > key) 
//         {
//             return start;
//         }
//         if (A[end] > key) 
//         {
//             return end;
//         }
//         return A.size();
//     }
// };
