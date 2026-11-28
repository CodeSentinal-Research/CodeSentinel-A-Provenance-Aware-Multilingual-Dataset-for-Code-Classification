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
            return new Node(data);
        } else {
            if (data <= node.data) {
                node.left = insert(node.left, data);
            } else {
                node.right = insert(node.right, data);
            }
            return node;
        }
    }

    static int minValue(Node root) {
        Node current = root;
        while (current.left != null) {
            current = current.left;
        }
        return current.data;
    }

    static int findSmallestGreaterKey(Node root, int x) {
        if (root == null) {
            return -1;
        }
        if (root.data > x) {
            int left = findSmallestGreaterKey(root.left, x);
            if (left != -1) {
                return left;
            } else {
                return root.data;
            }
        } else {
            return findSmallestGreaterKey(root.right, x);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Node root = null;
        for (int i = 0; i < n; i++) {
            int val = scanner.nextInt();
            root = insert(root, val);
        }
        int x = scanner.nextInt();
        int res = findSmallestGreaterKey(root, x);
        if (res == -1) {
            System.out.println("NONE");
        } else {
            System.out.println(res);
        }
    }
}
