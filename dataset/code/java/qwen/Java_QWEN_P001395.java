import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] points = new int[n][2];
        for(int i=0; i<n; i++) {
            points[i][0] = sc.nextInt();
            points[i][1] = sc.nextInt();
        }
        
        long count = 0;
        for(int i=0; i<n; i++) {
            Map<Double, Integer> slopes = new HashMap<>();
            for(int j=0; j<n; j++) {
                if(i == j) continue;
                double dx = points[i][0] - points[j][0];
                double dy = points[i][1] - points[j][1];
                double slope = dx == 0 ? Double.POSITIVE_INFINITY : dy / dx;
                slopes.put(slope, slopes.getOrDefault(slope, 0) + 1);
            }
            for(int val : slopes.values()) {
                count += (long)val * (val - 1);
            }
        }
        System.out.println(count);
    }
}
