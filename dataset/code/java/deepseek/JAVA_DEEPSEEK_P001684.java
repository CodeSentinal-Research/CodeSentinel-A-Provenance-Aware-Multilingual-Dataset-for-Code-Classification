import java.util.*;

public class Main {
    static class Node {
        int value;
        Node left;
        Node right;

        Node(int value) {
            this.value = value;
            left = null;
            right = null;
        }
    }

    static Node root;

    static void insert(int value, Node node) {
        if (value < node.value) {
            if (node.left != null) {
                insert(value, node.left);
            } else {
                node.left = new Node(value);
            }
        } else if (value > node.value) {
            if (node.right != null) {
                insert(value, node.right);
            } else {
                node.right = new Node(value);
            }
        }
    }

    static boolean isSibling(Node node, int x, int y) {
        if (node == null) {
            return false;
        }

        if (node.left != null && node.right != null) {
            if (node.left.value == x && node.right.value == y || node.left.value == y && node.right.value == x) {
                return true;
            }
        }

        return isSibling(node.left, x, y) || isSibling(node.right, x, y);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        root = new Node(scanner.nextInt());

        for (int i = 1; i < n; i++) {
            insert(scanner.nextInt(), root);
        }

        int x = scanner.nextInt();
        int y = scanner.nextInt();

        if (isSibling(root, x, y)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
