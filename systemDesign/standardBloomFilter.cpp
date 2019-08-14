#include<bitset>

class HashFunction{
    int cap, seed;
public:
    HashFunction(int c, int s) {
        cap = c;
        seed = s;
    }
    
    int getHash(string& word) {
        int res=0;
        for(int i=0; i<word.size(); i++) {
            res += res*seed + word[i];
            res %= cap;
        }
        return res;
    } 
};








class StandardBloomFilter {
    bitset<200000>bits;
    vector<HashFunction*> genHash;
public:
    /*
    * @param k: An integer
    */StandardBloomFilter(int k) {
        // do intialization if necessary
        for(int i=0; i<k; i++) {
            genHash.push_back(new HashFunction(100000+i, 2*i+k));
        }
      
        
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void add(string &word) {
        // write your code here
        for(int i=0; i<genHash.size(); i++) {
            int pos = genHash[i]->getHash(word);
            bits.set(pos);
        }
    }

    /*
     * @param word: A string
     * @return: True if contains word
     */
    bool contains(string &word) {
        // write your code here
        for(int i=0; i<genHash.size(); i++) {
            int pos = genHash[i]->getHash(word);
            if(!bits[pos]) return false;
        }
        return true;
    }
};
