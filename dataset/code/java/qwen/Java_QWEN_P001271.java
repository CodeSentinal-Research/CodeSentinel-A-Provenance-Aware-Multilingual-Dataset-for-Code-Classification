import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] ranges = new int[n+1];
        for(int i=0; i<=n; i++) {
            int r = sc.nextInt();
            int start = Math.max(0, i - r);
            int end = Math.min(n, i + r);
            ranges[start] = Math.max(ranges[start], end);
        }
        
        int taps = 0, end = 0, farthest = 0;
        for(int i=0; i<=n; i++) {
            if(i > farthest) { System.out.println(-1); return; }
            if(i > end) {
                taps++;
                end = farthest;
            }
            farthest = Math.max(farthest, ranges[i]);
        }
        if(farthest < n) System.out.println(-1);
        else System.out.println(taps);
    }
}
