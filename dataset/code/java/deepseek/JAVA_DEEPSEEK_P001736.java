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

    static void printBoundary(Node node) {
        if (node == null)
            return;

        System.out.print(node.data + " ");

        printBoundaryLeft(node.left);

        printBoundaryLeaf(node.left);
        printBoundaryLeaf(node.right);

        printBoundaryRight(node.right);
    }

    static void printBoundaryLeft(Node node) {
        if (node == null || (node.left == null && node.right == null))
            return;

        System.out.print(node.data + " ");
        if (node.left != null)
            printBoundaryLeft(node.left);
        else
            printBoundaryLeft(node.right);
    }

    static void printBoundaryRight(Node node) {
        if (node == null || (node.left == null && node.right == null))
            return;

        if (node.right != null)
            printBoundaryRight(node.right);
        else
            printBoundaryRight(node.left);

        System.out.print(node.data + " ");
    }

    static void printBoundaryLeaf(Node node) {
        if (node == null)
            return;

        printBoundaryLeaf(node.left);
        if (node.left == null && node.right == null)
            System.out.print(node.data + " ");
        printBoundaryLeaf(node.right);
    }

    public static void main(String[] args) {
        root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        printBoundary(root);
    }
}
