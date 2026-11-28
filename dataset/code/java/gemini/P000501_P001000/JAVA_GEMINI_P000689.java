import java.util.*;
public class Solution {
    static long prodDigits(long n) {
        if (n < 10) return n;
        return (n % 10) * prodDigits(n / 10);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            System.out.println(prodDigits(Math.abs(scanner.nextLong())));
        }
    }
}