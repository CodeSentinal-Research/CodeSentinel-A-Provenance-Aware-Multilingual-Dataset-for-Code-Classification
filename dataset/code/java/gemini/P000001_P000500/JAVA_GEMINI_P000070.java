import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextDouble()) {
            double a = scanner.nextDouble(), b = scanner.nextDouble(), c = scanner.nextDouble();
            boolean valid = (a + b > c) && (a + c > b) && (b + c > a);
            System.out.println(valid ? "Valid" : "Invalid");
        }
    }
}