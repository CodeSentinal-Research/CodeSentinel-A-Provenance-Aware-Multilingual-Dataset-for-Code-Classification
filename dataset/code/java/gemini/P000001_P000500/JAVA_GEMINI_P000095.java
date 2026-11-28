import java.util.Scanner;

public class Solution {
    public static boolean isNeonNumber(int n) {
        if (n < 0) return false;
        long sq = (long) n * n;
        long sum = 0;
        while (sq > 0) {
            sum += sq % 10;
            sq /= 10;
        }
        return sum == n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(isNeonNumber(n) ? "YES" : "NO");
        }
        sc.close();
    }
}