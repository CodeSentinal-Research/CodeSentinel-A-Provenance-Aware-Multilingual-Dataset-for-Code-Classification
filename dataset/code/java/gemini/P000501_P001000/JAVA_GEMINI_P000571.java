import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt(), k = scanner.nextInt();
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                ans = (ans + k) % i;
            }
            System.out.println(ans + 1);
        }
    }
}