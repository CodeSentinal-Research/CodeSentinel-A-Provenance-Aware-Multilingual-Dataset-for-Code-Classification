import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node root = null;
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            root = insert(root, val);
        }
        int k = scanner.nextInt();
        System.out.println(kthLargest(root, k).val);
    }

    static Node insert(Node root, int val) {
        if (root == null) {
            return new Node(val);
        }
        if (val < root.val) {
            root.left = insert(root.left, val);
        } else if (val > root.val) {
            root.right = insert(root.right, val);
        }
        return root;
    }

    static Node kthLargest(Node root, int k) {
        int[] count = new int[1];
        return kthLargestHelper(root, k, count);
    }

    static Node kthLargestHelper(Node root, int k, int[] count) {
        if (root == null) {
            return null;
        }
        Node right = kthLargestHelper(root.right, k, count);
        if (right != null) {
            return right;
        }
        count[0]++;
        if (count[0] == k) {
            return root;
        }
        return kthLargestHelper(root.left, k, count);
    }

    static class Node {
        int val;
        Node left;
        Node right;

        Node(int val) {
            this.val = val;
        }
    }
}
