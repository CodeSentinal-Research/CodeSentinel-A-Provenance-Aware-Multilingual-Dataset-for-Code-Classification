import java.util.Scanner;

public class Main {
    static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    static long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] nums = new long[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextLong();
        }
        long result = nums[0];
        for (int i = 1; i < n; i++) {
            result = lcm(result, nums[i]);
        }
        System.out.println(result % (long)(1e9 + 7));
    }
}
