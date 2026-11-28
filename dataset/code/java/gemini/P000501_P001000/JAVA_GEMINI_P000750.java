import java.util.*;
public class Solution {
    static void dfs(int cur, int n) {
        if (cur > n) return;
        System.out.println(cur);
        for (int i = 0; i < 10; i++) {
            if (cur * 10 + i <= n) dfs(cur * 10 + i, n);
            else break;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            for (int i = 1; i <= 9 && i <= n; i++) dfs(i, n);
        }
    }
}