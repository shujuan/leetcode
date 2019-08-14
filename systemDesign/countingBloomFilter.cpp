class HashFunction{
    int cap, seed;
public:
    HashFunction(int c, int s) {
        cap = c;
        seed = s;
    }
    
    int getHash(string &word){
        int res = 0;
        for(int i=0; i<word.size(); i++) {
            res += res*seed + word[i];
            res %=cap;
        }
        return res;
    }
};



class CountingBloomFilter {
    vector<HashFunction*> genHash;
    vector<int>count;
public:
    /*
    * @param k: An integer
    */CountingBloomFilter(int k) {
        // do intialization if necessary
        for(int i=0; i<k; i++) {
            genHash.push_back(new HashFunction(100000+i, 2*i+k));
        }
        
        count.resize(100000+k,0);
        
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void add(string &word) {
        // write your code here
        for(int i=0; i<genHash.size(); i++) {
            int hash = genHash[i]->getHash(word);
            count[hash]++;
        }
        
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void remove(string &word) {
        // write your code here
        for(int i=0; i<genHash.size(); i++) {
            int hash = genHash[i]->getHash(word);
            if(count[hash]>0)count[hash]--;
        }
        
    }
    

    /*
     * @param word: A string
     * @return: True if contains word
     */
    bool contains(string &word) {
        // write your code here
        for(int i=0; i<genHash.size(); i++) {
            int hash = genHash[i]->getHash(word);
            if(count[hash]<=0)return false;
        }
        return true;
        
        
    }
    
    
    
};
