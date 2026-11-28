import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            StringBuilder sb = new StringBuilder();
            for (int i = n; i >= 1; i--) {
                if (i < n) sb.append(' ');
                sb.append(i);
            }
            System.out.println(sb.toString());
        }
    }
}