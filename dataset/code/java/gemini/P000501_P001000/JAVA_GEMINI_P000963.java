import java.util.Scanner;

public class Solution {
    public static long countNonPurchasable(long a, long b) {
        return (a - 1) * (b - 1) / 2;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            System.out.println(countNonPurchasable(a, b));
        }
        sc.close();
    }
}