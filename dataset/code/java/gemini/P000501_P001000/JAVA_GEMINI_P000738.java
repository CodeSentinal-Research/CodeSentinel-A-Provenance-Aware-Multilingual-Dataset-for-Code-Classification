import java.util.*;
public class Solution {
    static int backtrack(int pos, int n, boolean[] used) {
        if (pos > n) return 1;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (!used[i] && (i % pos == 0 || pos % i == 0)) {
                used[i] = true;
                count += backtrack(pos + 1, n, used);
                used[i] = false;
            }
        }
        return count;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            System.out.println(backtrack(1, n, new boolean[n + 1]));
        }
    }
}