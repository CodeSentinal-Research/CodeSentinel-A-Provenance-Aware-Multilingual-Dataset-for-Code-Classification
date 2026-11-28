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

    static int max(int a, int b) {
        return (a >= b) ? a : b;
    }

    static int liss(Node node) {
        if (node == null)
            return 0;
        if (node.left == null && node.right == null)
            return node.data;

        int size_incl = node.data;
        if (node.left != null)
            size_incl += (liss(node.left.left) + liss(node.left.right));
        if (node.right != null)
            size_incl += (liss(node.right.left) + liss(node.right.right));

        int size_excl = liss(node.left) + liss(node.right);

        return max(size_incl, size_excl);
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        root.left.left.left = new Node(8);
        root.left.right.left = new Node(9);
        root.right.left.right = new Node(10);
        root.right.right.right = new Node(11);
        System.out.println("Size of the Largest Independent Set is " + liss(root));
    }
}
