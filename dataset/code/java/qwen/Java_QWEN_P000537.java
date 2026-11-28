import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        int k = sc.nextInt();
        
        Deque<Integer> deque = new ArrayDeque<>();
        int[] res = new int[n - k + 1];
        for(int i=0; i<n; i++) {
            while(!deque.isEmpty() && deque.peekFirst() <= i - k) deque.pollFirst();
            while(!deque.isEmpty() && nums[deque.peekLast()] <= nums[i]) deque.pollLast();
            deque.offerLast(i);
            if(i >= k - 1) res[i - k + 1] = nums[deque.peekFirst()];
        }
        for(int x : res) System.out.print(x + " ");
    }
}
