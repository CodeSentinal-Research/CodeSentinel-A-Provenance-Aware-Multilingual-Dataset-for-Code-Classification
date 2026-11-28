import java.util.Scanner;

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

    static int toSumTree(Node node) {
        if (node == null)
            return 0;

        int old_val = node.data;

        node.data = toSumTree(node.left) + toSumTree(node.right);

        return node.data + old_val;
    }

    static void printInorder(Node node) {
        if (node == null)
            return;

        printInorder(node.left);
        System.out.print(node.data + " ");
        printInorder(node.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nodes = new int[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = sc.nextInt();
        }

        root = new Node(nodes[0]);
        for (int i = 1; i < n; i++) {
            insert(root, nodes[i]);
        }

        toSumTree(root);
        printInorder(root);
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
}
