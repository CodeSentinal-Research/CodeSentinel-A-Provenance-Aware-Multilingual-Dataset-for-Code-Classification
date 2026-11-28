class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private static final int MOD = 1_000_000_007;

    private long[][] comb = new long[1005][1005];

    private void precomputeComb() {
        for (int i = 0; i <= 1000; i++) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
    }

    private long[] dfs(TreeNode node) {
        if (node == null) return new long[]{1, 0};
        long[] l = dfs(node.left);
        long[] r = dfs(node.right);

        int totalChildren = (int)(l[1] + r[1]);
        long c = comb[totalChildren][(int)l[1]];
        long ways = (((l[0] * r[0]) % MOD) * c) % MOD;
        return new long[]{ways, totalChildren + 1};
    }

    public int countValidInsertionSeqs(TreeNode root) {
        precomputeComb();
        return (int)dfs(root)[0];
    }
}