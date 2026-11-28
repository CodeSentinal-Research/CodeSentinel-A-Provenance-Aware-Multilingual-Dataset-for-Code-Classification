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

    static Node insert(Node node, int data) {
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

    static boolean isLeaf(Node node) {
        return node.left == null && node.right == null;
    }

    static int countDeadEnds(Node root, int min, int max) {
        if (root == null) {
            return 0;
        }

        if (isLeaf(root)) {
            return (max - min <= 1) ? 1 : 0;
        }

        return countDeadEnds(root.left, min, root.data - 1) + countDeadEnds(root.right, root.data + 1, max);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = null;
        while (n-- > 0) {
            root = insert(root, sc.nextInt());
        }
        System.out.println(countDeadEnds(root, 1, Integer.MAX_VALUE));
    }
}
