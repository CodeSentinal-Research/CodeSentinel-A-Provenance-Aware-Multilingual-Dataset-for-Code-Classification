import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] houses = new int[n];
        for(int i=0; i<n; i++) houses[i] = sc.nextInt();
        int m = sc.nextInt();
        int[] heaters = new int[m];
        for(int i=0; i<m; i++) heaters[i] = sc.nextInt();
        
        Arrays.sort(houses);
        Arrays.sort(heaters);
        
        int minRadius = 0;
        for(int house : houses) {
            int idx = Arrays.binarySearch(heaters, house);
            if(idx < 0) idx = -idx - 1;
            
            int dist1 = idx < m ? heaters[idx] - house : Integer.MAX_VALUE;
            int dist2 = idx > 0 ? house - heaters[idx - 1] : Integer.MAX_VALUE;
            
            minRadius = Math.max(minRadius, Math.min(dist1, dist2));
        }
        System.out.println(minRadius);
    }
}
