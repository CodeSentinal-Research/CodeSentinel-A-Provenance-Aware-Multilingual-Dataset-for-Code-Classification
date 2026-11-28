import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextDouble()) {
            double p = scanner.nextDouble();
            double r = scanner.nextDouble();
            double t = scanner.nextDouble();
            double si = (p * r * t) / 100.0;
            System.out.println(si);
        }
    }
}