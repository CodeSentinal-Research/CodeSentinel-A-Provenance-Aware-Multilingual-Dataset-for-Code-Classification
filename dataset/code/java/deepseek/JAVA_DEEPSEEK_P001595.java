import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }

        int L = scanner.nextInt();
        int R = scanner.nextInt();

        long sum = 0;
        for (int i = L; i <= R; i++) {
            sum += arr[i];
        }

        System.out.println(sum);
    }
}
