class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>>flagRow(9, vector<bool>(10,false));
        vector<vector<bool>>flagCol(9, vector<bool>(10,false));
        vector<vector<bool>>flagSqu(9, vector<bool>(10, false));
        for(int i=0; i<9; i++) {
            for(int j =0; j<9; j++) {
                if(board[i][j] != '.'){
                    int num = board[i][j]-'0';
                    int index = (i/3)*3 + j/3;
                   // cout<<flagRow[i][num]<<" "<<flagCol[j][num]<<" "<<flagSqu[index][num]<<"\n";
                    if(flagRow[i][num] || flagCol[j][num]||flagSqu[index][num]) return false;
                  
                    flagRow[i][num] = flagCol[j][num] = flagSqu[index][num] =true;
                   
                }
                
                
            }
        }
        
        return true;
        
    }
};