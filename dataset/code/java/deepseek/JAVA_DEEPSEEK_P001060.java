import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static class Pair implements Comparable<Pair> {
        int element;
        int index;

        public Pair(int element, int index) {
            this.element = element;
            this.index = index;
        }

        @Override
        public int compareTo(Pair o) {
            return this.element - o.element;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        PriorityQueue<Pair> queue = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            int element = scanner.nextInt();
            queue.add(new Pair(element, i));
        }
        while (!queue.isEmpty()) {
            Pair pair = queue.poll();
            System.out.print(pair.element + " ");
            if (pair.index < n - k) {
                Pair next = new Pair(queue.peek().element, queue.peek().index + k);
                queue.add(next);
            }
        }
    }
}
