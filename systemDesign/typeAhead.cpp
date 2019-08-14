#include<iostream>
#include<unordered_map>
#include<string>
#include<unordered_set>
#include<vector>
using namespace std;
class Typeahead {
public:
    /*
    * @param dict: A dictionary of words dict
    */
    unordered_map<string, vector<int>>diction;
    vector<string>strs;
    
    Typeahead(unordered_set<string> dict) {
        // do intialization if necessary
        int n = dict.size();
        for(string word : dict) {
            int len = word.size();
            strs.push_back(word);
            for(int i=0; i<len; i++){
                for(int j=1; i+j<=len; j++) {
                    string tmp = word.substr(i, j);
                    if(diction.count(tmp)){
                        if(diction[tmp].back() != strs.size()-1){
                            diction[tmp].push_back(strs.size()-1);
                        }
                    } else {
                        diction[tmp] = vector<int>{(int)(strs.size()-1)};
                    }
                }
            }
        }
    }

    /*
     * @param str: a string
     * @return: a list of words
     */
    vector<string> search(string &str) {
        // write your code here
        vector<string>res;
        if(!diction.count(str)) return res;
        for(auto i : diction[str]) {
            res.push_back(strs[i]);
        }
        return res;
    }
};

int main() {
    unordered_set<string>dict = {"Jason Zhang", "James Yu", "Li Zhang", "Yanxin Shi"};
    Typeahead test = Typeahead(dict);
    string str = "Zhang";
    vector<string> res = test.search(str);
    for(string word : res){
      printf("%s\t", word.c_str());
    }
    printf("\n");
    str = "James";
    res = test.search(str);
    for(string word : res){
      printf("%s\t", word.c_str());
    }
    printf("\n");
}


