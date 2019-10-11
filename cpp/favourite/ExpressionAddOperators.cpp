class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        getString(num, target, 0, 0, "", res);
        return res;
    }
    
    void getString(string num, int target, long curVal, long preVal, string str, vector<string>& res) {
        if(num.empty() && curVal == target){
            res.push_back(str);
            return;
        }
       
        for(int i=1; i<=num.size(); i++) {
            string tmp = num.substr(0,i);
            if (i > 1 && tmp[0] == '0') return;
            if(!str.empty()) {
                getString(num.substr(i), target, curVal+stoll(tmp), stoll(tmp), str+'+'+tmp, res);
                getString(num.substr(i), target, curVal-stoll(tmp), -stoll(tmp), str+'-'+tmp, res);
                getString(num.substr(i), target, curVal-preVal+ preVal*stoll(tmp), preVal*stoll(tmp), str+'*'+tmp, res);
            } else {
                getString(num.substr(i), target, stoll(tmp), stoll(tmp), tmp, res);
            }
            
        }
    }
};