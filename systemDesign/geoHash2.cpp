class GeoHash {
    string _base32 = "0123456789bcdefghjkmnpqrstuvwxyz";
    vector<int> m = {16, 8, 4, 2, 1};
public:
    /*
     * @param geohash: geohash a base32 string
     * @return: latitude and longitude a location coordinate pair
     */
    vector<double> decode(string &geohash) {
        // write your code here
 
        bool isLongi = true;
        double leftLat = -90, rightLat = 90;
        double leftLng = -180, rightLng = 180;
        for(int i =0; i<geohash.size(); i++ ) {
            int cur = _base32.find(geohash[i]);
            for(int j=0; j<5; j++) {
                if(isLongi){
                   
                    updateInterval(leftLng, rightLng, cur, j);
                } else {
                  
                    updateInterval(leftLat, rightLat, cur, j);
                }
                isLongi = !isLongi;
            }
        }
    
        vector<double>res;
        res.push_back((leftLat+rightLat)/2.0);
        res.push_back((leftLng + rightLng)/2.0);
        return res;
    }
    
    void updateInterval(double& left, double& right, int side, int i) {
        
            double mid = (left+right)/2.0;
            if(side & m[i]) {
                left = mid;
            } else {
                right= mid;
            }
       
    }
};
