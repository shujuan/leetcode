struct Node{
    int col1;
    int col2;
    int val;
    Node(int c1, int c2, int v){
        col1= c1;
        col2 = c2;
        val = v;
    }
};

struct cmp{
    bool operator()(const Node&a, const Node& b){
        return a.val >= b.val;
    }
};



class Solution {
public:
    /**
     * @param A: an integer arrays sorted in ascending order
     * @param B: an integer arrays sorted in ascending order
     * @param k: An integer
     * @return: An integer
     */
    int kthSmallestSum(vector<int> &A, vector<int> &B, int k) {
        // write your code here
        int lenA = A.size();
        int lenB = B.size();
        if(lenA ==0 || lenB ==0) return 0;
        vector<vector<bool>>visited(lenA, vector<bool>(lenB, false));
        priority_queue<Node, vector<Node>, cmp>pq;
        pq.push(Node(0, 0, A[0]+B[0]));
        visited[0][0]= true;
        int cnt =1;
        while(cnt < k) {
            auto top = pq.top();
            pq.pop();
            if(top.col1+1<A.size() && !visited[top.col1+1][top.col2]){
                visited[top.col1+1][top.col2] = true;
                pq.push(Node(top.col1+1, top.col2, A[top.col1+1]+ B[top.col2]));
            }
            
            if(top.col2+1 < B.size()&& !visited[top.col1][top.col2+1]){
                visited[top.col1][top.col2+1] = true;
                pq.push(Node(top.col1, top.col2+1, A[top.col1]+ B[top.col2+1]));
            }
            cnt++;
        }
        return pq.top().val;
        
        
    }
};
