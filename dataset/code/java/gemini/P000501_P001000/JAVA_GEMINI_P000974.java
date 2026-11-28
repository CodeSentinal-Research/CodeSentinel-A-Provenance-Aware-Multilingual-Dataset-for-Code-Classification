import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextDouble()) {
            double x1 = sc.nextDouble(), y1 = sc.nextDouble();
            double x2 = sc.nextDouble(), y2 = sc.nextDouble();
            double dist = Math.hypot(x2 - x1, y2 - y1);
            System.out.printf("%.6f\n", dist);
        }
        sc.close();
    }
}