import java.util.Scanner;

public class Solution {
    private static long[] extGcd(long a, long b) {
        if (b == 0) return new long[]{a, 1, 0};
        long[] res = extGcd(b, a % b);
        long g = res[0], x1 = res[1], y1 = res[2];
        return new long[]{g, y1, x1 - (a / b) * y1};
    }

    public static long crt(long[] num, long[] rem) {
        long prod = 1;
        for (long n : num) prod *= n;
        long result = 0;
        for (int i = 0; i < num.length; i++) {
            long pp = prod / num[i];
            long[] resGcd = extGcd(pp, num[i]);
            long inv = (resGcd[1] % num[i] + num[i]) % num[i];
            result = (result + rem[i] * pp % prod * inv) % prod;
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int k = sc.nextInt();
            long[] num = new long[k];
            for (int i = 0; i < k; i++) num[i] = sc.nextLong();
            long[] rem = new long[k];
            for (int i = 0; i < k; i++) rem[i] = sc.nextLong();
            System.out.println(crt(num, rem));
        }
        sc.close();
    }
}