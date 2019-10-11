class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>f(n,INT_MAX);
        f[0]=1;
        vector<int>prime{2,3,5};
        vector<int>index(3,0);
        int i=1;
        while(i<n) {
           f[i]=min(prime[0]*f[index[0]], min(prime[1]*f[index[1]], prime[2]*f[index[2]]));
            //for(int j=0;j<3;j++) f[i]=min(f[i], prime[j]*f[index[j]]);
            for(int k=0; k<3; k++) {
                if(f[i] == prime[k]*f[index[k]]) {
                    index[k]++;
                    //break;
                }
            }
            i++;
        }
        
        return f[n-1];
    }
};