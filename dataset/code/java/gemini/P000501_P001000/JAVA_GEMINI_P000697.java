import java.util.*;
public class Solution {
    static boolean isPrimeRec(long n, long d) {
        if (n <= 1) return false;
        if (d * d > n) return true;
        if (n % d == 0) return false;
        return isPrimeRec(n, d + 1);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            System.out.println(isPrimeRec(scanner.nextLong(), 2) ? "true" : "false");
        }
    }
}