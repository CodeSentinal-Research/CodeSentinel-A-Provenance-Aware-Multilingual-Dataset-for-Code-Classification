import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        for(int num : nums) {
            if(maxHeap.isEmpty() || num <= maxHeap.peek()) maxHeap.offer(num);
            else minHeap.offer(num);
            
            // Balance
            if(maxHeap.size() > minHeap.size() + 1) minHeap.offer(maxHeap.poll());
            else if(minHeap.size() > maxHeap.size()) maxHeap.offer(minHeap.poll());
            
            // Median
            if(maxHeap.size() > minHeap.size()) System.out.print(maxHeap.peek() + " ");
            else System.out.print((maxHeap.peek() + minHeap.peek()) / 2.0 + " ");
        }
    }
}
