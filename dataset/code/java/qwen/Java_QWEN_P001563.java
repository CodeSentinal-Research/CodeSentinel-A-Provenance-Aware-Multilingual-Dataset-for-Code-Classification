import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int limit = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        Deque<Integer> maxDeque = new ArrayDeque<>();
        Deque<Integer> minDeque = new ArrayDeque<>();
        int left = 0;
        int maxLen = 0;
        
        for(int right=0; right<n; right++) {
            while(!maxDeque.isEmpty() && nums[maxDeque.peekLast()] <= nums[right]) maxDeque.pollLast();
            maxDeque.offerLast(right);
            
            while(!minDeque.isEmpty() && nums[minDeque.peekLast()] >= nums[right]) minDeque.pollLast();
            minDeque.offerLast(right);
            
            while(nums[maxDeque.peekFirst()] - nums[minDeque.peekFirst()] > limit) {
                left++;
                if(maxDeque.peekFirst() < left) maxDeque.pollFirst();
                if(minDeque.peekFirst() < left) minDeque.pollFirst();
            }
            maxLen = Math.max(maxLen, right - left + 1);
        }
        System.out.println(maxLen);
    }
}
