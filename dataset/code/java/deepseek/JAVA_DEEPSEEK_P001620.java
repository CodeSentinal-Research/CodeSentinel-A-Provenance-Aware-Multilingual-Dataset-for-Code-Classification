import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        int q = scanner.nextInt();
        for (int i = 0; i < q; i++) {
            int l = scanner.nextInt();
            int r = scanner.nextInt();
            System.out.println(prefixSum(arr, l, r));
        }
    }

    private static int prefixSum(int[] arr, int l, int r) {
        if (l == 1) {
            return arr[r];
        } else {
            return arr[r] - arr[l - 1];
        }
    }
}
