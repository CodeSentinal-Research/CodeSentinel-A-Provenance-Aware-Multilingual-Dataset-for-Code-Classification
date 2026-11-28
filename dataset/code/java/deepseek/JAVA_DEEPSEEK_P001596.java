import java.util.*;

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
            System.out.println(countPositives(arr, L, R));
        }
    }

    private static int countPositives(int[] arr, int L, int R) {
        int count = 0;
        for (int i = L; i <= R; i++) {
            if (arr[i] > 0) {
                count++;
            }
        }
        return count;
    }
}
