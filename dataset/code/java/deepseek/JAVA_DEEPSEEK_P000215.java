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
        double maxAverage = Double.MIN_VALUE;
        for (int i = 0; i <= N - K; i++) {
            double sum = 0;
            for (int j = 0; j < K; j++) {
                sum += arr[i + j];
            }
            double average = sum / K;
            maxAverage = Math.max(maxAverage, average);
       }
        System.out.println(maxAverage);
    }
}
