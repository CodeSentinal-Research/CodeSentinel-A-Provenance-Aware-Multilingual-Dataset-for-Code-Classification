import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        while (n-- > 0) {
            maxHeap.add(scanner.nextInt());
        }
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(maxHeap);
        while (!minHeap.isEmpty()) {
            System.out.println(minHeap.poll());
        }
    }
}
