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

        long sum = 0;
        for (int i = 0; i < N - K + 1; i++) {
            int min = arr[i], max = arr[i];
            for (int j = i; j < i + K; j++) {
                min = Math.min(min, arr[j]);
                max = Math.max(max, arr[j]);
            }
            sum += max - min;
        }

        System.out.println(sum);
    }
}
