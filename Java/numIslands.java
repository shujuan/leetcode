class UF{
    int[] father;
    int count;
    public UF(int total){
        count =0;
        father = new int[total];
        for(int i=0; i<total; i++) {
            father[i] = i;
        }   
    }
    
    public int find(int a) {
        if(father[a] != a) {
            return find(father[a]);
        }
        return a;
    }
    
    public void union(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if(root_a != root_b) {
            father[root_b] = root_a;
            count -=1;
        }
    }
}


class NumIslands {
    public static void main(String[] args) {
         NumIslands test = new NumIslands();
         char[][] grid= { {'1','1','1', '1', '0'}, {'1','1','0','1','0'}};
         System.out.println(test.numIslands(grid));
    }

    public int numIslands(char[][] grid) {
        int m = grid.length;
        if(m==0) return 0;
        int n = grid[0].length;
        UF uf = new UF(m*n);
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1') {
                    uf.count++;
                    if(i<m-1 && grid[i+1][j] == '1') uf.union(i*n + j, (i+1)*n + j);
                    if(j<n-1 && grid[i][j+1] == '1') uf.union(i*n+j, i*n+j+1); 
                }
            }
        return uf.count;
    }
}



