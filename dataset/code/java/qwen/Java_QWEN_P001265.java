import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] speed = new int[n];
        int[] eff = new int[n];
        for(int i=0; i<n; i++) speed[i] = sc.nextInt();
        for(int i=0; i<n; i++) eff[i] = sc.nextInt();
        
        int[][] engineers = new int[n][2];
        for(int i=0; i<n; i++) {
            engineers[i][0] = eff[i];
            engineers[i][1] = speed[i];
        }
        Arrays.sort(engineers, (a, b) -> b[0] - a[0]);
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        long sumSpeed = 0;
        long res = 0;
        for(int[] e : engineers) {
            pq.offer(e[1]);
            sumSpeed += e[1];
            if(pq.size() > k) sumSpeed -= pq.poll();
            res = Math.max(res, sumSpeed * e[0]);
        }
        System.out.println(res % 1000000007);
    }
}
