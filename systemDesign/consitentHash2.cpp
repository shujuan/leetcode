class Solution {
    int shardNum, pointsNum;
    map<int, int>hashcodeToMach;
    set<int>existHash;
public:
    /*
     * @param n: a positive integer
     * @param k: a positive integer
     * @return: a Solution object
     */
    Solution(int s, int p) {
        shardNum = s;
        pointsNum = p;
    }
    static Solution create(int n, int k) {
        // Write your code here
      
        return Solution(n,k);
    }

    /*
     * @param machine_id: An integer
     * @return: a list of shard ids
     */
    vector<int> addMachine(int machine_id) {
        // write your code here
        vector<int>res;
        for(int i=0; i<pointsNum; i++) {
            int hash = rand()%shardNum;
            while(existHash.count(hash)){
                hash = rand()%shardNum;
            }
            existHash.insert(hash);
            res.push_back(hash);
            hashcodeToMach[hash] = machine_id;
        }
        return res;
        
        
        
    }

    /*
     * @param hashcode: An integer
     * @return: A machine id
     */
    int getMachineIdByHashCode(int hashcode) {
        // write your code here
        auto it = hashcodeToMach.lower_bound(hashcode);
        if(it!= hashcodeToMach.end()) {
            return it->second;
        }
        return hashcodeToMach.begin()->second;
    }
};
