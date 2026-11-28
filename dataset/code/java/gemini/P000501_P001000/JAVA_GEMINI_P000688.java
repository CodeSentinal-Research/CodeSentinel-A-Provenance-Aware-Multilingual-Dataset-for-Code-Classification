import java.util.*;
public class Solution {
    static int countDigits(long n) {
        if (n < 10) return 1;
        return 1 + countDigits(n / 10);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            System.out.println(countDigits(Math.abs(scanner.nextLong())));
        }
    }
}