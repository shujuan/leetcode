class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        if(!m) return 0;
        int n = image[0].size();
        int up = binarySearch(image, 0, x, 0, n, 0);
        int down = binarySearch(image, x+1, m, 0, n, 1);
        int left = binarySearch(image, 0,y, up, down, 2);
        int right = binarySearch(image, y+1, n, up, down, 3);
        return (down - up ) *(right - left);
    }
    
    int binarySearch(vector<vector<char>>& image, int lf, int rt, int low, int high, int type) {
 
        
        while (lf<rt) {
            int mid = (lf+rt)/2;
            
            int k = low;
            while(k< high&& ((type == 2|| type == 3) ? image[k][mid] : image[mid][k])=='0') {
                k++;
                
               
            }
           
            if (k < high == (type&1)) {
                lf = mid+1;
            } else {
                rt = mid ;
            }
        }
        
        return lf;
    }
};