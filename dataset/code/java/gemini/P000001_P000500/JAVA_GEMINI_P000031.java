import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            StringBuilder sb = new StringBuilder();
            for (int i = 1; i <= n; i++) {
                if (n % i == 0) {
                    if (sb.length() > 0) sb.append(' ');
                    sb.append(i);
                }
            }
            System.out.println(sb.toString());
        }
    }
}