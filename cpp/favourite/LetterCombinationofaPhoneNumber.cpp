class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>dict={"", "", "abc","def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>res;
        string comb;
        if(digits.empty()) return res;
        getComb(digits, dict, res, comb, 0);
        return res;   
    }
    
    void getComb(string digits, vector<string>& dict, vector<string>& res, string comb, int start) {
        if(start>=digits.size()) {
            res.push_back(comb);
            return;
        }
        
        string str = dict[digits[start]-'0'];
        for(int i= 0; i<str.size(); i++) {
            comb +=str[i];
            getComb(digits, dict, res, comb, start+1);
            comb.pop_back();
        }
        
    }
};