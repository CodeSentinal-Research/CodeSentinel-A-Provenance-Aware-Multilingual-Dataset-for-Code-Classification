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
        long count = 0;
        for (int i = 0; i < N - K + 1; i++) {
            if (arr[i] > 0 && arr[i + K - 1] > 0) {
                count++;
            }
        }
        System.out.println(count);
    }
}
