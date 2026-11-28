import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] arr = new long[n];
        long prefixSum = 0;
        long count = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLong();
            prefixSum += arr[i];
            if (prefixSum < 0) {
                count += (n - i);
            }
        }
        System.out.println(count);
    }
}
