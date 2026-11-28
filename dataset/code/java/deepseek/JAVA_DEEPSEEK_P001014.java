import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static class Pair implements Comparable<Pair> {
        int arr[];
        int index;
        int element;

        public Pair(int[] arr, int index) {
            this.arr = arr;
            this.index = index;
            this.element = arr[index];
        }

        @Override
        public int compareTo(Pair o) {
            return this.element - o.element;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int K = scanner.nextInt();
        PriorityQueue<Pair> queue = new PriorityQueue<>();
        for (int i = 0; i < K; i++) {
            int N = scanner.nextInt();
            int[] arr = new int[N];
            for (int j = 0; j < N; j++) {
                arr[j] = scanner.nextInt();
            }
            queue.add(new Pair(arr, 0));
        }

        while (!queue.isEmpty()) {
            Pair pair = queue.poll();
            System.out.print(pair.element + " ");
            if (pair.index + 1 < pair.arr.length) {
                pair.index++;
                pair.element = pair.arr[pair.index];
                queue.add(pair);
            }
        }
    }
}
