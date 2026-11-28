import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextDouble()) {
            double a = scanner.nextDouble(), b = scanner.nextDouble(), c = scanner.nextDouble();
            if (a == b && b == c) System.out.println("Equilateral");
            else if (a == b || b == c || a == c) System.out.println("Isosceles");
            else System.out.println("Scalene");
        }
    }
}