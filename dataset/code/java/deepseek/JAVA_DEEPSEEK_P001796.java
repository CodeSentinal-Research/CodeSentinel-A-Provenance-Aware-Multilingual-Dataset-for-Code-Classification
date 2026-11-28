import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] preorder = new int[n];
        for (int i = 0; i < n; i++) {
            preorder[i] = sc.nextInt();
        }
        TreeNode root = constructBST(preorder);
        inorderTraversal(root);
    }

    public static TreeNode constructBST(int[] preorder) {
        if (preorder.length == 0) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[0]);
        List<Integer> leftSubtree = new ArrayList<>();
        List<Integer> rightSubtree = new ArrayList<>();
        for (int i = 1; i < preorder.length; i++) {
            if (preorder[i] < preorder[0]) {
                leftSubtree.add(preorder[i]);
            } else {
                rightSubtree.add(preorder[i]);
            }
        }
        root.left = constructBST(leftSubtree.stream().mapToInt(i->i).toArray());
        root.right = constructBST(rightSubtree.stream().mapToInt(i->i).toArray());
        return root;
    }

    public static void inorderTraversal(TreeNode node) {
        if (node == null) {
            return;
        }
        inorderTraversal(node.left);
        System.out.print(node.val + " ");
        inorderTraversal(node.right);
    }

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }
}
