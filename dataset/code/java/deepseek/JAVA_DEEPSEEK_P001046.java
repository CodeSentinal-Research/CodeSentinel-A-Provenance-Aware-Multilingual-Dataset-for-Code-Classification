import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        long count = countNodesGreaterThanRoot(arr, n);
        System.out.println(count);
    }

    private static long countNodesGreaterThanRoot(int[] arr, int n) {
        long count = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[(int) (i - 1) / 2]) {
                count++;
            }
        }
        return count;
    }
}
