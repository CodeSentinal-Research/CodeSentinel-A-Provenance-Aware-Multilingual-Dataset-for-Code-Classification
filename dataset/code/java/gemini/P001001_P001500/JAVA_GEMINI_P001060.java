import java.util.PriorityQueue;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

            PriorityQueue<Integer> pq = new PriorityQueue<>();
            int idx = 0;
            for (int i = 0; i <= Math.min(k, n - 1); i++) pq.offer(arr[i]);

            for (int i = k + 1; i < n; i++) {
                arr[idx++] = pq.poll();
                pq.offer(arr[i]);
            }
            while (!pq.isEmpty()) {
                arr[idx++] = pq.poll();
            }

            for (int i = 0; i < n; i++) {
                System.out.print(arr[i] + (i == n - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}