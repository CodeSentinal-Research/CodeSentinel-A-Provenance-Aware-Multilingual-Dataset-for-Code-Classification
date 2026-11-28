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
        System.out.println(maxRepeating(arr, N, K));
    }

    public static int maxRepeating(int[] arr, int N, int K) {
        int[] count = new int[K];
        for (int i = 0; i < N; i++) {
            count[arr[i]]++;
        }
        int max = count[0];
        for (int i = 1; i < K; i++) {
            if (count[i] > max) {
                max = count[i];
            }
       }
        return max;
    }
}
