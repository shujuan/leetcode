class TinyUrl2 {
    string dirs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<string, string> longToShortMap;
    unordered_map<string,string> shortToLongMap;
    string tinyUrl = "http://tiny.url/" ;
    
public:
    /*
     * @param long_url: a long url
     * @param key: a short key
     * @return: a short url starts with http://tiny.url/
     */
    string createCustom(string &long_url, string &key) {
        // write your code here
        int n = key.size();
        if( shortToLongMap.count(key) || longToShortMap.count(long_url)) {
            if(longToShortMap.count(long_url) && longToShortMap[long_url] == key) {
                return tinyUrl+key;
            }
            return "error";
        }
        for(int i=0; i<n; i++) {
            if((key[i]>= 'a' &&key[i]<='z') || (key[i]>= 'A' &&key[i]<='Z') ||(key[i]>= '0' &&key[i]<='9')){
                continue;
            } else {
                return "error";
            }
        }
        longToShortMap[long_url] = key;
        shortToLongMap[key] = long_url;
        return tinyUrl+key;
        
    }

    /*
     * @param long_url: a long url
     * @return: a short url starts with http://tiny.url/
     */
    string longToShort(string &long_url) {
        // write your code here
        string shortUrl;
        if(longToShortMap.count(long_url)) return tinyUrl + longToShortMap[long_url];
        for(int i=0; i<6; i++) {
            shortUrl += dirs[rand()%62];
        }
        if(shortToLongMap.count(shortUrl)) {
            return  longToShort(long_url);
        } else {
            longToShortMap[long_url] = shortUrl;
            shortToLongMap[shortUrl] = long_url;
            return tinyUrl + shortUrl;
        }
    }

    /*
     * @param short_url: a short url starts with http://tiny.url/
     * @return: a long url
     */
    string shortToLong(string &short_url) {
        // write your code here
        string tmp = short_url.substr(tinyUrl.size());
        if(shortToLongMap.count(tmp))
            return shortToLongMap[tmp];
        return NULL;
    }
};
