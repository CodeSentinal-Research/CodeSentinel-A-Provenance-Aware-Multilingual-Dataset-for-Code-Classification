import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        for (int i = 0; i < n; i++) {
            maxHeap.add(scanner.nextInt());
        }
        int m = scanner.nextInt();
        for (int i = 0; i < m; i++) {
            maxHeap.add(scanner.nextInt());
        }
        while (!maxHeap.isEmpty()) {
            System.out.println(maxHeap.poll());
        }
    }
}
