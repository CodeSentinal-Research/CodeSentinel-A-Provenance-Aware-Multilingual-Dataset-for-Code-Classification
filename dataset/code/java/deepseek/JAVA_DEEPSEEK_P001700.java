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

    static void reverseAlternate(Node node, int level, boolean isLeft) {
        if (node == null)
            return;

        if (isLeft && level % 2 == 0) {
            int temp = node.left.data;
            node.left.data = node.right.data;
            node.right.data = temp;
        }

        reverseAlternate(node.left, level + 1, true);
        reverseAlternate(node.right, level + 1, false);
    }

    static void printTree(Node node) {
        if (node == null)
            return;

        printTree(node.left);
        System.out.print(node.data + " ");
        printTree(node.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = sc.nextInt();
        }

        root = new Node(values[0]);
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);

        for (int i = 1; i < n; i += 2) {
            Node parent = queue.poll();
            Node left = new Node(values[i]);
            Node right = new Node(values[i + 1]);
            parent.left = left;
            parent.right = right;
            queue.add(left);
            queue.add(right);
        }

        reverseAlternate(root, 0, true);
        printTree(root);
    }
}
