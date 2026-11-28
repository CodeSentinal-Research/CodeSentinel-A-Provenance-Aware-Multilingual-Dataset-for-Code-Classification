import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        PriorityQueue<Integer> maxPq = new PriorityQueue<>(Collections.reverseOrder());
        for(int num : nums) {
            if(num % 2 != 0) maxPq.offer(num * 2);
            else maxPq.offer(num);
        }
        
        while(true) {
            int max = maxPq.peek();
            int min = maxPq.stream().mapToInt(Integer::intValue).min().getAsInt();
            if(max - min <= 1) break;
            
            maxPq.poll();
            if(max % 2 == 0) maxPq.offer(max / 2);
            else maxPq.offer(max * 2); // Should not happen as we doubled odds initially
        }
        
        int max = maxPq.stream().mapToInt(Integer::intValue).max().getAsInt();
        int min = maxPq.stream().mapToInt(Integer::intValue).min().getAsInt();
        System.out.println(max - min);
    }
}
