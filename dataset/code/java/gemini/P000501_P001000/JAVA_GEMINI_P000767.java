import java.util.*;
public class Solution {
    static class TreeNode {
        int val; TreeNode left, right;
        TreeNode(int v, TreeNode l, TreeNode r) { val = v; left = l; right = r; }
    }
    static List<TreeNode> generateTrees(int start, int end) {
        List<TreeNode> res = new ArrayList<>();
        if (start > end) { res.add(null); return res; }
        for (int i = start; i <= end; i++) {
            List<TreeNode> leftTrees = generateTrees(start, i - 1);
            List<TreeNode> rightTrees = generateTrees(i + 1, end);
            for (TreeNode l : leftTrees) {
                for (TreeNode r : rightTrees) {
                    res.add(new TreeNode(i, l, r));
                }
            }
        }
        return res;
    }
    static String serialize(TreeNode root) {
        if (root == null) return "null";
        return root.val + "(" + serialize(root.left) + "," + serialize(root.right) + ")";
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            List<TreeNode> trees = generateTrees(1, scanner.nextInt());
            for (TreeNode t : trees) System.out.println(serialize(t));
        }
    }
}