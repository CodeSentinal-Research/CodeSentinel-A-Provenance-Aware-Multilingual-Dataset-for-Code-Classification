import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            long n = scanner.nextLong();
            long total = n * (n + 1) / 2;
            System.out.println(total);
        }
    }
}