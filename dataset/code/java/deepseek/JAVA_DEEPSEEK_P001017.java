import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        PriorityQueue<Long> queue = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            queue.add(scanner.nextLong());
        }
        long totalCost = 0;
        while (queue.size() > 1) {
            long cost = queue.poll() + queue.poll();
            totalCost += cost;
            queue.add(cost);
        }
        System.out.println(totalCost);
    }
}
