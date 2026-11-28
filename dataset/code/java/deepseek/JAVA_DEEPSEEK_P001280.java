import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        long n = scanner.nextLong();
        long[] arr = new long[m];
        long[] prefix = new long[m];
        for (int i = 0; i < m; i++) {
            arr[i] = scanner.nextLong();
        }
        prefix[0] = arr[0];
        for (int i = 1; i < m; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        long ans = 0;
        for (int i = 0; i < m; i++) {
            if (prefix[i] >= n) {
                ans += prefix[i] - n;
            }
        }
        System.out.println(ans);
    }
}
