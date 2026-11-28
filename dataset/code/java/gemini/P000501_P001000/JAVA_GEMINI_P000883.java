import java.util.Scanner;

public class Solution {
    public static int productOfDigits(int n) {
        n = Math.abs(n);
        if (n == 0) return 0;
        int prod = 1;
        while (n > 0) {
            prod *= (n % 10);
            n /= 10;
        }
        return prod;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(productOfDigits(n));
        }
        sc.close();
    }
}