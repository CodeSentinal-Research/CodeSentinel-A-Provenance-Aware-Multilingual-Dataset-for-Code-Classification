import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int countPairs(int[] deliciousness) {
        long MOD = 1000000007;
        Map<Integer, Integer> map = new HashMap<>();
        long ans = 0;

        for (int x : deliciousness) {
            int power = 1;
            for (int i = 0; i <= 21; i++) {
                if (map.containsKey(power - x)) {
                    ans = (ans + map.get(power - x)) % MOD;
                }
                power <<= 1;
            }
            map.put(x, map.getOrDefault(x, 0) + 1);
        }
        return (int)ans;
    }
}