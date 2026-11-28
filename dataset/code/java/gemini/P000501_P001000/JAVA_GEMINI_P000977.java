import java.util.Scanner;

public class Solution {
    public static boolean areCollinear(long x1, long y1, long x2, long y2, long x3, long y3) {
        return (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) == 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long x1 = sc.nextLong(), y1 = sc.nextLong();
            long x2 = sc.nextLong(), y2 = sc.nextLong();
            long x3 = sc.nextLong(), y3 = sc.nextLong();
            System.out.println(areCollinear(x1, y1, x2, y2, x3, y3) ? "YES" : "NO");
        }
        sc.close();
    }
}