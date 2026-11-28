import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int K = scanner.nextInt();
        int[] arr1 = new int[N];
        int[] arr2 = new int[M];
        for (int i = 0; i < N; i++) {
            arr1[i] = scanner.nextInt();
        }
        for (int i = 0; i < M; i++) {
            arr2[i] = scanner.nextInt();
        }
        System.out.println(maxNumber(arr1, arr2, K));
    }

    public static String maxNumber(int[] arr1, int[] arr2, int K) {
        if (K == 0) {
            return "";
        }
        if (arr1.length == 0 || arr2.length == 0) {
            return "";
        }
        if (arr1.length + arr2.length > K) {
            return maxNumber(Arrays.copyOfRange(arr1, 1, arr1.length), arr2, K - 1);
        }
        if (arr1[0] > arr2[0]) {
            return arr1[0] + maxNumber(Arrays.copyOfRange(arr1, 1, arr1.length), arr2, K - 1);
        }
        return arr2[0] + maxNumber(arr1, Arrays.copyOfRange(arr2, 1, arr2.length), K - 1);
    }
}
