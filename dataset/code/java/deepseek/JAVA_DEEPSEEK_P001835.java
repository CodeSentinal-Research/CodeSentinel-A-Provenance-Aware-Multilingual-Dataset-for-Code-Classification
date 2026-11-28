import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
        }
    }

    static int maxSize = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node root = null;
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            root = insert(root, val);
        }
        largestDeadEndFreeSubtree(root);
        System.out.println(maxSize);
    }

    static Node insert(Node node, int val) {
        if (node == null) {
            return new Node(val);
        }
        if (val < node.val) {
            node.left = insert(node.left, val);
        } else if (val > node.val) {
            node.right = insert(node.right, val);
        }
        return node;
    }

    static int largestDeadEndFreeSubtree(Node node) {
        if (node == null) {
            return 0;
        }
        int left = largestDeadEndFreeSubtree(node.left);
        int right = largestDeadEndFreeSubtree(node.right);
        if (left == 0 && right == 0) {
            maxSize = Math.max(maxSize, 1);
        } else if (left != 0 && right != 0) {
            maxSize = Math.max(maxSize, left + right + 1);
        }
        return Math.max(left, right) + 1;
    }
}
