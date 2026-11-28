public class Solution {
    private boolean backtrack(int idx, int n, int[] res, boolean[] used) {
        while (idx < res.length && res[idx] != 0) idx++;
        if (idx == res.length) return true;

        for (int num = n; num >= 1; num--) {
            if (used[num]) continue;
            if (num == 1) {
                res[idx] = 1;
                used[1] = true;
                if (backtrack(idx + 1, n, res, used)) return true;
                res[idx] = 0;
                used[1] = false;
            } else if (idx + num < res.length && res[idx + num] == 0) {
                res[idx] = num;
                res[idx + num] = num;
                used[num] = true;
                if (backtrack(idx + 1, n, res, used)) return true;
                res[idx] = 0;
                res[idx + num] = 0;
                used[num] = false;
            }
        }
        return false;
    }

    public int[] constructDistancedSequence(int n) {
        int[] res = new int[2 * n - 1];
        backtrack(0, n, res, new boolean[n + 1]);
        return res;
    }
}