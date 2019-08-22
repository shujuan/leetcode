/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
    unordered_map<int,int>father;
    unordered_map<int, vector<int>>cnt;
public:
    /*
     * @param nodes: a array of Undirected graph node
     * @return: a connected set of a Undirected graph
     */
     
     int find(int a){
         if(father[a] != a) {
             return find(father[a]);
         }
         return a;
     }
     
     void unin(int a, int b){
         int root_a = find(a);
         int root_b = find(b);
         if(root_a != root_b){
             father[root_b] = root_a;
             for(auto c: cnt[root_b]){
                 cnt[root_a].push_back(c);
             }
             cnt.erase(root_b);
         }
     }
     
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*> nodes) {
        // write your code here
        for(int i=0; i<nodes.size(); i++) {
            father[nodes[i]->label] = nodes[i]->label;
            cnt[nodes[i]->label].push_back(nodes[i]->label);
        }
        
        for(int i=0; i<nodes.size(); i++) {
            for(auto n : nodes[i]->neighbors){
                unin(nodes[i]->label, n->label);
            }
        }
        
        vector<vector<int>> res;
        for(auto c : cnt){
            auto v = c.second;
            sort(v.begin(), v.end());
            res.push_back(v);
        }
        return res;
    }
};
