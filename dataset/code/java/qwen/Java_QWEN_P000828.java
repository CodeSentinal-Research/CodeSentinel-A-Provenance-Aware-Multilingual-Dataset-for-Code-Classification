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
        
        int[] starts = new int[n];
        for(int i=0; i<n; i++) starts[i] = intervals[i][0];
        Arrays.sort(starts);
        
        int[] res = new int[n];
        for(int i=0; i<n; i++) {
            int end = intervals[i][1];
            int idx = Arrays.binarySearch(starts, end);
            if(idx < 0) idx = -idx - 1;
            res[i] = idx < n ? idx : -1;
        }
        for(int x : res) System.out.print(x + " ");
    }
}
