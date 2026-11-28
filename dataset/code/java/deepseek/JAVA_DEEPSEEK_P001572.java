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
        System.out.println(countWindows(arr, K));
    }

    private static int countWindows(int[] arr, int k) {
        int count = 0;
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }
        if (windowSum % 2 == 0) {
            count++;
        }
        for (int i = k; i < arr.length; i++) {
            windowSum -= arr[i - k];
            windowSum += arr[i];
            if (windowSum % 2 == 0) {
                count++;
            }
        }
        return count;
    }
}
