import java.util.*;
public class Solution {
    static long powerRec(long x, int n) {
        if (n == 0) return 1;
        long half = powerRec(x, n / 2);
        if (n % 2 == 0) return half * half;
        return half * half * x;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            long x = scanner.nextLong();
            int n = scanner.nextInt();
            System.out.println(powerRec(x, n));
        }
    }
}