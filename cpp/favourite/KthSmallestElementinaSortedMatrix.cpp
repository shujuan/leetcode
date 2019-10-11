struct compare{
    bool operator()(pair<int,int>& a, pair<int,int>& b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int cnt =0;
        priority_queue<pair<int, int>, vector<pair<int,int>>, compare>q;
        
        q.push({0, matrix[0][0]});
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>visited(m*n,0);
        while(!q.empty()) {
            auto t = q.top(); q.pop();
            cnt++;
            if(cnt == k) return t.second;
            int i = t.first/m;
            int j = t.first%m;
            if(i < m-1 && !visited[(i+1)*m + j]) {
                q.push({(i+1)*m + j, matrix[i+1][j]});
                visited[(i+1)*m + j] = 1;
            }
            if(j < n-1 && !visited[i*m+j+1]) {
                q.push({i*m+j+1, matrix[i][j+1]});
                visited[i*m+j+1] = 1;
            }
            
        }
        
        return -1;
        
        
    }
};