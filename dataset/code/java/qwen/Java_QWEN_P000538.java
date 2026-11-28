import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        int k = sc.nextInt();
        
        long[] prefix = new long[n + 1];
        for(int i=0; i<n; i++) prefix[i+1] = prefix[i] + nums[i];
        
        Deque<Integer> deque = new ArrayDeque<>();
        int minLen = Integer.MAX_VALUE;
        for(int i=0; i<=n; i++) {
            while(!deque.isEmpty() && prefix[deque.peekLast()] >= prefix[i]) deque.pollLast();
            deque.offerLast(i);
            while(!deque.isEmpty() && prefix[i] - prefix[deque.peekFirst()] >= k) {
                minLen = Math.min(minLen, i - deque.pollFirst());
            }
        }
        System.out.println(minLen == Integer.MAX_VALUE ? -1 : minLen);
    }
}
