import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long totalTrips = sc.nextLong();
        int[] time = new int[n];
        for(int i=0; i<n; i++) time[i] = sc.nextInt();
        
        long low = 1;
        long high = Arrays.stream(time).min().getAsInt() * totalTrips;
        
        while(low < high) {
            long mid = low + (high - low) / 2;
            long trips = 0;
            for(int t : time) {
                trips += mid / t;
                if(trips >= totalTrips) break;
            }
            if(trips >= totalTrips) high = mid;
            else low = mid + 1;
        }
        System.out.println(low);
    }
}
