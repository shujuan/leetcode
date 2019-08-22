class UF{
private:
    unordered_map<int, int>father;
   
public:
    UF(int n) {
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
    
    void unin(int a, int b){
        int root_a = find(a);
        int root_b = find(b);
        if(root_a != root_b) {
            father[root_b] = root_a;
        }
    }


};




class ConnectingGraph {
    UF* f;
public:
    /*
    * @param n: An integer
    */ConnectingGraph(int n) {
        // do intialization if necessary
        f = new UF(n);
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        // write your code here
        f->unin(a, b);
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: A boolean
     */
    bool query(int a, int b) {
        // write your code here
        return f->find(a) == f->find(b);
    }
};
