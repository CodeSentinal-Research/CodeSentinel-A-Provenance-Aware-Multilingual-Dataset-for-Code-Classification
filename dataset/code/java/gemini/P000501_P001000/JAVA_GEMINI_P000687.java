import java.util.*;
public class Solution {
    static long sumDigits(long n) {
        if (n == 0) return 0;
        return (n % 10) + sumDigits(n / 10);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            System.out.println(sumDigits(Math.abs(scanner.nextLong())));
        }
    }
}