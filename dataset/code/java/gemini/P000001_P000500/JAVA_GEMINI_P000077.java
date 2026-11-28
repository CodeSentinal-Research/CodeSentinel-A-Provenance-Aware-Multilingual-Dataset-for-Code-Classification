import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextDouble()) {
            double x1 = scanner.nextDouble(), y1 = scanner.nextDouble();
            double x2 = scanner.nextDouble(), y2 = scanner.nextDouble();
            double dist = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
            System.out.println(dist);
        }
    }
}