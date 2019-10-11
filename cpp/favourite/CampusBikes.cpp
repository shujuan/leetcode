struct comb{
    int worker;
    int bike;
    int dist;
    comb(int w, int b, int d){
        worker = w;
        bike = b;
        dist= d;
    }
    // bool const operator < ( const comb& b) {
    //     return dist > b.dist ||(dist== b.dist && worker > b.worker)||(dist==b.dist && worker == b.worker && bike>b.bike);
    // }
};

struct cmp{
    bool operator()(comb& a, comb&b){
        return a.dist > b.dist ||(a.dist== b.dist && a.worker > b.worker)||(a.dist==b.dist && a.worker == b.worker && a.bike>b.bike);
    }
};

class Solution {
    priority_queue<comb, vector<comb>, cmp>pq;
    //priority_queue<comb>pq;
    unordered_map<int,int>visitedW;
    unordered_map<int,int>visitedB;
    
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
      
        for(int i=0; i<workers.size(); i++) {
            for(int j=0; j<bikes.size(); j++) {
                int dist = abs(workers[i][0] -bikes[j][0]) + abs(workers[i][1]- bikes[j][1]);
                
                comb t= comb(i, j, dist);
               // cout<<dist<<" "<<t.dist<<"\n";
                pq.push(t);
            }
        }
        
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            if(visitedW.count(t.worker) || visitedB.count(t.bike)) continue;
         //   cout<<t.worker<<" "<<t.bike<<" "<< t.dist<<"\n";
            visitedW[t.worker] = t.bike;
            visitedB[t.bike] = t.worker;
        }
        
        vector<int>res;
        for(int i=0; i<workers.size(); i++) {
            res.push_back(visitedW[i]);
        }
        return res;
        
        
    }
};