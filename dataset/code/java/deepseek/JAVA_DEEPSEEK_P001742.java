import java.util.*;

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

    void printLeafNodes(Node node) {
        if (node == null)
            return;

        if (node.left == null && node.right == null) {
            System.out.print(node.data + " ");
            return;
        }

        if (node.right != null)
            printLeafNodes(node.right);

        if (node.left != null)
            printLeafNodes(node.left);
    }

    public static void main(String[] args) {
        Main tree = new Main();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);
        tree.root.right.left = new Node(6);
        tree.root.right.right = new Node(7);

        tree.printLeafNodes(tree.root);
    }
}
