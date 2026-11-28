import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextDouble()) {
            double b = scanner.nextDouble(), h = scanner.nextDouble();
            System.out.println(0.5 * b * h);
        }
    }
}