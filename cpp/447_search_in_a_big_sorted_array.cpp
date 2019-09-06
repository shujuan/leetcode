/**
 * Definition of ArrayReader:
 * 
 * class ArrayReader {
 * public:
 *     int get(int index) {
 *          // return the number on given index, 
 *          // return 2147483647 if the index is invalid.
 *     }
 * };
 */
class Solution {
public:
    /*
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader * reader, int target) {
        // write your code here
        if(target == reader->get(0)) return 0;
        if(target < reader->get(0)) return -1;
        int l = 0, r=1;
        while(reader->get(r) <target) {
            r<<=1;
        }
        
        while(l<=r) {
            int mid = (l+r)/2;
            if(reader->get(mid) >= target){
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        if(reader->get(l) == target) return l;
        else return -1;
    }
};
