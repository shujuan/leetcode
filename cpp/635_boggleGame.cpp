struct TrieNode{
    bool isword;
    vector<TrieNode*>child;
    TrieNode() {
        isword = false;
        child.resize(26, nullptr);
    }
};



class Solution {
    int maxCount;
public:
    /*
     * @param board: a list of lists of character
     * @param words: a list of string
     * @return: an integer
     */
    void insert(string word, TrieNode* root) {
        for(auto w:word) {
            if(!root->child[w-'a']) {
                root->child[w-'a'] = new TrieNode();
            }
            root = root->child[w-'a'];
        }
        root->isword=true;
        
    }
    
    
    int boggleGame(vector<vector<char>> &board, vector<string> &words) {
        // write your code here
        TrieNode* root = new TrieNode();
        for(auto w:words) {
            insert(w, root);
        }
        int cnt = 0;
        int m = board.size();
        int n = board[0].size();
        maxCount = 0;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
       // for(int i=0; i<board.size(); i++) {
       //     for(int j=0; j<board[0].size(); j++) {
                dfs(board, 0, 0, visited, root, 0 );
       //     }
       // }
        return maxCount;

    }
    
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, TrieNode* root, int cnt) {
        int m = board.size();
        int n = board[0].size();
        for(int x = i; x<m; x++){
            for(int y=j; y<n; y++) {
                vector<int>paths;
                vector<vector<int>>visitedpaths;
                findNextWord(board, x, y, visited,root, paths, visitedpaths, cnt);
                for(auto visitedP : visitedpaths) {
                    for(auto path : visitedP){
                        visited[path/n][path%n] = true;
                    }
                    dfs(board, x, y, visited, root, cnt+1);
                    for(auto path : visitedP){
                        visited[path/n][path%n] = false;
                    }
                }
            }
            j=0;
        }
       
        
    }
    
    
    void findNextWord(vector<vector<char>>&board, int x, int y, vector<vector<bool>>& visited, TrieNode*curNode, vector<int>& paths, vector<vector<int>>& visitedPaths, int cnt){
        if(visited[x][y] || !curNode->child[board[x][y]-'a']) return;
        curNode = curNode->child[board[x][y] -'a'];
        int m = board.size();
        int n = board[0].size();
        paths.push_back(x*n + y);
        if(curNode->isword) {
            visitedPaths.push_back(paths);
            maxCount = max(maxCount, cnt+1);
            
        }else {
            visited[x][y] = true;
            if(x+1 < m) findNextWord(board, x+1, y, visited, curNode, paths, visitedPaths, cnt);
            if(x-1>=0) findNextWord(board, x-1, y, visited, curNode, paths, visitedPaths, cnt);
            if(y+1 < n) findNextWord(board, x, y+1, visited, curNode, paths, visitedPaths, cnt);
            if(y-1 >=0)  findNextWord(board, x, y-1, visited, curNode, paths, visitedPaths, cnt);
            visited[x][y]=false;
            
        }
        paths.pop_back();
    }
    
    
    
    
    
    
};
