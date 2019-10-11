class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        int n = word.size();
       
        getAbbr(word, 0, "", res, false);
       
        return res;
    }
    
    void getAbbr(string word, int start, string out, vector<string>& res, bool onePass) {
        if(start == word.size()) {
            res.push_back(out);
            return;
        }
        getAbbr(word, start+1, out+word[start], res, false);
        
        if(!onePass) {
            for(int i= 1; i+start<=word.size(); i++) {
                string tmp =  to_string(i);
                getAbbr(word, start+i, out+tmp, res, true );
            }
        }
    }
};