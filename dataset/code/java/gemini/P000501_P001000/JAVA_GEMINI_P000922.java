import java.util.Scanner;

public class Solution {
    public static long sumDigitsUpTo(long n) {
        if (n <= 0) return 0;
        String s = String.valueOf(n);
        int d = s.length();
        if (d == 1) return n * (n + 1) / 2;
        long first = s.charAt(0) - '0';
        long rem = Long.parseLong(s.substring(1).isEmpty() ? "0" : s.substring(1));
        long p = (long) Math.pow(10, d - 1);

        long ans = first * 45 * (d - 1) * (p / 10);
        ans += (first * (first - 1) / 2) * p;
        ans += first * (rem + 1);
        ans += sumDigitsUpTo(rem);
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long l = sc.nextLong();
            long r = sc.nextLong();
            System.out.println(sumDigitsUpTo(r) - sumDigitsUpTo(l - 1));
        }
        sc.close();
    }
}