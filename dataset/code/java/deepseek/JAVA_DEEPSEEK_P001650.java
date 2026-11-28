import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] inorder = new int[N];
        for (int i = 0; i < N; i++) {
            inorder[i] = scanner.nextInt();
        }
        int[] postorder = new int[N];
        for (int i = 0; i < N; i++) {
            postorder[i] = scanner.nextInt();
        }
        TreeNode root = buildTree(inorder, postorder, 0, N - 1, 0);
        printInorder(root);
    }

    private static TreeNode buildTree(int[] inorder, int[] postorder, int inStart, int inEnd, int postStart) {
        if (inStart > inEnd) {
            return null;
        }
        TreeNode node = new TreeNode(postorder[postStart]);
        int index = -1;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == postorder[postStart]) {
                index = i;
                break;
            }
        }
        postStart++;
        node.left = buildTree(inorder, postorder, inStart, index - 1, postStart);
        node.right = buildTree(inorder, postorder, index + 1, inEnd, postStart);
        return node;
    }

    private static void printInorder(TreeNode node) {
        if (node == null) {
            return;
        }
        printInorder(node.left);
        System.out.print(node.val + " ");
        printInorder(node.right);
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
