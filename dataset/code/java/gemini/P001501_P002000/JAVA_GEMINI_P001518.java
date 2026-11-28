import java.util.Arrays;

public class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        Arrays.sort(potions);
        int n = spells.length, m = potions.length;
        int[] res = new int[n];

        for (int i = 0; i < n; i++) {
            long minPotion = (success + spells[i] - 1) / spells[i];
            int l = 0, r = m;
            while (l < r) {
                // Calculate midpoint to prevent potential overflow
                int mid = (l + r) / 2;
                if (potions[mid] >= minPotion) r = mid;
                else l = mid + 1;
            }
            res[i] = m - l;
        }
        return res;
    }
}