import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextDouble()) {
            double a = scanner.nextDouble(), b = scanner.nextDouble(), c = scanner.nextDouble();
            double d = b * b - 4 * a * c;
            if (d > 0) {
                double r1 = (-b + Math.sqrt(d)) / (2 * a);
                double r2 = (-b - Math.sqrt(d)) / (2 * a);
                System.out.println(r1 + " " + r2);
            } else if (d == 0) {
                System.out.println(-b / (2 * a));
            } else {
                System.out.println("Complex Roots");
            }
        }
    }
}