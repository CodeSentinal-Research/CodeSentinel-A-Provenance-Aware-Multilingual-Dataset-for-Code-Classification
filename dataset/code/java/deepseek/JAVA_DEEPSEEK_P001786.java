import java.util.Scanner;

public class Main {
    public static class Node {
        int data;
        Node left, right;

        Node(int item) {
            data = item;
            left = right = null;
        }
    }

    Node root;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Main tree = new Main();
        while (n-- > 0) {
            tree.root = tree.insert(tree.root, scanner.nextInt());
        }
        int key = scanner.nextInt();
        if (tree.search(tree.root, key)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    public Node insert(Node node, int data) {
        if (node == null) {
            return new Node(data);
        }
        if (data < node.data) {
            node.left = insert(node.left, data);
        } else if (data > node.data) {
            node.right = insert(node.right, data);
        }
        return node;
    }

    boolean search(Node root, int key) {
        if (root == null) {
            return false;
        }
        if (root.data == key) {
            return true;
        }
        if (root.data > key) {
            return search(root.left, key);
        }
        return search(root.right, key);
    }
}
