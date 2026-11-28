import java.util.*;

public class Main {
    static class Node {
        int val;
        Node left;
        Node right;
        Node(int val) {
            this.val = val;
            left = null;
            right = null;
        }
    }

    static int count = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = new Node(1);
        for (int i = 0; i < n; i++) {
            int val = sc.nextInt();
            int left = sc.nextInt();
            int right = sc.nextInt();
            insert(root, val, left, right);
        }
        isSymmetric(root);
        System.out.println(count);
    }

    public static void insert(Node root, int val, int left, int right) {
        if (root == null) {
            return;
        }
        if (root.val == val) {
            root.left = new Node(left);
            root.right = new Node(right);
        } else {
            insert(root.left, val, left, right);
            insert(root.right, val, left, right);
        }
    }

    public static boolean isSymmetric(Node root) {
        if (root == null) {
            return true;
        }
        return isMirror(root.left, root.right);
    }

    public static boolean isMirror(Node left, Node right) {
        if (left == null && right == null) {
            return true;
        }
        if (left == null || right == null) {
            return false;
        }
        if (left.val != right.val) {
            return false;
        }
        if (!isMirror(left.left, right.right)) {
            return false;
        }
        if (!isMirror(left.right, right.left)) {
            return false;
        }
        count++;
        return true;
    }
}
