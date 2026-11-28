import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int M = scanner.nextInt();
        int N = scanner.nextInt();
        int K = scanner.nextInt();

        int[] array1 = new int[M];
        for (int i = 0; i < M; i++) {
            array1[i] = scanner.nextInt();
        }

        int[] array2 = new int[N];
        for (int i = 0; i < N; i++) {
            array2[i] = scanner.nextInt();
        }

        System.out.println(findKth(array1, array2, K));
    }

    private static int findKth(int[] array1, int[] array2, int K) {
        int m = array1.length;
        int n = array2.length;
        if (m > n) {
            return findKth(array2, array1, K);
        }
        if (m == 0) {
            return array2[K - 1];
        }
        if (K == 1) {
            return Math.min(array1[0], array2[0]);
        }

        int i = Math.min(K / 2, m);
        int j = Math.min(K / 2, n);

        if (array1[i - 1] > array2[j - 1]) {
            return findKth(array1, java.util.Arrays.copyOfRange(array2, j, n), K - j);
        } else {
            return findKth(java.util.Arrays.copyOfRange(array1, i, m), array2, K - i);
        }
    }
}
