import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextDouble()) {
            double r = scanner.nextDouble();
            double pi = 3.14159;
            double area = pi * r * r;
            System.out.println(area);
        }
    }
}