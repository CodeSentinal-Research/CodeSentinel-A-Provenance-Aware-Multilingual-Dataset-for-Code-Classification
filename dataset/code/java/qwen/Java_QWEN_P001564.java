import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        for(int i=0; i<k; i++) {
            addNum(nums[i], maxHeap, minHeap);
        }
        printMedian(maxHeap, minHeap);
        
        for(int i=k; i<n; i++) {
            removeNum(nums[i-k], maxHeap, minHeap);
            addNum(nums[i], maxHeap, minHeap);
            printMedian(maxHeap, minHeap);
        }
    }
    
    static void addNum(int num, PriorityQueue<Integer> maxHeap, PriorityQueue<Integer> minHeap) {
        maxHeap.offer(num);
        minHeap.offer(maxHeap.poll());
        if(maxHeap.size() < minHeap.size()) {
            maxHeap.offer(minHeap.poll());
        }
    }
    
    static void removeNum(int num, PriorityQueue<Integer> maxHeap, PriorityQueue<Integer> minHeap) {
        if(num <= maxHeap.peek()) {
            maxHeap.remove(num);
        } else {
            minHeap.remove(num);
        }
        if(maxHeap.size() < minHeap.size()) {
            maxHeap.offer(minHeap.poll());
        } else if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.offer(maxHeap.poll());
        }
    }
    
    static void printMedian(PriorityQueue<Integer> maxHeap, PriorityQueue<Integer> minHeap) {
        if(maxHeap.size() > minHeap.size()) {
            System.out.printf("%.1f ", (double)maxHeap.peek());
        } else {
            System.out.printf("%.1f ", (maxHeap.peek() + minHeap.peek()) / 2.0);
        }
    }
}
