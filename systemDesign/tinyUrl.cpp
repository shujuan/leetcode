#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class TinyUrl {
public:
    /*
     * @param url: a long url
     * @return: a short url starts with http://tiny.url/
     */
     
    string dirs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
   
    unordered_map<string,string>longtoShort_mp;
    unordered_map<string, string>shorttoLong_mp;
    string tinyUrl = "http://tiny.url/";
    string longToShort(string &url) {
        // write your code here
        string shortUrl ;
       
        if(longtoShort_mp.count(url)){
            return tinyUrl + longtoShort_mp[url];
        } else {
            for(int i=0; i<6; i++){
                shortUrl += dirs[rand()%62];
            }
            if(shorttoLong_mp.count(shortUrl)){
                longToShort(url);
            } else {
                longtoShort_mp[url]= shortUrl;
                shorttoLong_mp[shortUrl] = url;
            }
        }
        return tinyUrl+shortUrl;
    }

    /*
     * @param url: a short url starts with http://tiny.url/
     * @return: a long url
     */
    string shortToLong(string &url) {
        // write your code here
        url = url.substr(tinyUrl.size(), url.size()-tinyUrl.size());
        if(shorttoLong_mp.count(url)){
            return shorttoLong_mp[url];
        } else{
            return string{};
        }
        
    }
};


int main() {
    TinyUrl test = TinyUrl();
    string url = "http://www.lintcode.com/faq/?id=10";
    string res = test.longToShort(url);
    printf("longToShort short string is %s \n", res.c_str());
}

