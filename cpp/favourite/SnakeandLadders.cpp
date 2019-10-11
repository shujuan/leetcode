class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int level=0;
        int n = board.size();
        vector<bool>visited(n*n, false);
        queue<int>q;
        int start = 1;
        q.push(start);
        visited[start-1] = true;
        
        while(!q.empty()) {
            level++;
            int k = q.size();
            for(int i=0; i<k; i++) {
                auto t = q.front();
                q.pop();
           

                for(int i=t+1; i<=t+6 && i<=n*n; i++) {
                    if(i==n*n) return level;
                    int tmp = i;
                    int x =0, y=0;
                    getRC(n, tmp, x, y);
                    if(board[x][y] !=-1){
                        tmp=board[x][y];
                        if(tmp== n*n) return level;
                       
                    }
                    if(!visited[tmp-1]){
                        visited[tmp-1] = true;
                        q.push(tmp);
                    }
                }
                
            }
        
            
        }
        return -1;
    }
    
   
   
    
    // void getRC(int num, int sz, int&x, int y) {
    //     x = sz-(num-1)/sz-1;
    //     if((num/sz)%2==0) y = (num-1)%sz;
    //     else y = sz-(num-1)%sz-1;
    // }
    
    void getRC(int m, int j, int& x, int& y) {
        int tmp_x = (j-1)/m;
        int tmp_y = (j-1)%m;
        x = m-tmp_x-1;
        y = (tmp_x%2)? m-tmp_y-1 : tmp_y;
        
    }
};