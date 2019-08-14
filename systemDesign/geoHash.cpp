class GeoHash {
    string _base32 = "0123456789bcdefghjkmnpqrstuvwxyz";
public:
    /*
     * @param latitude: one of a location coordinate pair 
     * @param longitude: one of a location coordinate pair 
     * @param precision: an integer between 1 to 12
     * @return: a base32 string
     */
    string encode(double latitude, double longitude, int precision) {
        // write your code here
        string hash_code, fullBin;
        string latiBin = getBin(latitude, -90, 90);
        string longiBin = getBin(longitude, -180, 180);
        for(int i=0; i<30; i++) {
            fullBin += longiBin[i];
            fullBin +=latiBin[i];
        }
        for(int i=0; i<60; i+=5) {
            string tmp = fullBin.substr(i, 5);
            int hash = binToInt(tmp); 
            hash_code += _base32[hash];
        }
        return hash_code.substr(0, precision);
    }
    string getBin(double pos, double left, double right) {
        string res;
        for(int i=0; i<30; i++) {
            double mid = (left+ right) /2.0;
            if(pos > mid) {
                res +='1';
                left = mid;
            } else {
                res +='0';
                right = mid;
            }
        }
        
        return res;
        
    }
    
    int binToInt(string bin) {
        int res = 0;
        int base = 1;
        for(int i=bin.size()-1; i>=0; i--) {
            if(bin[i] == '1') {
                res += base;
            }
            base *=2;
        }
        return res;
    }
    
};
