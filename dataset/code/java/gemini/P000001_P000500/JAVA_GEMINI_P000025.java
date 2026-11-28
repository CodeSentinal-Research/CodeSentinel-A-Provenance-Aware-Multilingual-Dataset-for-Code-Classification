import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            long n = scanner.nextLong();
            long sign = n < 0 ? -1 : 1;
            long num = Math.abs(n);
            long rev = 0;
            while (num > 0) {
                rev = rev * 10 + (num % 10);
                num /= 10;
            }
            System.out.println(sign * rev);
        }
    }
}