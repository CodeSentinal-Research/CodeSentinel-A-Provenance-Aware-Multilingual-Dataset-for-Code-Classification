import java.util.Arrays;

public class Solution {
    private boolean backtrack(int[] matchsticks, int idx, int side, int[] sides) {
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

    public boolean makesquare(int[] matchsticks) {
        int total = 0;
        for (int m : matchsticks) total += m;
        if (total % 4 != 0) return false;
        int side = total / 4;

        Arrays.sort(matchsticks);
        int n = matchsticks.length;
        for (int i = 0; i < n / 2; i++) {
            int tmp = matchsticks[i];
            matchsticks[i] = matchsticks[n - 1 - i];
            matchsticks[n - 1 - i] = tmp;
        }

        if (matchsticks[0] > side) return false;
        return backtrack(matchsticks, 0, side, new int[4]);
    }
}