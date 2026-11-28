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
        int[] newInterval = {sc.nextInt(), sc.nextInt()};
        
        List<int[]> result = new ArrayList<>();
        int i = 0;
        while(i < n && intervals[i][1] < newInterval[0]) {
            result.add(intervals[i++]);
        }
        while(i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.add(newInterval);
        while(i < n) {
            result.add(intervals[i++]);
        }
        
        for(int[] r : result) {
            System.out.print("[" + r[0] + "," + r[1] + "] ");
        }
    }
}
