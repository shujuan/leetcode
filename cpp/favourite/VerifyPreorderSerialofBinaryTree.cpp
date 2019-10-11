class Solution {
public:
    bool isValidSerialization(string preorder) {
        istringstream in(preorder);
        int cnt =1;
        string s;
        while(getline(in, s, ',')) {
            cnt--;
            if(cnt < 0) return false;
            if(s!= "#") cnt +=2;
        }
        return cnt==0;
    }