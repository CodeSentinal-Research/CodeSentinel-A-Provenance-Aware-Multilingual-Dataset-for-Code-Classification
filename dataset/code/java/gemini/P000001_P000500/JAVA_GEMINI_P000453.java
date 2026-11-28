import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int ans = -1;
            for (int i = 0; i < n; i++) {
                int v = scanner.nextInt();
                if (v == i && ans == -1) ans = i;
            }
            System.out.println(ans);
        }
    }
}