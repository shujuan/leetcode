class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if(!m) return false;
        int n = board[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) {
                
                if(getWord(board, word, visited, 0, i, j)) return true;
            }
        }
        return false;
    }
    
    bool getWord(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int start, int i, int j) 
    {
        
        if(start >= word.size()) return true;
        if(i<0 || j<0 || i>= board.size() || j>=board[0].size() ||word[start] != board[i][j] || visited[i][j]) 
            return false;
        visited[i][j] = true;
        bool res= getWord(board, word, visited, start+1, i-1, j) || getWord(board,word, visited, start+1, i+1, j)
            || getWord(board, word, visited,  start+1, i, j-1) || getWord(board, word, visited, start+1, i, j+1);
        visited[i][j] = false;
        return res;
        
    }
};