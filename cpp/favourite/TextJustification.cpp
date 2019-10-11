class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int start=0, curLen=0;
        vector<string>res;
        
        for(int i=0; i<words.size(); i++) {
            if(curLen+words[i].size() > maxWidth){
                string curStr(maxWidth, ' ');
                int extraSpace = maxWidth - curLen+1;
                int eachW = ((i-1)==start) ? 0 : extraSpace/(i-start-1);
                int leftSpace = extraSpace - eachW*(i-start-1);
                
                cout<<extraSpace<<" "<<eachW<<" "<<leftSpace<<"\n";
                int pos =0;
                for(int j=start; j<i; j++){
                    for(int k=0; k<words[j].size(); k++) {
                        curStr[pos++] = words[j][k];
                    }
                    pos += eachW+1;
                    if(leftSpace-->0) pos++;

                }
                res.push_back(curStr);
                start =i;
                curLen =0;
            }
            curLen += words[i].size()+1;
        }
        if(curLen>0) {
            string curStr(maxWidth, ' ');
            int pos =0;
            for(int i=start; i<words.size(); i++) {
                for(int j= 0; j<words[i].size(); j++) {
                    curStr[pos++] = words[i][j];
                }
                pos++;
            }
            res.push_back(curStr);
        }
        
        return res;
    }
};