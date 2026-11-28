import java.util.*;

public class Main {
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public TreeNode balanceBST(TreeNode root) {
        List<Integer> values = new ArrayList<>();
        inorder(root, values);
        return buildTree(values, 0, values.size() - 1);
    }

    private static void inorder(TreeNode node, List<Integer> values) {
        if (node == null) {
            return;
        }
        inorder(node.left, values);
        values.add(node.val);
        inorder(node.right, values);
   }

    private static TreeNode buildTree(List<Integer> values, int start, int end) {
        if (start > end) {
            return null;
        }
        int mid = (start + end) / 2;
        TreeNode root = new TreeNode(values.get(mid));
        root.left = buildTree(values, start, mid - 1);
        root.right = buildTree(values, mid + 1, end);
        return root;
    }
}
