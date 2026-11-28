import java.util.Scanner;

public class Solution {
    public static String triangleType(long x1, long y1, long x2, long y2, long x3, long y3) {
        if ((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) == 0) {
            return "Not a Triangle";
        }
        long d1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        long d2 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
        long d3 = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);

        if (d1 == d2 && d2 == d3) return "Equilateral";
        if (d1 == d2 || d2 == d3 || d3 == d1) return "Isosceles";
        return "Scalene";
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextLong()) {
            long x1 = sc.nextLong(), y1 = sc.nextLong();
            long x2 = sc.nextLong(), y2 = sc.nextLong();
            long x3 = sc.nextLong(), y3 = sc.nextLong();
            System.out.println(triangleType(x1, y1, x2, y2, x3, y3));
        }
        sc.close();
    }
}