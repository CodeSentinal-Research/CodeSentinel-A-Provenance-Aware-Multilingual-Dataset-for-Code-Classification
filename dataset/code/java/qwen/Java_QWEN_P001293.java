import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int num : nums) pq.offer(num);
        
        long MOD = 1000000007;
        for(int i=0; i<k; i++) {
            long min = pq.poll();
            min = (min + 1) % MOD;
            pq.offer((int)min);
        }
        
        long prod = 1;
        for(int num : pq) prod = (prod * num) % MOD;
        System.out.println(prod);
    }
}
