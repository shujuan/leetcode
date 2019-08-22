struct Node{
    int val;
    int from_id;
    int index;
    Node(int v, int f, int i) {
        val = v;
        from_id = f;
        index = i;
    }
    bool operator <( const Node& n) const {
        return val < n.val;
    }
    
};

class Solution {
public:
    /**
     * @param arrays: a list of array
     * @param k: An integer
     * @return: an integer, K-th largest element in N arrays
     */
    int KthInArrays(vector<vector<int>> &arrays, int k) {
        // write your code here
        int n = arrays.size();
        priority_queue<Node>pq;
        for(int i=0; i<n; i++) {
            if(arrays[i].empty()) continue;
            sort(arrays[i].begin(), arrays[i].end());
            int val = arrays[i].back();
            int from_id = i;
            int index = arrays[i].size()-1;
            pq.push(Node(val, from_id, index));
        }
        
        for(int i =0; i<k; i++) {
            auto p = pq.top();
            pq.pop();
            if(i==k-1) return p.val;
            if(p.index >0) {
                int pre = p.index-1;
                int val = arrays[p.from_id][pre];
                pq.push(Node(val, p.from_id, pre));
            }
        }
    }
};
