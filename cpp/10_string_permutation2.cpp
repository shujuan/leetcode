
class Solution {
public:
    /**
     * @param str: A string
     * @return: all permutations
     */
    vector<string> stringPermutation2(string &str) {
        // write your code here
        vector<string>res;
        sort(str.begin(), str.end());
        string tmp;
        getPermu(str, res, tmp);
        return res;
    }
    void getPermu(string str, vector<string>& res, string tmp) {
        if(str.empty()){
            res.push_back(tmp);
            return;
        }
        for(int i=0; i<str.size(); i++) {
            if(i!=0 && str[i]==str[i-1]) continue;
            tmp += str[i];
            getPermu(str.substr(0, i)+str.substr(i+1), res, tmp);
            tmp.pop_back();
        }
        
    }
    
};
