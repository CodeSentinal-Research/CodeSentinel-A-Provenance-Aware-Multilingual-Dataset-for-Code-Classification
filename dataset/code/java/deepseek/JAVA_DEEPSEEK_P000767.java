import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        int n = 8;
        List<TreeNode> trees = generateTrees(n);
        for (TreeNode tree : trees) {
            System.out.println(tree.val);
        }
    }

    public static List<TreeNode> generateTrees(int n) {
        return generateSubTrees(1, n);
    }

    private static List<TreeNode> generateSubTrees(int start, int end) {
        List<TreeNode> result = new ArrayList<>();
        if (start > end) {
            result.add(null);
            return result;
       }
       
        for (int i = start; i <= end; i++) {
            List<TreeNode> leftSubTrees = generateSubTrees(start, i - 1);
            List<TreeNode> rightSubTrees = generateSubTrees(i + 1, end);
            for (TreeNode left : leftSubTrees) {
                for (TreeNode right : rightSubTrees) {
                    TreeNode root = new TreeNode(i);
                    root.left = left;
                    root.right = right;
                    result.add(root);
                }
            }
        }
        return result;
    }

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }
}
