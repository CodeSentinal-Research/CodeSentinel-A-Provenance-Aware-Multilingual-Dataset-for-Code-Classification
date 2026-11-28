import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        long[] a = new long[n];
        long[] b = new long[n];

        long sumA = 0;
        long sumB = 0;

        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
            sumA += a[i];
        }

        for (int i = 0; i < n; i++) {
            b[i] = scanner.nextLong();
            sumB += b[i];
        }

        if (sumA < sumB) {
            System.out.println(-1);
        } else {
            System.out.println(sumA - sumB);
        }
    }
}
