import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        long[] batteries = new long[m];
        long total = 0;
        for(int i=0; i<m; i++) {
            batteries[i] = sc.nextLong();
            total += batteries[i];
        }
        
        long low = 0, high = total / n;
        while(low < high) {
            long mid = low + (high - low + 1) / 2;
            if(canRun(batteries, n, mid)) low = mid;
            else high = mid - 1;
        }
        System.out.println(low);
    }
    static boolean canRun(long[] batteries, int n, long time) {
        long power = 0;
        for(long b : batteries) {
            power += Math.min(b, time);
        }
        return power >= n * time;
    }
}
