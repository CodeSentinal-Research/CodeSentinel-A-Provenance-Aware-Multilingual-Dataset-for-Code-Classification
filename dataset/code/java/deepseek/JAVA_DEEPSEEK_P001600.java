import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }

        int Q = scanner.nextInt();
        for (int i = 0; i < Q; i++) {
            int L = scanner.nextInt();
            int R = scanner.nextInt();
            double sum = 0;
            for (int j = L; j <= R; j++) {
                sum += arr[j];
            }
            double avg = sum / (R - L + 1);
            System.out.println(String.format("%.2f", avg));
        }
    }
}
