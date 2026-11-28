import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans = (ans << 1) | scanner.nextInt();
            }
            System.out.println(ans);
        }
    }
}