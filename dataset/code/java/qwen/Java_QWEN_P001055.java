import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int target = sc.nextInt();
        int startFuel = sc.nextInt();
        int n = sc.nextInt();
        
        int[][] stations = new int[n][2];
        for(int i=0; i<n; i++) {
            stations[i][0] = sc.nextInt();
            stations[i][1] = sc.nextInt();
        }
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        int fuel = startFuel;
        int stops = 0;
        int prev = 0;
        
        for(int i=0; i<n; i++) {
            int dist = stations[i][0] - prev;
            while(fuel < dist) {
                if(pq.isEmpty()) {
                    System.out.println(-1);
                    return;
                }
                fuel += pq.poll();
                stops++;
            }
            fuel -= dist;
            pq.offer(stations[i][1]);
            prev = stations[i][0];
        }
        
        int dist = target - prev;
        while(fuel < dist) {
            if(pq.isEmpty()) {
                System.out.println(-1);
                return;
            }
            fuel += pq.poll();
            stops++;
        }
        
        System.out.println(stops);
    }
}
