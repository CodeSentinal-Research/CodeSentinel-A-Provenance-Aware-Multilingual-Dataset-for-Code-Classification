import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        TreeNode root = new TreeNode(scanner.nextInt());
        TreeNode[] nodes = new TreeNode[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = new TreeNode(scanner.nextInt());
            if (i > 0) {
                TreeNode parent = nodes[i - 1];
                if (parent.left == null) {
                    parent.left = nodes[i];
                } else {
                    parent.right = nodes[i];
                }
            }
        }
        int node1 = scanner.nextInt();
        int node2 = scanner.nextInt();
        TreeNode result = lowestCommonAncestor(root, new TreeNode(node1), new TreeNode(node2));
        System.out.println(result.value);
    }

    public static TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return null;
        }
        if (root.value == p.value || root.value == q.value) {
            return root;
        }
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        if (left != null && right != null) {
            return root;
        } else if (left != null) {
            return left;
        } else {
            return right;
        }
    }

    public static class TreeNode {
        int value;
        TreeNode left;
        TreeNode right;

        TreeNode(int value) {
            this.value = value;
        }
    }
}
