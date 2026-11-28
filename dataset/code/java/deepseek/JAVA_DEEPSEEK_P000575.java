import java.util.*;

public class Main {
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        Queue<TreeNode> queue = new LinkedList<>();
        LinkedList<TreeNode> level = new LinkedList<>();
        queue.offer(root);
        level.add(root);
        int maxWidth = 0;
        while (!level.isEmpty()) {
            maxWidth = Math.max(maxWidth, level.getLast().val - level.getFirst().val + 1);
            TreeNode node = queue.poll();
            if (node.left != null) {
                node.left.val = 2 * node.val + 1;
                queue.offer(node.left);
                level.add(node.left);
            }
            if (node.right != null) {
                node.right.val = 2 * node.val + 2;
                queue.offer(node.right);
                level.add(node.right);
            }
            level.removeFirst();
        }
        return maxWidth;
    }
}
