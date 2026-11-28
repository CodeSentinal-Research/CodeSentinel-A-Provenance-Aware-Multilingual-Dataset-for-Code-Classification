import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] stations = new int[n];
        for(int i=0; i<n; i++) stations[i] = sc.nextInt();
        int k = sc.nextInt();
        
        double low = 0, high = stations[n-1] - stations[0];
        for(int i=0; i<100; i++) {
            double mid = low + (high - low) / 2;
            if(needStations(stations, mid) <= k) high = mid;
            else low = mid;
        }
        System.out.printf("%.6f
", high);
    }
    static int needStations(int[] stations, double dist) {
        int count = 0;
        for(int i=1; i<stations.length; i++) {
            count += (int)((stations[i] - stations[i-1]) / dist);
        }
        return count;
    }
}
