class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size(), n = version2.size();
        int i=0, j=0;
        while(i<m || j<n) {
            int tmp = i;
            while(tmp<m && version1[tmp] != '.'){
                tmp++;
            }
            int num1 = i==tmp ? 0: stoi(version1.substr(i, tmp-i));
            i = tmp==m? m : tmp+1;
            
            tmp = j;
            while(tmp<n && version2[tmp] != '.'){
                tmp++;
            }
            int num2 = j==tmp ? 0 : stoi(version2.substr(j, tmp-j));
            j= tmp==n ? n : tmp+1;
            
            
            if(num1>num2) return 1;
            else if(num1<num2) return -1;
        }
        return 0;
    }
};