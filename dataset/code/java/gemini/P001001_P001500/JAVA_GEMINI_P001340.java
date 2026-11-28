import java.util.Arrays;

public class Solution {
    private int ans = Integer.MAX_VALUE;

    private void backtrack(int[] cookies, int idx, int[] children, int k) {
        if (idx == cookies.length) {
            int maxCookie = 0;
            for (int c : children) maxCookie = Math.max(maxCookie, c);
            ans = Math.min(ans, maxCookie);
            return;
        }

        int maxChild = 0;
        for (int c : children) maxChild = Math.max(maxChild, c);
        if (maxChild >= ans) return;

        for (int i = 0; i < k; i++) {
            children[i] += cookies[idx];
            backtrack(cookies, idx + 1, children, k);
            children[i] -= cookies[idx];
            if (children[i] == 0) break;
        }
    }

    public int distributeCookies(int[] cookies, int k) {
        Arrays.sort(cookies);
        int n = cookies.length;
        for (int i = 0; i < n / 2; i++) {
            int tmp = cookies[i];
            cookies[i] = cookies[n - 1 - i];
            cookies[n - 1 - i] = tmp;
        }
        backtrack(cookies, 0, new int[k], k);
        return ans;
    }
}