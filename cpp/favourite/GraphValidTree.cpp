class Solution {
    vector<int>parent;
    int cnt;
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int num = edges.size();
        if(num != n-1) return false;
        parent.resize(n);
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
        cnt = n;
        for(int i=0; i<num; i++) {
            connect(edges[i][0], edges[i][1]);
        }
        return cnt == 1;
        
    }
    
    int find(int a) {
        while(parent[a] != a) 
            return find(parent[a]);
        return a;
    }
    
    void connect(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if(root_a != root_b) {
            parent[root_a] = parent[root_b];
            cnt--;
        }
        
    }
};