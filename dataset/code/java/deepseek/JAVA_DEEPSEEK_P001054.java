import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static class Pair implements Comparable<Pair> {
        int sum, idx1, idx2;

        public Pair(int sum, int idx1, int idx2) {
            this.sum = sum;
            this.idx1 = idx1;
            this.idx2 = idx2;
        }

        @Override
        public int compareTo(Pair o) {
            return o.sum - this.sum;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] arr1 = new int[N];
        int[] arr2 = new int[N];
        for (int i = 0; i < N; i++) {
            arr1[i] = sc.nextInt();
        }
        for (int i = 0; i < N; i++) {
            arr2[i] = sc.nextInt();
        }
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                pq.add(new Pair(arr1[i] + arr2[j], i, j));
                if (pq.size() > K) {
                    pq.poll();
                }
            }
        }
        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            System.out.println(p.sum);
        }
    }
}
