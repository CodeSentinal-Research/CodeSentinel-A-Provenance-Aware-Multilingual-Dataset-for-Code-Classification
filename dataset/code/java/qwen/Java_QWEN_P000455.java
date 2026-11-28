import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int d = sc.nextInt();
        int[] weights = new int[n];
        for(int i=0; i<n; i++) weights[i] = sc.nextInt();
        
        int low = Arrays.stream(weights).max().getAsInt();
        int high = Arrays.stream(weights).sum();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(canShip(weights, d, mid)) high = mid;
            else low = mid + 1;
        }
        System.out.println(low);
    }
    static boolean canShip(int[] weights, int d, int cap) {
        int days = 1, load = 0;
        for(int w : weights) {
            if(load + w > cap) { days++; load = w; }
            else load += w;
        }
        return days <= d;
    }
}
