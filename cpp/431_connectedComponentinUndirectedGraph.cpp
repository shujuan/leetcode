/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
    

public:
    /*
     * @param nodes: a array of Undirected graph node
     * @return: a connected set of a Undirected graph
     */

     
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        // write your code here
        unordered_set<UndirectedGraphNode*>visited;
        vector<vector<int>>res;
        int n = nodes.size();
        queue<UndirectedGraphNode*>q;
       
        for(int i=0; i<n; i++){
            
            if(!visited.count(nodes[i])){
                q.push(nodes[i]);
                visited.insert(nodes[i]);
                vector<int>tmp;
                while(!q.empty()) {
                    auto top = q.front();
                    q.pop();
                    tmp.push_back(top->label);
                    cout<< top->label<<'\n';
                    for(auto neigh : top->neighbors) {
                        if(!visited.count(neigh)){
                            q.push(neigh);
                            visited.insert(neigh);
                        }
                    }
                }
                sort(tmp.begin(), tmp.end());
                res.push_back(tmp);
            }
        }
        
        return res;
    
    }
};
