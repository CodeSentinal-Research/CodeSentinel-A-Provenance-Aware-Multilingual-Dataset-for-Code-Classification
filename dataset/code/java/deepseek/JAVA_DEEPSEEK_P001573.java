import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int D = scanner.nextInt();
        long[] arr = new long[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextLong();
        }
        scanner.close();
        long count = 0;
        long sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
            if (i >= K - 1) {
                if (sum % D == 0) {
                    count++;
                }
                sum -= arr[i - (K - 1)];
            }
        }
        System.out.println(count);
    }
}
