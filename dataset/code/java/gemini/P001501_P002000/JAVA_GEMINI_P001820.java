class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

public class Solution {
    private int curRank = 0;
    private int ans = -1;

    private void inorder(TreeNode node, int rank) {
        if (node == null || ans != -1) return;
        inorder(node.left, rank);
        curRank++;
        if (curRank == rank) {
            ans = node.val;
            return;
        }
        inorder(node.right, rank);
    }

    public int keyWithRank(TreeNode root, int rank) {
        curRank = 0;
        ans = -1;
        inorder(root, rank);
        return ans;
    }
}