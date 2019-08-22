/**
 * Definition for a Connection.
 * class Connection {
 * public:
 *   string city1, city2;
 *   int cost;
 *   Connection(string& city1, string& city2, int cost) {
 *       this->city1 = city1;
 *       this->city2 = city2;
 *       this->cost = cost;
 * }
 */
bool compare(Connection& a, Connection&b){
    return (a.cost<b.cost || (a.cost == b.cost && a.city1 <b.city1) || (a.cost == b.cost&& a.city1 == b.city1 && a.city2<b.city2));
}

class Solution {
    
    unordered_map<string,string>father;
    int cnt;
public:
    /**
     * @param connections given a list of connections include two cities and cost
     * @return a list of connections from results
     */
    void unin(string a, string b){
        string root_a = find(a);
        string root_b = find(b);
        if(root_a != root_b){
            father[root_b] = root_a;
            cnt--;
        }
    } 
    
    string find(string a){
        if(father[a] != a) {
            return father[a] = find(father[a]);
        }
        return a;
    }
    vector<Connection> lowestCost(vector<Connection>& connections) {
        // Write your code here
        sort(connections.begin(), connections.end(), compare);
        vector<Connection>res;
        for(auto c: connections){
            string city1 = c.city1;
            string city2 = c.city2;
            string d1, d2;
            if(father.count(city1)){
                d1= find(city1);
            } else {
                father[city1]= city1;
                cnt++;
                d1 = city1;
            }
            
            if(father.count(city2)){
                d2= find(city2);
            } else {
                father[city2]= city2;
                cnt++;
                d2 = city2;
            }
            
            if(d1==d2) continue;
            res.push_back(c);
            unin(d1, d2);
            
        }
        if(cnt != 1) return vector<Connection>();
        sort(res.begin(), res.end(), compare);
        return res;
        
    }
};
