import java.util.*;
public class Main {
    static int n, k;
    static int[] cookies;
    static int minUnfairness;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        cookies = new int[n];
        for(int i=0; i<n; i++) cookies[i] = sc.nextInt();
        
        minUnfairness = Integer.MAX_VALUE;
        int[] distribution = new int[k];
        backtrack(0, distribution);
        System.out.println(minUnfairness);
    }
    
    static void backtrack(int idx, int[] dist) {
        if(idx == n) {
            int maxVal = 0;
            for(int val : dist) maxVal = Math.max(maxVal, val);
            minUnfairness = Math.min(minUnfairness, maxVal);
            return;
        }
        
        // Pruning
        int maxVal = 0;
        for(int val : dist) maxVal = Math.max(maxVal, val);
        if(maxVal >= minUnfairness) return;
        
        for(int i=0; i<k; i++) {
            dist[i] += cookies[idx];
            backtrack(idx+1, dist);
            dist[i] -= cookies[idx];
            
            // Optimization: if dist[i] was 0, no need to try other empty buckets
            if(dist[i] == 0) break;
        }
    }
}
