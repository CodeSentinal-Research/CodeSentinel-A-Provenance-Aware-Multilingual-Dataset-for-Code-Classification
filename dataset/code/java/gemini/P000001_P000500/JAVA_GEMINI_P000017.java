import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextDouble()) {
            double f = scanner.nextDouble();
            double c = (f - 32.0) * 5.0 / 9.0;
            System.out.println(c);
        }
    }
}