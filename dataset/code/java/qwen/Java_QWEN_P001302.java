import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] intervals = new int[n][2];
        for(int i=0; i<n; i++) {
            intervals[i][0] = sc.nextInt();
            intervals[i][1] = sc.nextInt();
        }
        
        List<int[]> events = new ArrayList<>();
        for(int[] interval : intervals) {
            events.add(new int[]{interval[0], 1});
            events.add(new int[]{interval[1], -1});
        }
        
        Collections.sort(events, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        
        int maxRooms = 0;
        int current = 0;
        for(int[] event : events) {
            current += event[1];
            maxRooms = Math.max(maxRooms, current);
        }
        System.out.println(maxRooms);
    }
}
