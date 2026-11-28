import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int p = scanner.nextInt();
        int b = scanner.nextInt();
        int[] banned = new int[b];
        for (int i = 0; i < b; i++) {
            banned[i] = scanner.nextInt();
        }
        int k = scanner.nextInt();

        int[] result = minReverseOperations(n, p, banned, k);
        for (int i = 0; i < n; i++) {
            System.out.println(result[i]);
        }
    }

    public static int[] minReverseOperations(int n, int p, int[] banned, int k) {
        int[] result = new int[n];
        Arrays.fill(result, -1);
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(p);
        result[p] = 0;
        while (!queue.isEmpty()) {
            int current = queue.poll();
            for (int i = 1; i < k && current + i < n; i++) {
                if (Arrays.binarySearch(banned, 0, banned.length, current + i) < 0 && result[current + i] == -1) {
                    result[current + i] = result[current] + 1;
                    queue.offer(current + i);
                }
            }
            for (int i = 1; i < k && current - i >= 0; i++) {
                if (Arrays.binarySearch(banned, 0, banned.length, current - i) < 0 && result[current - i] == -1) {
                    result[current - i] = result[current] + 1;
                    queue.offer(current - i);
                }
            }
        }
        return result;
    }
}
