import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] dims = new int[n];
        for (int i = 0; i < n; i++) {
            dims[i] = scanner.nextInt();
        }
        System.out.println(minScalarMultiplications(dims, 1, n - 1));
    }

    private static int minScalarMultiplications(int[] dims, int i, int j) {
        if (i == j) {
            return 0;
        }
        int min = Integer.MAX_VALUE;
        for (int k = i; k < j; k++) {
            int count = minScalarMultiplications(dims, i, k) +
                    minScalarMultiplications(dims, k + 1, j) +
                    dims[i - 1] * dims[k] * dims[j];
            if (count < min) {
                min = count;
            }
        }
        return min;
    }
}
