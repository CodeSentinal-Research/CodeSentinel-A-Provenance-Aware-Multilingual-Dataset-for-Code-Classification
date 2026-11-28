import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextDouble()) {
            double p = scanner.nextDouble();
            double r = scanner.nextDouble();
            double t = scanner.nextDouble();
            double a = p * Math.pow(1.0 + r / 100.0, t);
            double ci = a - p;
            System.out.println(ci);
        }
    }
}