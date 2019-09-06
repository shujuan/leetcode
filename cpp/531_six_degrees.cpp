/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param graph: a list of Undirected graph node
     * @param s: Undirected graph node
     * @param t: Undirected graph nodes
     * @return: an integer
     */
    int sixDegrees(vector<UndirectedGraphNode*> graph, UndirectedGraphNode* s, UndirectedGraphNode* t) {
        // write your code here
        int n = graph.size();
        unordered_map<UndirectedGraphNode*, bool>visited(n);
        for(auto node : graph) {
            visited[node] = false;
        }
        queue<UndirectedGraphNode*>q;
        q.push(s);
        visited[s] = true;
        if(s== t) return 0;
        int level=0;
        while(!q.empty()){
            level++;
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                auto top = q.front();
                q.pop();
    
                for(auto node : top->neighbors){
                    if(!visited[node]) {
                        if(node == t) return level;
                        q.push(node);
                        visited[node] = true;
                    }
                }
            }
        }
        
        return -1;
    }
};
