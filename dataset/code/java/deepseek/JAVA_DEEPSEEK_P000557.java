import java.util.Scanner;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int target = scanner.nextInt();
        System.out.println(minInstructions(target));
    }

    private static int minInstructions(int target) {
        PriorityQueue<int[]> queue = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        queue.offer(new int[]{0, 1, 0}); // position, speed, instructions

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            if (curr[0] == target) {
                return curr[2];
            }
            if (curr[1] > 0) {
                queue.offer(new int[]{curr[0] + curr[1], curr[1] * 2, curr[2] + 1});
            }
            if (curr[1] < 0) {
                queue.offer(new int[]{curr[0] + curr[1], curr[1] * 2, curr[2] + 1});
            }
            queue.offer(new int[]{curr[0], -curr[1], curr[2] + 1});
        }

        return -1;
    }
}
