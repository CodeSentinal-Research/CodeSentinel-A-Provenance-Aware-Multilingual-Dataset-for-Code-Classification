import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] people = new int[n][2];
        for (int i = 0; i < n; i++) {
            people[i] = new int[]{scanner.nextInt(), scanner.nextInt()};
        }
        Arrays.sort(people, (a, b) -> a[0] - b[0]);
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int[] person : people) {
            if (!queue.isEmpty() && queue.peek() >= person[1]) {
                queue.poll();
            }
            queue.offer(person[1]);
        }
        while (!queue.isEmpty()) {
            queue.poll();
        }
        for (int[] person : people) {
            while (queue.peek() != null && queue.peek() < person[1]) {
                queue.poll();
            }
            System.out.println(person[0] + " " + (queue.peek() == null ? "0" : queue.poll()));
        }
    }
}
