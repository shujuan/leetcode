import java.util.*;
class MeetingRooms2 {
    public static void main(String[] args){
        MeetingRooms2 test = new MeetingRooms2();
        int[][] intervals = {{0,30}, {5,10}, {15,20}};
        System.out.println(test.minMeetingRooms(intervals));
    }

    public int minMeetingRooms(int[][] intervals) {
        int n = intervals.length;
        int[] start = new int[n];
        int[] end = new int[n];
        for (int i=0; i<n; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        Arrays.sort(start);
        Arrays.sort(end);
        int res = 0, endpos =0;
        for(int i=0; i<n; i++) {
            if(start[i] < end[endpos]) {
                res++;
            } else {
                endpos++;
            }
        }
        return res;
        
    }
}
