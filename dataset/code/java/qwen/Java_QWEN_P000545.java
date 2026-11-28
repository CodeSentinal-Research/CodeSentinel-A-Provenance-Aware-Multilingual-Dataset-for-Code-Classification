import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        int k = sc.nextInt();
        
        Deque<Integer> deque = new ArrayDeque<>();
        long[] dp = new long[n];
        dp[0] = nums[0];
        deque.offer(0);
        
        for(int i=1; i<n; i++) {
            while(!deque.isEmpty() && deque.peekFirst() < i - k) deque.pollFirst();
            dp[i] = dp[deque.peekFirst()] + nums[i];
            while(!deque.isEmpty() && dp[deque.peekLast()] <= dp[i]) deque.pollLast();
            deque.offerLast(i);
        }
        System.out.println(dp[n-1]);
    }
}
