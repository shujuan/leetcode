class TicTacToe {
    vector<vector<int>>cntR;
    vector<vector<int>>cntC;
    vector<vector<int>>cntD;
    int target;
    
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        cntR.resize(2, vector<int>(n, 0));
        cntC.resize(2, vector<int>(n, 0));
        cntD.resize(2, vector<int>(2, 0));
        target = n;
        
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(++cntR[player-1][row]==target) return player;
        if(++cntC[player-1][col] == target ) return player;
        if(row == col && ++cntD[player-1][0] == target)return player;
        if(row+col == (target-1) && ++cntD[player-1][1] == target) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */