import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[][] people = new int[N][2];
        for (int i = 0; i < N; i++) {
            people[i] = new int[]{scanner.nextInt(), scanner.nextInt()};
        }
        Arrays.sort(people, (a, b) -> a[0] - b[0]);
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int[] person : people) {
            if (!queue.isEmpty() && queue.peek() <= person[0]) {
                queue.poll();
            }
            queue.offer(person[1]);
        }
        while (!queue.isEmpty()) {
            queue.poll();
        }
    }
}
