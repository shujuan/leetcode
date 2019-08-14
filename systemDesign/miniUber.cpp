/**
 * Definition of Trip:
 * class Trip {
 * public:
 *     int id; // trip's id, primary key
 *     int driver_id, rider_id; // foreign key
 *     double lat, lng; // pick up location
 *     Trip(int rider, double lat, double lng);
 * }
 * Definition of Helper
 * class Helper {
 * public:
 *     static double get_distance(double lat1, double lng1,
 *                         double lat2, double lng2) {
 *         // return distance between (lat1, lng1) and (lat2, lng2)
 *     }
 * };
 */
class MiniUber {
    unordered_map<int,pair<double, double>>driverToDist;
    unordered_map<int, Trip*> driverToTrip;
   
public:
    MiniUber() {
        // initialize your data structure here.
    }

    // @param driver_id an integer
    // @param lat, lng driver's location
    // return matched trip information if there have matched rider or NULL
    Trip* report(int driver_id, double lat, double lng) {
        // Write your code here
        if(driverToTrip.count(driver_id)) {
            return driverToTrip[driver_id];
        } else {
            driverToDist[driver_id] = {lat, lng};
            return nullptr;
        }
        
    }

    // @param rider_id an integer
    // @param lat, lng rider's location
    // return a trip
    Trip* request(int rider_id, double lat, double lng) {
        // Write your code here
        int driver=-1;
        Trip *t = new Trip(rider_id, lat, lng);
        double minDist = -1;
        for(auto d : driverToDist) {
            if(minDist == -1 || Helper::get_distance(lat, lng, d.second.first, d.second.second) < minDist){
                driver = d.first;
                minDist = Helper::get_distance(lat, lng, d.second.first, d.second.second);
            }
        }
        t->driver_id = driver;
        if(driver != -1) {
            driverToDist.erase(driver);
            driverToTrip[driver] = t;
        }
        
        return t;
    }
};
