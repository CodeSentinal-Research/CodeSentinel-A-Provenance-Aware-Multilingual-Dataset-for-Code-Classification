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

    static Node splitBST(Node root, int x) {
        if (root == null)
            return null;

        if (root.data <= x) {
            Node right = splitBST(root.right, x);
            root.right = right;
            return root;
        } else {
            Node left = splitBST(root.left, x);
            root.left = left;
            return root;
        }
    }

    static void inOrder(Node node) {
        if (node != null) {
            inOrder(node.left);
            System.out.print(node.data + " ");
            inOrder(node.right);
        }
    }

    public static void main(String[] args) {
        root = new Node(50);
        root.left = new Node(30);
        root.right = new Node(70);
        root.left.left = new Node(20);
        root.left.right = new Node(40);
        root.right.left = new Node(60);
        root.right.right = new Node(80);

        int x = 50;

        Node root1 = splitBST(root, x);
        Node root2 = root;

        System.out.println("Tree 1 (Keys are less than or equal to " + x + ")");
        inOrder(root1);

        System.out.println("\nTree 2 (Keys are greater than " + x + ")");
        inOrder(root2);
    }
}
