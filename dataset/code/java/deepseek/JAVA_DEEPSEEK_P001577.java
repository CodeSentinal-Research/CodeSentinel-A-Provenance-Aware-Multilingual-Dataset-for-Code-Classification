import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(countStrictlyIncreasingWindows(arr, K));
    }

    private static int countStrictlyIncreasingWindows(int[] arr, int k) {
        int count = 0;
        for (int i = 0; i < arr.length - k + 1; i++) {
            if (isStrictlyIncreasing(arr, i, i + k)) {
                count++;
            }
        }
        return count;
    }

    private static boolean isStrictlyIncreasing(int[] arr, int start, int end) {
        for (int i = start; i < end; i++) {
            if (arr[i] >= arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
}
