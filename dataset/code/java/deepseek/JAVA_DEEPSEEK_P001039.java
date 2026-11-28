import java.util.Scanner;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] heights = new int[n];
        for (int i = 0; i < n; i++) {
            heights[i] = scanner.nextInt();
        }
        int bricks = scanner.nextInt();
        int ladders = scanner.nextInt();

        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            queue.add(heights[i]);
        }

        while (!queue.isEmpty() && bricks > 0) {
            bricks--;
            queue.poll();
        }

        while (!queue.isEmpty() && ladders > 0) {
            ladders--;
            queue.poll();
        }

        if (!queue.isEmpty()) {
            System.out.println(queue.peek());
        } else {
            System.out.println(-1);
        }
    }
}
