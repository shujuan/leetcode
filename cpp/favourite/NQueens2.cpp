class Solution {
public:
    int totalNQueens(int n) {
        int cnt = 0;
        vector<bool> visitCol(n,false);
        vector<bool> visit45(2*n, false);
        vector<bool> visit135(2*n, false);
        getQueen(cnt, 0, n, visitCol, visit45, visit135);
        return cnt;   
    }
    
    void getQueen(int& cnt, int curRow, int totalRow, vector<bool>& visitCol, vector<bool>& visit45, vector<bool>& visit135) {
        if (curRow == totalRow) {
            cnt++;
            return;
        }
        for(int i = 0; i<totalRow; i++) {
            if (!visitCol[i] && !visit45[i+curRow] && !visit135[curRow-i+totalRow])
            {
               visitCol[i] = visit45[i+curRow] = visit135[curRow-i+totalRow] = true;
                getQueen(cnt, curRow+1, totalRow, visitCol, visit45, visit135);
                visitCol[i] = visit45[i+curRow] = visit135[curRow-i+totalRow] = false;
            }
        }
    }
};