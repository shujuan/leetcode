class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int>res;
        int n= input.size();
        
        for(int i=0; i<n; i++) {
            if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
                string part1 = input.substr(0, i);
                string part2 = input.substr(i+1);
                
                vector<int>res1 = diffWaysToCompute(part1);
                vector<int>res2 = diffWaysToCompute(part2);
                int c =0;
                for(auto p1 : res1){
                    for(auto p2 : res2) {
                        switch(input[i]) {
                           
                            case '+': c= p1+p2;
                                break;
                            case '-': c = p1-p2;
                                break;
                            case '*': c = p1*p2;
                                break;
                                
                        }
                        res.push_back(c);
                    }
                }
            }
        }
        
        return res.empty() ? vector<int>{stoi(input)} : res;
    }
};