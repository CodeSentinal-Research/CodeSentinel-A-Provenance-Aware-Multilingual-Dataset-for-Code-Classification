import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] prefixSum = new long[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            long num = scanner.nextLong();
            sum += num;
            prefixSum[i] = sum;
        }
        for (long val : prefixSum) {
            System.out.println(val);
        }
    }
}
