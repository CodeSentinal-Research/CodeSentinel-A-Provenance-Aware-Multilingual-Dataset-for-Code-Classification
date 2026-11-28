import java.io.*;
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

    static Node prune(Node root, HashSet<Node> nodesWithOne) {
        if (root == null) {
            return null;
        }

        root.left = prune(root.left, nodesWithOne);
        root.right = prune(root.right, nodesWithOne);

        if (root.data == 0 && !nodesWithOne.contains(root)) {
            return null;
        }

        if (root.data == 1) {
            nodesWithOne.add(root);
        }

        return root;
    }

    static void inOrder(Node root) {
        if (root != null) {
            inOrder(root.left);
            System.out.print(root.data + " ");
            inOrder(root.right);
        }
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(1);
        root.right = new Node(0);
        root.right.left = new Node(0);
        root.right.right = new Node(1);
        root.right.left.left = new Node(0);
        root.right.left.right = new Node(1);

        HashSet<Node> nodesWithOne = new HashSet<>();
        root = prune(root, nodesWithOne);
        inOrder(root);
    }
}
