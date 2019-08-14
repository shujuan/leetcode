/**
 * Definition of Location:
 * class Location {
 * public:
 *     double latitude, longitude;
 *     static Location create(double lati, double longi) {
 *         // This will create a new location object
 *     }
 * };
 * Definition of Restaurant
 * class Restaurant {
 * public:
 *     int id;
 *     string name;
 *     Location location;
 *     static Restaurant create(string &name, Location &location) {
 *         // This will create a new restaurant object,
 *         // and auto fill id
 *     }
 * };
 * Definition of Helper
 * class Helper {
 * public:
 *     static get_distance(Location &location1, Location &location2) {
 *         // return distance between location1 and location2.
 *     }
 * };
 * class GeoHash {
 * public:
 *     static string encode(Location &location) {
 *         // return convert location to a GeoHash string
 *     }
 *     static Location decode(string &hashcode) {
 *          // return convert a GeoHash string to location
 *     }
 * };
 */
struct Node{
    double distance;
    Restaurant res;
    Node(double d, Restaurant r) {
        distance = d;
        res = r;
    }
    bool operator < (Node& node2) {
        return distance < node2.distance;
    }
    
};
 
class MiniYelp {
    map<string, Restaurant>GeoHashToRes;
    unordered_map<int, string>IdToGeoHash;
    vector<double> distance_ref = {2500, 630, 78, 20, 2.4, 0.61, 0.076, 0.01911, 0.00478, 0.0005971, 0.0001492, 0.0000186};
    
public:
    MiniYelp() {
        // initialize your data structure here.
    }

    // @param name a string
    // @param location a Location
    // @return an integer, restaurant's id
    int addRestaurant(string name, Location &location) {
        // Write your code here
        Restaurant res = Restaurant::create(name, location);
       
        string geohash = GeoHash::encode(location) + ". "+ to_string(res.id);
        GeoHashToRes[geohash] = res;
        IdToGeoHash[res.id] = geohash;
        return res.id;
    }

    // @param restaurant_id an integer
    void removeRestaurant(int restaurant_id) {
        // Write your code here
        auto geohash = IdToGeoHash[restaurant_id];
        IdToGeoHash.erase(restaurant_id);
        GeoHashToRes.erase(geohash);
  
    }

    // @param location a Location
    // @param k an integer, distance smaller than k miles
    // @return a list of restaurant's name and sort by 
    // distance from near to far.
    vector<string> neighbors(Location &location, double k) {
        // Write your code here
        vector<string> res;
        vector<Node> nodes;
        int len = get_len(k);
        
        string req = GeoHash::encode(location).substr(0, len);
        for(auto it = GeoHashToRes.lower_bound(req); it != GeoHashToRes.end(); it++) {
            if(it->first.substr(0,len) != req) break;
            auto curLocation = it->second.location;
            auto dist = Helper::get_distance(location, curLocation);
            if(dist <= k) nodes.push_back(Node(dist,it->second));
        }
        sort(nodes.begin(), nodes.end());
        for(auto node : nodes) {
            res.push_back(node.res.name);
        }
        return res;
        
    }
    
    int get_len(double k){
        for(int i=0; i<distance_ref.size(); i++) {
            if(k>distance_ref[i]) return i;
        }
        return distance_ref.size();
    }
};
