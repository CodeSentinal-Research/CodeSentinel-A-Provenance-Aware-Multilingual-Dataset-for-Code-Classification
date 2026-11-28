import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            maxHeap.add(num);
            minHeap.add(num);
        }
        while (n % 2 == 0) {
            int max = maxHeap.poll();
            int min = minHeap.poll();
            maxHeap.add(max / 2);
            minHeap.add(min / 2);
        }
        int maxDeviation = maxHeap.peek() - minHeap.peek();
        System.out.println(maxDeviation);
    }
}
