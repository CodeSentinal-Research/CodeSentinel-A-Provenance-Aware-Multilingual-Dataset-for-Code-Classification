import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextDouble()) {
            double scored = scanner.nextDouble(), total = scanner.nextDouble();
            System.out.println((scored / total) * 100.0);
        }
    }
}