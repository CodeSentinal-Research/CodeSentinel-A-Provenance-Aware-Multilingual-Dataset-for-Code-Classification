import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextDouble()) {
            double l = scanner.nextDouble();
            double b = scanner.nextDouble();
            System.out.println(l * b);
        }
    }
}