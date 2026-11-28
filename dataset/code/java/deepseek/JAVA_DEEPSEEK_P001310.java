import java.util.Scanner;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            queue.add(scanner.nextInt());
        }
        int cost = 0;
        while (queue.size() > 1) {
            int a = queue.poll();
            int b = queue.poll();
            cost += a + b;
            queue.add(a + b);
        }
        System.out.println(cost);
    }
}
