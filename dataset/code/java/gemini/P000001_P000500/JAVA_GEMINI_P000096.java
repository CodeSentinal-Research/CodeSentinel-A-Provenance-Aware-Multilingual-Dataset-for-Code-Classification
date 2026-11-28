import java.util.Scanner;

public class Solution {
    public static boolean isSpyNumber(int n) {
        n = Math.abs(n);
        int sum = 0;
        int prod = 1;
        while (n > 0) {
            int d = n % 10;
            sum += d;
            prod *= d;
            n /= 10;
        }
        return sum == prod;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(isSpyNumber(n) ? "YES" : "NO");
        }
        sc.close();
    }
}