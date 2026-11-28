import java.util.Scanner;
public class Solution {
    private static boolean isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
        return true;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int l = scanner.nextInt(), r = scanner.nextInt();
            StringBuilder sb = new StringBuilder();
            for (int i = l; i <= r; i++) {
                if (isPrime(i)) {
                    if (sb.length() > 0) sb.append(' ');
                    sb.append(i);
                }
            }
            System.out.println(sb.toString());
        }
    }
}