import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(longestBitonicSubsequence(arr, n));
    }

    private static int longestBitonicSubsequence(int[] arr, int n) {
        int[] lis = new int[n];
        int[] lds = new int[n];
        lis[0] = 1;
        lds[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            lis[i] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
                }
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            lds[i] = 1;
            for (int j = n - 1; j > i; j--) {
                if (arr[i] > arr[j] && lds[i] < lds[j] + 1) {
                    lds[i] = lds[j] + 1;
                }
            }
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (lis[i] + lds[i] - 1 > max) {
                max = lis[i] + lds[i] - 1;
            }
        }
        return max;
    }
}
