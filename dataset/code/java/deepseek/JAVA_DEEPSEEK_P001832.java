import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<TreeNode> trees = generateTrees(n);
        for (TreeNode tree : trees) {
            printTree(tree);
            System.out.println();
        }
    }

    public static List<TreeNode> generateTrees(int n) {
        List<TreeNode>[] result = new List[n + 1];
        result[0] = new ArrayList<TreeNode>();
        if (n == 0) {
            return result[0];
        }

        result[0].add(null);
        for (int len = 1; len <= n; len++) {
            result[len] = new ArrayList<>();
            for (int j = 0; j < len; j++) {
                int left = j;
                int right = len - j - 1;
                for (TreeNode nodeL : result[left]) {
                    for (TreeNode nodeR : result[right]) {
                        TreeNode node = new TreeNode(j + 1);
                        node.left = nodeL;
                        node.right = clone(nodeR, j + 1);
                        result[len].add(node);
                    }
                }
            }
        }
        return result[n];
    }

    private static TreeNode clone(TreeNode node, int shift) {
        if (node == null) {
            return null;
        }
        TreeNode newNode = new TreeNode(node.val + shift);
        newNode.left = clone(node.left, shift);
        newNode.right = clone(node.right, shift);
        return newNode;
    }

    private static void printTree(TreeNode root) {
        if (root == null) {
            return;
        }
        printTree(root.left);
        System.out.print(root.val + " ");
        printTree(root.right);
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
