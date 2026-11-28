import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            long a = scanner.nextLong(), b = scanner.nextLong();
            System.out.println(a % b == 0 ? "Divisible" : "Not Divisible");
        }
    }
}