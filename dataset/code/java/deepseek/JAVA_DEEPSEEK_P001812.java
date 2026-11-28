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

    static void inOrder(Node node, int low, int high) {
        if (node == null) {
            return;
        }

        inOrder(node.left, low, high);

        if (node.key >= low && node.key <= high) {
            System.out.print(node.key + " ");
        }

        inOrder(node.right, low, high);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node root = null;

        for (int i = 0; i < n; i++) {
            root = insert(root, scanner.nextInt());
        }

        int low = scanner.nextInt();
        int high = scanner.nextInt();

        inOrder(root, low, high);
    }
}
