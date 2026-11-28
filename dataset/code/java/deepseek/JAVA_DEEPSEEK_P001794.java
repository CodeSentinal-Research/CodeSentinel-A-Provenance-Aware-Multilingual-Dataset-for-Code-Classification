import java.util.Scanner;

public class Main {
    static class Node {
        int key;
        Node left, right;

        Node(int key) {
            this.key = key;
            left = right = null;
        }
    }

    static Node insert(Node node, int key) {
        if (node == null) {
            return new Node(key);
        }

        if (key < node.key) {
            node.left = insert(node.left, key);
        } else if (key > node.key) {
            node.right = insert(node.right, key);
        }

        return node;
    }

    static Node LCA(Node node, int n1, int n2) {
        if (node == null) {
            return null;
        }

        if (node.key > n1 && node.key > n2) {
            return LCA(node.left, n1, n2);
        }

        if (node.key < n1 && node.key < n2) {
            return LCA(node.right, n1, n2);
        }

        return node;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node root = null;
        for (int i = 0; i < n; i++) {
            int key = scanner.nextInt();
            root = insert(root, key);
        }
        int n1 = scanner.nextInt();
        int n2 = scanner.nextInt();
        Node lca = LCA(root, n1, n2);
        if (lca != null) {
            System.out.println(lca.key);
        }
    }
}
