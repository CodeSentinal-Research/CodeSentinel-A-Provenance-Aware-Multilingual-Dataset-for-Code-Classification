import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            if (n <= 1) {
                System.out.println("Not Perfect");
                return;
            }
            int sum = 0;
            for (int i = 1; i < n; i++) if (n % i == 0) sum += i;
            System.out.println(sum == n ? "Perfect" : "Not Perfect");
        }
    }
}