class Solution {
public:
    /*
     * @param n: a positive integer
     * @return: n x 3 matrix
     */
    vector<vector<int>> consistentHashing(int n) {
        // write your code here
        
        vector<vector<int>>res{{0,359,1}};
        
        for(int i=2; i<=n; i++) {
            int index =1;
            for(int j=2; j<=res.size(); j++){
                if((res[j-1][1]-res[j-1][0])>(res[index-1][1]-res[index-1][0])){
                    index = j;
                }
            }
            int mid = (res[index-1][1]+res[index-1][0])/2;
            int tmp = res[index-1][1];
            res[index-1][1] = mid;
            res.push_back({mid+1, tmp, i});
        }
      
       
        return res;
        
    }
};
