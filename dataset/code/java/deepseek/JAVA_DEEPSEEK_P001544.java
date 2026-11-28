import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int X = scanner.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        long count = 0;
        for (int i = 0; i < N - K + 1; i++) {
            int sum = 0;
            for (int j = i; j < i + K; j++) {
                sum += arr[j];
            }
            if (sum > X) {
                count++;
            }
        }
        System.out.println(count);
    }
}
