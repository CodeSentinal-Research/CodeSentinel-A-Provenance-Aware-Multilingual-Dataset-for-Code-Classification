import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextDouble()) {
            double x1 = sc.nextDouble(), y1 = sc.nextDouble();
            double x2 = sc.nextDouble(), y2 = sc.nextDouble();
            System.out.printf("%.6f %.6f\n", (x1 + x2) / 2.0, (y1 + y2) / 2.0);
        }
        sc.close();
    }
}