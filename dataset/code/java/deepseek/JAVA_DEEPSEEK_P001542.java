import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        double[] arr = new double[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextDouble();
        }
        scanner.close();
        double sum = 0;
        for (int i = 0; i < K; i++) {
            sum += arr[i];
        }
        double avg = sum / K;
        System.out.print(avg + " ");
        for (int i = K; i < N; i++) {
            sum -= arr[i - K];
            sum += arr[i];
            avg = sum / K;
            System.out.print(avg + " ");
        }
    }
}
