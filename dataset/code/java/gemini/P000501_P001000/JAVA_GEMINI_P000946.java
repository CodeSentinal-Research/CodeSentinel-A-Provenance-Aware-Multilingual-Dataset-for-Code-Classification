import java.util.HashMap;
import java.util.Map;

public class Solution {
    private Map<String, Boolean> memo = new HashMap<>();

    public boolean canWin(String currentState) {
        if (memo.containsKey(currentState)) return memo.get(currentState);
        for (int i = 0; i < currentState.length() - 1; i++) {
            if (currentState.charAt(i) == '+' && currentState.charAt(i + 1) == '+') {
                String nextState = currentState.substring(0, i) + "--" + currentState.substring(i + 2);
                if (!canWin(nextState)) {
                    memo.put(currentState, true);
                    return true;
                }
            }
        }
        memo.put(currentState, false);
        return false;
    }
}