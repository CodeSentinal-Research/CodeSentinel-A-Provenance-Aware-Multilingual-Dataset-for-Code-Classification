import java.util.*;

public class Solution {
    private Map<String, Integer> memo = new HashMap<>();

    public int minStickers(String[] stickers, String target) {
        int n = stickers.length;
        int[][] stickerCounts = new int[n][26];
        for (int i = 0; i < n; i++) {
            for (char c : stickers[i].toCharArray()) stickerCounts[i][c - 'a']++;
        }
        memo.put("", 0);
        return dfs(target, stickerCounts);
    }

    private int dfs(String target, int[][] stickerCounts) {
        if (memo.containsKey(target)) return memo.get(target);

        int[] tCount = new int[26];
        for (char c : target.toCharArray()) tCount[c - 'a']++;

        int res = Integer.MAX_VALUE;
        for (int[] sCount : stickerCounts) {
            if (sCount[target.charAt(0) - 'a'] == 0) continue;

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 26; i++) {
                if (tCount[i] > sCount[i]) {
                    for (int j = 0; j < tCount[i] - sCount[i]; j++) {
                        sb.append((char)('a' + i));
                    }
                }
            }
            int sub = dfs(sb.toString(), stickerCounts);
            if (sub != -1) res = Math.min(res, 1 + sub);
        }

        int ans = (res == Integer.MAX_VALUE) ? -1 : res;
        memo.put(target, ans);
        return ans;
    }
}