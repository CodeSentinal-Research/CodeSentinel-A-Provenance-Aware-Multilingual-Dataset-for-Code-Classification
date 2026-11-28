import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int count = 0;
            for (int i = 1; i <= n; i++) if (n % i == 0) count++;
            System.out.println(count);
        }
    }
}