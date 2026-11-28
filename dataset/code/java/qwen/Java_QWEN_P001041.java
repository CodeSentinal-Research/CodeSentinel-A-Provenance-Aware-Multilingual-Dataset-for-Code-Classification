import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] quality = new int[n];
        int[] wage = new int[n];
        for(int i=0; i<n; i++) quality[i] = sc.nextInt();
        for(int i=0; i<n; i++) wage[i] = sc.nextInt();
        
        double[][] workers = new double[n][2];
        for(int i=0; i<n; i++) {
            workers[i][0] = (double)wage[i] / quality[i];
            workers[i][1] = quality[i];
        }
        Arrays.sort(workers, (a, b) -> Double.compare(a[0], b[0]));
        
        PriorityQueue<Double> pq = new PriorityQueue<>(Collections.reverseOrder());
        double sumQ = 0;
        double res = Double.MAX_VALUE;
        for(double[] w : workers) {
            pq.offer(w[1]);
            sumQ += w[1];
            if(pq.size() > k) sumQ -= pq.poll();
            if(pq.size() == k) res = Math.min(res, sumQ * w[0]);
        }
        System.out.printf("%.5f
", res);
    }
}
