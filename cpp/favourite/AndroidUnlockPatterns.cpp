class Solution {
    vector<vector<int>>preq;
    vector<bool>visited;
    
public:
    Solution(){
        preq.resize(9, vector<int>(9,-1));
        visited.resize(9,false);
        preq[0][2]=preq[2][0]=1;
        preq[0][6]=preq[6][0]=3;
        preq[2][8]=preq[8][2]=5;
        preq[0][8]= preq[8][0]=preq[2][6]=preq[6][2]=preq[3][5]=preq[5][3]=preq[1][7]=preq[7][1]=4;
        preq[6][8]=preq[8][6]=7;
        
    }
    int numberOfPatterns(int m, int n) {
        int res = 0, tmp1=0, tmp2=0, tmp3=0;
        int cnt=1;
        
        dfs(0, m, n, cnt, tmp1);
        dfs(1, m, n, cnt, tmp2);
        dfs(4, m,n, cnt, tmp3);
       // cout<<tmp1<<" " <<tmp2<<" "<<tmp3<<"\n";
        res = 4*tmp1 + 4*tmp2+tmp3 ;
        return res;     
    }
    
    void dfs(int curPos, int m, int n, int cnt, int&res){
        if(cnt >n) return;
        visited[curPos] = true;
        if(cnt>=m && cnt <=n) res++;
        for(int i=0; i<9; i++) {
          //  cout<<i<<" "<<visited[i]<<"\n";
            if(!visited[i]&&(preq[curPos][i]==-1 || visited[preq[curPos][i]])){
               
                dfs(i, m, n, cnt+1, res);
            }
        }
        visited[curPos] = false;
    }
};