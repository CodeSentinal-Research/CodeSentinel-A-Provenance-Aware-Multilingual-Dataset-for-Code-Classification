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

    static Node root;

    static void insert(int data) {
        if (root == null) {
            root = new Node(data);
            return;
        }

        Node current = root;
        Node newNode = new Node(data);

        while (true) {
            if (data < current.data) {
                if (current.left == null) {
                    current.left = newNode;
                    break;
                }
                current = current.left;
            } else {
                if (current.right == null) {
                    current.right = newNode;
                    break;
                }
                current = current.right;
            }
        }
    }

    static int minPathSum(Node root) {
        if (root == null) {
            return Integer.MAX_VALUE;
        }
        if (root.left == null && root.right == null) {
            return root.data;
        }
        return root.data + Math.min(minPathSum(root.left), minPathSum(root.right));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            insert(scanner.nextInt());
        }
        System.out.println(minPathSum(root));
    }
}
