import java.util.Scanner;
public class Solution {
    private static int fact(int n) {
        int f = 1;
        for (int i = 2; i <= n; i++) f *= i;
        return f;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int temp = n, sum = 0;
            while (temp > 0) { sum += fact(temp % 10); temp /= 10; }
            System.out.println(sum == n ? "Strong" : "Not Strong");
        }
    }
}