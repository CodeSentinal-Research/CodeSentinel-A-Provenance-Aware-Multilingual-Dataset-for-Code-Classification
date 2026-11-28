import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        for (int i = 0; i < n; i++) {
            maxHeap.offer(scanner.nextInt());
       }
        for (int i = 0; i < k - 1; i++) {
            maxHeap.poll();
        }
        System.out.println(maxHeap.peek());
    }
}
