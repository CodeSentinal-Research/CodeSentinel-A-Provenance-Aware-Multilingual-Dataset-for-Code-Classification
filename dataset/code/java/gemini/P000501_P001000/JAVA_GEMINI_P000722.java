import java.util.*;
public class Solution {
    static boolean backtrack(int[] matchsticks, int idx, int side, int[] sides) {
        if (idx == matchsticks.length) return true;
        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[idx] <= side) {
                sides[i] += matchsticks[idx];
                if (backtrack(matchsticks, idx + 1, side, sides)) return true;
                sides[i] -= matchsticks[idx];
            }
            if (sides[i] == 0) break;
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] matchsticks = new int[n];
            int total = 0;
            for (int i = 0; i < n; i++) {
                matchsticks[i] = scanner.nextInt();
                total += matchsticks[i];
            }
            if (total % 4 != 0 || n < 4) { System.out.println("false"); return; }
            int side = total / 4;
            Arrays.sort(matchsticks);
            for (int i = 0; i < n / 2; i++) {
                int t = matchsticks[i]; matchsticks[i] = matchsticks[n - 1 - i]; matchsticks[n - 1 - i] = t;
            }
            if (matchsticks[0] > side) { System.out.println("false"); return; }
            System.out.println(backtrack(matchsticks, 0, side, new int[4]) ? "true" : "false");
        }
    }
}