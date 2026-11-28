import java.util.Scanner;

public class Main {
    static int[] arr;
    static boolean[] visited;
    static int minDiff = Integer.MAX_VALUE;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        arr = new int[n];
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        partition(0, 0, n);
        System.out.println(minDiff);
    }

    private static void partition(int start, int sum1, int n) {
        if (start == n) {
            int sum2 = 0;
            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    sum2 += arr[i];
                }
            }
            minDiff = Math.min(minDiff, Math.abs(sum1 - sum2));
            return;
        }
        visited[start] = true;
        partition(start + 1, sum1 + arr[start], n);
        visited[start] = false;
        partition(start + 1, sum1, n);
    }
}
