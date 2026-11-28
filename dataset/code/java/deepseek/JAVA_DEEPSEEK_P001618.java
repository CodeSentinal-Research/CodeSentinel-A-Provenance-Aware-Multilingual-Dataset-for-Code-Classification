import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] arr = new long[n];
        long[] xorArr = new long[n];
        long xor = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLong();
            xor ^= arr[i];
            xorArr[i] = xor;
        }
        for (long val : xorArr) {
            System.out.println(val);
        }
    }
}
