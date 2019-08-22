class ConnectingGraph2 {
    vector<int>father;
    vector<int>cnt;
public:
    /*
    * @param n: An integer
    */ConnectingGraph2(int n) {
        // do intialization if necessary
        father.resize(n+1);
        cnt.resize(n+1, 1);
        for(int i=1; i<=n; i++) {
            father[i] = i;
        }
    }
    
    int find(int a) {
        if(father[a] != a){
            return find(father[a]);
        }
        return a;
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        // write your code here
        int root_a = find(a);
        int root_b = find(b);
        if(root_a != root_b) {
            father[root_b] = root_a;
            cnt[root_a] += cnt[root_b];
        }
    }

    /*
     * @param a: An integer
     * @return: An integer
     */
    int query(int a) {
        // write your code here
        int root_a = find(a);
        return cnt[root_a];
    }
};
