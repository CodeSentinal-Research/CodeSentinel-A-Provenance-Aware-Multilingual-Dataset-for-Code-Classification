import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            minHeap.add(scanner.nextInt());
        }
        int m = scanner.nextInt();
        PriorityQueue<Integer> secondMinHeap = new PriorityQueue<>();
        for (int i = 0; i < m; i++) {
            secondMinHeap.add(scanner.nextInt());
        }
        PriorityQueue<Integer> mergedHeap = new PriorityQueue<>();
        while (!minHeap.isEmpty() || !secondMinHeap.isEmpty()) {
            if (!minHeap.isEmpty()) {
                mergedHeap.add(minHeap.poll());
            }
            if (!secondMinHeap.isEmpty()) {
                mergedHeap.add(secondMinHeap.poll());
            }
        }
        while (!mergedHeap.isEmpty()) {
            System.out.println(mergedHeap.poll());
        }
    }
}
