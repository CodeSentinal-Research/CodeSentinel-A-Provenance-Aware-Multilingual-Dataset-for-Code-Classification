import java.util.Scanner;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int i = 0; i < N; i++) {
            int score = scanner.nextInt();
            maxHeap.offer(score);
            minHeap.offer(score);
        }
        while (K-- > 1) {
            int maxScore = maxHeap.poll();
            int minScore = minHeap.poll();
            maxHeap.offer(maxScore - 1);
            minHeap.offer(minScore + 1);
        }
        int minDifference = maxHeap.peek() - minHeap.peek();
        System.out.println(minDifference);
    }
}
