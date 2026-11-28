import java.util.*;

public class Main {
    static class Node {
        int data;
        Node left, right;

        Node(int item) {
            data = item;
            left = right = null;
        }
    }

    static Node insert(Node node, int data) {
        if (node == null) {
            return (new Node(data));
        } else {
            if (data <= node.data) {
                node.left = insert(node.left, data);
            } else {
                node.right = insert(node.right, data);
            }
            return node;
        }
    }

    static int rank(Node root, int key) {
        if (root == null)
            return -1;

        if (root.data == key)
            return size(root.left);

        if (root.data > key)
            return rank(root.left, key);

        int rightRank = rank(root.right, key);
        if (rightRank == -1)
            return -1;
        else
            return size(root.left) + 1 + rightRank;
    }

    static int size(Node node) {
        if (node == null)
            return 0;
        return size(node.left) + size(node.right) + 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node root = null;
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            root = insert(root, val);
        }
        int key = scanner.nextInt();
        System.out.println(rank(root, key));
    }
}
