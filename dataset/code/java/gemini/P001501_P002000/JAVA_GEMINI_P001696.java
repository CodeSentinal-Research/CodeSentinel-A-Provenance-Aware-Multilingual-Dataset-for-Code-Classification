class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private String ans = "~";

    private void dfs(TreeNode node, StringBuilder sb) {
        if (node == null) return;
        sb.append((char)('a' + node.val));
        if (node.left == null && node.right == null) {
            String s = new StringBuilder(sb).reverse().toString();
            if (s.compareTo(ans) < 0) ans = s;
        }
        dfs(node.left, sb);
        dfs(node.right, sb);
        sb.deleteCharAt(sb.length() - 1);
    }

    public String smallestFromLeaf(TreeNode root) {
        ans = "~";
        dfs(root, new StringBuilder());
        return ans;
    }
}