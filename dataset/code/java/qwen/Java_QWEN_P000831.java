import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] bloomDay = new int[n];
        for(int i=0; i<n; i++) bloomDay[i] = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        
        if((long)m * k > n) { System.out.println(-1); return; }
        
        int low = Arrays.stream(bloomDay).min().getAsInt();
        int high = Arrays.stream(bloomDay).max().getAsInt();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(canMake(bloomDay, m, k, mid)) high = mid;
            else low = mid + 1;
        }
        System.out.println(low);
    }
    static boolean canMake(int[] bloomDay, int m, int k, int day) {
        int bouquets = 0, flowers = 0;
        for(int b : bloomDay) {
            if(b <= day) flowers++;
            else flowers = 0;
            if(flowers == k) { bouquets++; flowers = 0; }
        }
        return bouquets >= m;
    }
}
