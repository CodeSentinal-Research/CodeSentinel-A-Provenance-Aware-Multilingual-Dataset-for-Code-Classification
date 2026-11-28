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
        
        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);
        
        int remove = 0;
        int end = Integer.MIN_VALUE;
        for(int[] interval : intervals) {
            if(interval[0] < end) {
                remove++;
            } else {
                end = interval[1];
            }
        }
        System.out.println(remove);
    }
}
