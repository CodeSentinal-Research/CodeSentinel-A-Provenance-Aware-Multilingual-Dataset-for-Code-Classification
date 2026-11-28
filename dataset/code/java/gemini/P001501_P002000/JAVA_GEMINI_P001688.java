import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private List<Long> allSums = new ArrayList<>();

    private long treeSum(TreeNode node) {
        if (node == null) return 0;
        long cur = node.val + treeSum(node.left) + treeSum(node.right);
        allSums.add(cur);
        return cur;
    }

    public int maxProduct(TreeNode root) {
        allSums.clear();
        long total = treeSum(root);
        long maxProd = 0;
        long mod = 1000000007L;

        for (long s : allSums) {
            maxProd = Math.max(maxProd, s * (total - s));
        }
        return (int)(maxProd % mod);
    }
}