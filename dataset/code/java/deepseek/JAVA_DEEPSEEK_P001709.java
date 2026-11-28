import java.util.Scanner;

public class Main {
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public static TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) return null;
        if (t1 == null) return t2;
        if (t2 == null) return t1;

        TreeNode node = new TreeNode(t1.val + t2.val);
        node.left = mergeTrees(t1.left, t2.left);
        node.right = mergeTrees(t1.right, t2.right);
        return node;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n1 = scanner.nextInt();
        TreeNode[] t1 = new TreeNode[n1+1];
        for (int i = 1; i <= n1; i++) {
            int val = scanner.nextInt();
            t1[i] = new TreeNode(val);
            if (2*i <= n1) t1[i].left = t1[2*i];
            if (2*i+1 <= n1) t1[i].right = t1[2*i+1];
        }

        int n2 = scanner.nextInt();
        TreeNode[] t2 = new TreeNode[n2+1];
        for (int i = 1; i <= n2; i++) {
            int val = scanner.nextInt();
            t2[i] = new TreeNode(val);
            if (2*i <= n2) t2[i].left = t2[2*i];
            if (2*i+1 <= n2) t2[i].right = t2[2*i+1];
        }

        TreeNode mergedTree = mergeTrees(t1[1], t2[1]);

        // Print the merged tree
        // This is a simple in-order traversal to print the merged tree
        inOrderTraversal(mergedTree);
    }

    public static void inOrderTraversal(TreeNode node) {
        if (node == null) return;
        inOrderTraversal(node.left);
        System.out.println(node.val);
        inOrderTraversal(node.right);
    }
}
