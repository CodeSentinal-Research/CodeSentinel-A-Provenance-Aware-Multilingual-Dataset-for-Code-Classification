import java.util.HashMap;
import java.util.Map;

public class Solution {
    private Map<Integer, Boolean> memo = new HashMap<>();

    private boolean helper(int maxChoosable, int desiredTotal, int mask, int currentTotal) {
        if (memo.containsKey(mask)) return memo.get(mask);
        for (int i = 1; i <= maxChoosable; i++) {
            if ((mask & (1 << i)) == 0) {
                if (currentTotal + i >= desiredTotal || !helper(maxChoosable, desiredTotal, mask | (1 << i), currentTotal + i)) {
                    memo.put(mask, true);
                    return true;
                }
            }
        }
        memo.put(mask, false);
        return false;
    }

    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;
        int total = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (total < desiredTotal) return false;
        return helper(maxChoosableInteger, desiredTotal, 0, 0);
    }
}