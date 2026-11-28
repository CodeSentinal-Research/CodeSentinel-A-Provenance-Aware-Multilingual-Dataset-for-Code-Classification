import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private TreeNode build(int[] keys, int[][] rootIdx, int i, int j) {
        if (i > j) return null;
        int r = rootIdx[i][j];
        TreeNode node = new TreeNode(keys[r]);
        node.left = build(keys, rootIdx, i, r - 1);
        node.right = build(keys, rootIdx, r + 1, j);
        return node;
    }

    public TreeNode constructOBST(int[] keys, int[] freq) {
        int n = keys.length;
        int[][] cost = new int[n][n];
        int[][] rootIdx = new int[n][n];
        int[][] w = new int[n][n];

        for (int i = 0; i < n; i++) {
            w[i][i] = freq[i];
            cost[i][i] = freq[i];
            rootIdx[i][i] = i;
            for (int j = i + 1; j < n; j++) {
                w[i][j] = w[i][j - 1] + freq[j];
            }
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                cost[i][j] = Integer.MAX_VALUE;
                for (int r = i; r <= j; r++) {
                    int c = (r > i ? cost[i][r - 1] : 0) + (r < j ? cost[r + 1][j] : 0) + w[i][j];
                    if (c < cost[i][j]) {
                        cost[i][j] = c;
                        rootIdx[i][j] = r;
                    }
                }
            }
        }

        return build(keys, rootIdx, 0, n - 1);
    }
}