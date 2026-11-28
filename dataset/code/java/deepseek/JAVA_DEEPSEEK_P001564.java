import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        List<Integer> nums = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            nums.add(scanner.nextInt());
        }
        scanner.close();
        calculateMedians(nums, K, N);
    }

    private static void calculateMedians(List<Integer> nums, int k, int n) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            maxHeap.add(nums.get(i));
            minHeap.add(maxHeap.poll());
            if (maxHeap.size() > k) {
                minHeap.add(maxHeap.poll());
            }
            if (maxHeap.size() < k) {
                System.out.println("Invalid size");
                return;
            }
            if (maxHeap.size() == k) {
                double median;
                if (k % 2 == 0) {
                    median = (minHeap.peek() + maxHeap.peek()) / 2.0;
                } else {
                    median = maxHeap.peek();
                }
                System.out.println(median);
            }
        }
    }
}
