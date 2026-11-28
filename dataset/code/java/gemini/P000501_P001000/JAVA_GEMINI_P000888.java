import java.util.Scanner;

public class Solution {
    public static boolean isAutomorphic(long n) {
        long sq = n * n;
        return String.valueOf(sq).endsWith(String.valueOf(n));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long n = sc.nextLong();
            System.out.println(isAutomorphic(n) ? "YES" : "NO");
        }
        sc.close();
    }
}