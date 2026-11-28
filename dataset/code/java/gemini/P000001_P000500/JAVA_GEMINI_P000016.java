import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextDouble()) {
            double c = scanner.nextDouble();
            double f = (c * 9.0 / 5.0) + 32.0;
            System.out.println(f);
        }
    }
}