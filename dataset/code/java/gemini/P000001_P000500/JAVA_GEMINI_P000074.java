import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextDouble()) {
            double r = scanner.nextDouble();
            System.out.println((4.0 / 3.0) * 3.14159 * r * r * r);
        }
    }
}