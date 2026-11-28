import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private TreeNode insert(TreeNode node, int val) {
        if (node == null) return new TreeNode(val);
        if (val < node.val) node.left = insert(node.left, val);
        else node.right = insert(node.right, val);
        return node;
    }

    public TreeNode bstFromAncestorMatrix(int[][] matrix) {
        int n = matrix.length;
        if (n == 0) return null;

        int[][] desc = new int[n][2];
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) sum += matrix[i][j];
            desc[i][0] = sum;
            desc[i][1] = i;
        }

        Arrays.sort(desc, (a, b) -> b[0] - a[0]);

        TreeNode root = new TreeNode(desc[0][1]);
        for (int i = 1; i < n; i++) {
            insert(root, desc[i][1]);
        }
        return root;
    }
}