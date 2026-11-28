import java.util.Scanner;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int B = scanner.nextInt();
        int L = scanner.nextInt();
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 0; i < N; i++) {
            int height = scanner.nextInt();
            queue.add(height);
        }
        int bricks = B;
        while (!queue.isEmpty() && bricks > 0) {
            bricks -= queue.poll();
        }
        if (bricks < 0) {
            System.out.println(-1);
        } else {
            System.out.println(queue.peek());
        }
    }
}
