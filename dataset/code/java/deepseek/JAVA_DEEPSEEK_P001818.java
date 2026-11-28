import java.util.*;

public class Main {
    public static class Node {
        int value;
        Node left;
        Node right;

        Node(int value) {
            this.value = value;
            left = null;
            right = null;
        }
    }

    public static Node insert(Node root, int value) {
        if (root == null) {
            return new Node(value);
        }

        if (value < root.value) {
            root.left = insert(root.left, value);
        } else if (value > root.value) {
            root.right = insert(root.right, value);
        }

        return root;
    }

    public static Node LCA(Node root, int n1, int n2) {
        if (root == null) {
            return null;
        }

        if (root.value > n1 && root.value > n2) {
            return LCA(root.left, n1, n2);
        }

        if (root.value < n1 && root.value < n2) {
            return LCA(root.right, n1, n2);
        }

        return root;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node root = null;
        for (int i = 0; i < n; i++) {
            root = insert(root, scanner.nextInt());
        }

        int k = scanner.nextInt();
        int[] keys = new int[k];
        for (int i = 0; i < k; i++) {
            keys[i] = scanner.nextInt();
        }

        Arrays.sort(keys);
        Node lca = LCA(root, keys[0], keys[k - 1]);
        System.out.println(lca.value);
    }
}
