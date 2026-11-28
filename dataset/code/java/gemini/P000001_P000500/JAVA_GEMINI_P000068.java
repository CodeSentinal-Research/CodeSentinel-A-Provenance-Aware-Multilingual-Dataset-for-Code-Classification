import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextDouble()) {
            double s = scanner.nextDouble();
            System.out.println(4 * s);
        }
    }
}