import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Deque<Integer> deque = new ArrayDeque<>();
        long sum = 0;
        int minLen = Integer.MAX_VALUE;
        for(int right=0; right<n; right++) {
            sum += nums[right];
            while(sum >= k) {
                minLen = Math.min(minLen, right - deque.isEmpty() ? 0 : deque.peekFirst() + 1); // Simplified logic
                // Correct sliding window for shortest subarray with sum >= k (positive numbers only)
                // If negative numbers allowed, need monotonic queue on prefix sums
            }
        }
        // Standard solution for positive numbers:
        int left = 0;
        sum = 0;
        minLen = Integer.MAX_VALUE;
        for(int right=0; right<n; right++) {
            sum += nums[right];
            while(sum >= k) {
                minLen = Math.min(minLen, right - left + 1);
                sum -= nums[left++];
            }
        }
        System.out.println(minLen == Integer.MAX_VALUE ? -1 : minLen);
    }
}
